import os
import csv
import pandas as pd
import numpy as np
from tabulate import tabulate

def load_data(directory='Results'):
    runtimes = ["Native", "Wasmtime", "Wasmer", "Wasmedge"]
    benchmarks = [
        "averageVector", "normalizeVector", "vectorDotProduct", "vectorAddition",
        "multiplyMatrices", "transposeMatrix", "mandelbrot"
    ]
    vector_sizes = [16, 256, 4096, 65536, 262144]
    matrix_sizes = [4, 16, 64, 256, 512]
    mandelbrot_sizes = [16, 64, 256, 1024, 4096]

    data = []

    for runtime in runtimes:
        for benchmark in benchmarks:
            if benchmark == "mandelbrot":
                sizes = mandelbrot_sizes
                data_types = ['']  # No suffix for mandelbrot
            elif "Matrix" in benchmark or "Matrices" in benchmark:
                sizes = matrix_sizes
                data_types = ['float', 'int']
            else:
                sizes = vector_sizes
                data_types = ['float', 'int']

            for size in sizes:
                for data_type in data_types:
                    suffix = f"_{data_type}" if data_type else ""
                    file_path = os.path.join(directory, runtime, f"{benchmark}{suffix}_{size}.csv")
                    if os.path.exists(file_path):
                        with open(file_path, 'r') as f:
                            reader = csv.reader(f)
                            measurements = [float(x) for x in next(reader)[1:]]  # Skip the first measurement
                        mean_performance = np.mean(measurements)
                        std_performance = np.std(measurements)
                        data.append({
                            'Runtime': runtime,
                            'Benchmark': f"{benchmark}{suffix}",
                            'Size': size,
                            'Mean Performance': mean_performance,
                            'Std Performance': std_performance
                        })

    return pd.DataFrame(data)

def calculate_scaling_factors(df):
    results = []

    for benchmark in df['Benchmark'].unique():
        for runtime in df['Runtime'].unique():
            benchmark_data = df[(df['Benchmark'] == benchmark) & (df['Runtime'] == runtime)].sort_values('Size')
            if len(benchmark_data) > 1:
                base_size = benchmark_data['Size'].iloc[0]
                base_performance = benchmark_data['Mean Performance'].iloc[0]

                for _, row in benchmark_data.iterrows():
                    size = row['Size']
                    performance = row['Mean Performance']
                    # size_factor = size / base_size
                    if "Matrix" in benchmark or "Matrices" in benchmark:
                        size_factor = (size / base_size) ** 2  # Quadratic scaling for matrices
                    else:
                        size_factor = size / base_size  # Linear scaling for other operations

                    performance_factor = performance / base_performance

                    # Calculate scaling factor
                    # We use the nth root, where n is the number of size increases
                    n = np.log(size / base_size) / np.log(2)  # Assuming sizes increase by powers of 2
                    scaling_factor = (performance_factor / size_factor) ** (1/n)

                    # scaling_factor = performance_factor / size_factor

                    results.append({
                        'Benchmark': benchmark,
                        'Runtime': runtime,
                        'Size': size,
                        'Scaling Factor': scaling_factor
                    })

    return pd.DataFrame(results)

def format_table(df):
    df['Scaling Factor'] = df['Scaling Factor'].apply(lambda x: f"{x:.2f}")
    return df

def main():
    # Load the data
    df = load_data()

    # Calculate scaling factors
    scaling_factors = calculate_scaling_factors(df)

    # Format the table
    formatted_table = format_table(scaling_factors)

    # Pivot the table for better readability
    pivot_table = formatted_table.pivot_table(
        values='Scaling Factor',
        index=['Benchmark', 'Size'],
        columns='Runtime',
        aggfunc='first'
    ).reset_index()

    # Sort the table
    sorted_table = pivot_table.sort_values(['Benchmark', 'Size'])

    # Generate LaTeX table
    latex_table = tabulate(sorted_table, headers='keys', tablefmt='latex_booktabs', floatfmt='.4f')

    # Save to .tex file
    with open('analysis/tables/simd_scaling_comparison_table.tex', 'w') as f:
        f.write(latex_table)

    print("SIMD scaling comparison table has been generated and saved to 'simd_scaling_comparison_table.tex'")

if __name__ == "__main__":
    main()