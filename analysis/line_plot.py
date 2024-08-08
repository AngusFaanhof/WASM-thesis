import csv
import os
import numpy as np
from scipy import stats
import matplotlib.pyplot as plt
import seaborn as sns
import re

runtimes = ["Native", "Wasmtime", "Wasmer", "Wasmedge"]
benchmarks = [
    "averageVector_float", "averageVector_int", "normalizeVector_float", "normalizeVector_int",
    "vectorDotProduct_float", "vectorDotProduct_int", "vectorAddition_float", "vectorAddition_int",
    "multiplyMatrices_float", "multiplyMatrices_int", "transposeMatrix_int", "transposeMatrix_float",
    "mandelbrot"
]

vector_sizes = [16, 256, 4096, 65536, 262144]
vector_benchmarks = [
    "averageVector_float", "averageVector_int", "normalizeVector_float", "normalizeVector_int",
    "vectorDotProduct_float", "vectorDotProduct_int", "vectorAddition_float", "vectorAddition_int",
]

matrix_sizes = [4, 16, 64, 256, 512]
matrix_benchmarks = [
    "multiplyMatrices_float", "multiplyMatrices_int", "transposeMatrix_int", "transposeMatrix_float",
]

mandelbrot_sizes = [16, 64, 256, 1024, 4096]
mandelbrot_benchmarks = ["mandelbrot"]

def read_csv(file_path):
    with open(file_path, 'r') as f:
        return [int(x) for x in f.read().strip().split(',')[1:]]

def calculate_metrics(data):
    mean = np.mean(data)
    median = np.median(data)
    std_dev = np.std(data)
    ci = stats.t.interval(0.95, len(data)-1, loc=mean, scale=stats.sem(data))
    return {
        'mean': mean,
        'median': median,
        'std_dev': std_dev,
        'ci_lower': ci[0],
        'ci_upper': ci[1]
    }

def get_sizes_for_benchmark(benchmark):
    if benchmark in vector_benchmarks:
        return vector_sizes
    elif benchmark in matrix_benchmarks:
        return matrix_sizes
    elif benchmark in mandelbrot_benchmarks:
        return mandelbrot_sizes
    else:
        return []

results = {}

for runtime in runtimes:
    results[runtime] = {}
    for benchmark in benchmarks:
        results[runtime][benchmark] = {}
        sizes = get_sizes_for_benchmark(benchmark)
        for size in sizes:
            file_path = f"Results/{runtime}/{benchmark}_{size}.csv"
            if os.path.exists(file_path):
                data = read_csv(file_path)
                results[runtime][benchmark][size] = calculate_metrics(data)

# Generate line plots for each benchmark
os.makedirs("line", exist_ok=True)

def get_title(benchmark):
    # example input: normalizeVector_int
    # example title: Comparison normalize vector (int) performance across runtimes

    # Split the benchmark string by underscore
    parts = benchmark.split('_')

    # Convert camelCase to space-separated words for the first part
    operation = ' '.join(re.findall(r'[A-Z]?[a-z]+|[A-Z]+(?=[A-Z][a-z]|\d|\W|$)|\d+', parts[0]))

    # Capitalize the first letter of the operation
    operation = operation.capitalize()

    # Get the data type (if present)
    data_type = f" ({parts[1]})" if len(parts) > 1 else ""

    # Construct the title
    title = f"Comparison mean {operation}{data_type} performance across runtimes"

    return title

def get_x_label(benchmark):
    if benchmark in vector_benchmarks:
        return "Vector Size"
    elif benchmark in matrix_benchmarks:
        return "Matrix Size (n x n)"
    elif benchmark in mandelbrot_benchmarks:
        return "Max iterations"

for benchmark in benchmarks:
    sizes = get_sizes_for_benchmark(benchmark)
    plt.figure(figsize=(12, 6))


    # increase text size
    plt.rc('font', size=18)

    for runtime in runtimes:
        runtime_data = [results[runtime][benchmark][size]['mean'] for size in sizes if size in results[runtime][benchmark]]
        plt.plot(sizes[:len(runtime_data)], runtime_data, marker='o', label=runtime)

    plt.xlabel(get_x_label(benchmark))
    plt.ylabel('Execution Time (nano seconds)')
    # plt.title(get_title(benchmark))

    plt.xscale('log', base=2)  # Use log scale for x-axis as sizes often vary by orders of magnitude
    # plt.xscale('linear')
    plt.xticks(sizes, labels=sizes)

    plt.yscale('log', base=2)  # Use log scale for y-axis as execution times often vary by orders of magnitude
    plt.legend()
    plt.grid(True, which="both", ls="-", alpha=0.2)
    plt.tight_layout()
    plt.savefig(f'analysis/line/{benchmark}.png')
    plt.close()

print(f"Graphs have been saved in the 'graphs' directory.")