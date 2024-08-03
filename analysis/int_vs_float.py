import os
import csv
import numpy as np
from scipy import stats
import pandas as pd

def read_csv(file_path):
    with open(file_path, 'r') as f:
        reader = csv.reader(f)
        data = next(reader)[1:]  # Skip the first measurement
    return [float(x) for x in data]

def analyze_performance(float_measurements, int_measurements):
    float_mean = np.mean(float_measurements)
    int_mean = np.mean(int_measurements)
    float_std = np.std(float_measurements, ddof=1)
    int_std = np.std(int_measurements, ddof=1)

    t_statistic, p_value = stats.ttest_ind(float_measurements, int_measurements)

    pooled_std = np.sqrt((float_std**2 + int_std**2) / 2)
    effect_size = abs(float_mean - int_mean) / pooled_std

    perf_diff = ((float_mean - int_mean) / int_mean) * 100

    return {
        'float_performance': f"{float_mean:.2f} ± {float_std:.2f}",
        'int_performance': f"{int_mean:.2f} ± {int_std:.2f}",
        'perf_diff': f"{perf_diff:.2f}{'*' if p_value < 0.05 else ''}",
        'p_value': f"{p_value:.4f}",
        'effect_size': f"{effect_size:.2f}"
    }

def get_effect_size_description(effect_size):
    if effect_size > 0.8:
        return "Large"
    elif effect_size > 0.5:
        return "Medium"
    elif effect_size > 0.2:
        return "Small"
    else:
        return "Negligible"

def main():
    runtimes = ["Native", "Wasmtime", "Wasmer", "Wasmedge"]
    benchmarks = [
        "averageVector", "normalizeVector", "vectorDotProduct", "vectorAddition",
        "multiplyMatrices", "transposeMatrix"
    ]
    vector_sizes = [16, 256, 4096, 65536, 262144]
    matrix_sizes = [4, 16, 64, 256, 512]

    results = []

    for runtime in runtimes:
        for benchmark in benchmarks:
            sizes = vector_sizes if "Vector" in benchmark or "vector" in benchmark else matrix_sizes
            for size in sizes:
                float_file = f"Results/{runtime}/{benchmark}_float_{size}.csv"
                int_file = f"Results/{runtime}/{benchmark}_int_{size}.csv"

                if os.path.exists(float_file) and os.path.exists(int_file):
                    float_data = read_csv(float_file)
                    int_data = read_csv(int_file)
                    analysis = analyze_performance(float_data, int_data)

                    results.append({
                        'Runtime': runtime,
                        'Benchmark': benchmark,
                        'Size': size,
                        'Float Performance': analysis['float_performance'],
                        'Int Performance': analysis['int_performance'],
                        'Performance Difference (%)': analysis['perf_diff'],
                        'p-value': analysis['p_value'],
                        'Effect Size': f"{analysis['effect_size']} ({get_effect_size_description(float(analysis['effect_size']))})"
                    })

    # Create a DataFrame and sort it
    df = pd.DataFrame(results)
    df = df.sort_values(['Runtime', 'Benchmark', 'Size'])

    # Generate Markdown table
    markdown_table = df.to_markdown(index=False)

    # Save to file
    with open('performance_comparison_table.md', 'w') as f:
        f.write(markdown_table)

    print("Table has been generated and saved to 'performance_comparison_table.md'")

if __name__ == "__main__":
    main()