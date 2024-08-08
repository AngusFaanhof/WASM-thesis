import os
import csv
import pandas as pd
import numpy as np

def load_data(directory='Results'):
    runtimes = ["Native", "Wasmtime", "Wasmer", "Wasmedge"]
    benchmarks = [
        "averageVector", "normalizeVector", "vectorDotProduct", "vectorAddition",
        "multiplyMatrices", "transposeMatrix"
    ]
    vector_sizes = [16, 256, 4096, 65536, 262144]
    matrix_sizes = [4, 16, 64, 256, 512]

    data = []

    for runtime in runtimes:
        for benchmark in benchmarks:
            sizes = vector_sizes if "Vector" in benchmark or "vector" in benchmark else matrix_sizes
            for size in sizes:
                for data_type in ['float', 'int']:
                    file_path = os.path.join(directory, runtime, f"{benchmark}_{data_type}_{size}.csv")
                    if os.path.exists(file_path):
                        with open(file_path, 'r') as f:
                            reader = csv.reader(f)
                            measurements = [float(x) for x in next(reader)[1:]]  # Skip the first measurement
                        mean_performance = np.mean(measurements)
                        std_performance = np.std(measurements)
                        data.append({
                            'Runtime': runtime,
                            'Benchmark': benchmark,
                            'Size': size,
                            'Data Type': data_type,
                            'Mean Performance': mean_performance,
                            'Std Performance': std_performance
                        })

    return pd.DataFrame(data)

def calculate_relative_performance(df):
    results = []

    for benchmark in df['Benchmark'].unique():
        for size in df['Size'].unique():
            native_float = df[(df['Runtime'] == 'Native') & (df['Benchmark'] == benchmark) &
                              (df['Size'] == size) & (df['Data Type'] == 'float')]['Mean Performance'].values
            native_int = df[(df['Runtime'] == 'Native') & (df['Benchmark'] == benchmark) &
                            (df['Size'] == size) & (df['Data Type'] == 'int')]['Mean Performance'].values

            if len(native_float) == 0 or len(native_int) == 0:
                continue  # Skip if we don't have Native performance data

            native_float = native_float[0]
            native_int = native_int[0]

            for runtime in df['Runtime'].unique():
                if runtime != 'Native':
                    runtime_float = df[(df['Runtime'] == runtime) & (df['Benchmark'] == benchmark) &
                                       (df['Size'] == size) & (df['Data Type'] == 'float')]['Mean Performance'].values
                    runtime_int = df[(df['Runtime'] == runtime) & (df['Benchmark'] == benchmark) &
                                     (df['Size'] == size) & (df['Data Type'] == 'int')]['Mean Performance'].values

                    if len(runtime_float) == 0 or len(runtime_int) == 0:
                        continue  # Skip if we don't have data for this runtime

                    runtime_float = runtime_float[0]
                    runtime_int = runtime_int[0]

                    float_relative = (runtime_float - native_float) / native_float * 100
                    int_relative = (runtime_int - native_int) / native_int * 100

                    results.append({
                        'Benchmark': benchmark,
                        'Size': size,
                        'Runtime': runtime,
                        'Float Relative Performance (%)': float_relative,
                        'Int Relative Performance (%)': int_relative
                    })

    return pd.DataFrame(results)

def format_table(df):
    df['Float Relative Performance (%)'] = df['Float Relative Performance (%)'].apply(lambda x: f"{x:.2f}%")
    df['Int Relative Performance (%)'] = df['Int Relative Performance (%)'].apply(lambda x: f"{x:.2f}%")
    return df

def main():
    # Load the data
    df = load_data()

    # Calculate relative performance
    relative_performance = calculate_relative_performance(df)

    # Format the table
    formatted_table = format_table(relative_performance)

    # Sort the table
    sorted_table = formatted_table.sort_values(['Benchmark', 'Size', 'Runtime'])

    # Save to markdown
    with open('analysis/tables/runtime_comparison_table.md', 'w') as f:
        f.write(sorted_table.to_markdown(index=False))

    print("Runtime comparison table has been generated and saved to 'runtime_comparison_table.md'")

if __name__ == "__main__":
    main()