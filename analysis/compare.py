import csv
import os
import numpy as np
from scipy import stats
import matplotlib.pyplot as plt
import seaborn as sns

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
        return [int(x) for x in f.read().strip().split(',')]

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

# Calculate geometric means across benchmarks for each runtime and size
for runtime in runtimes:
    results[runtime]['geometric_mean'] = {}
    for benchmark_group in [vector_benchmarks, matrix_benchmarks, mandelbrot_benchmarks]:
        sizes = get_sizes_for_benchmark(benchmark_group[0])
        for size in sizes:
            means = [results[runtime][benchmark][size]['mean'] for benchmark in benchmark_group
                     if size in results[runtime][benchmark]]
            if means:
                results[runtime]['geometric_mean'][size] = stats.gmean(means)

# Print overview
print("Performance Overview:")
for runtime in runtimes:
    print(f"\n{runtime}:")
    for benchmark in benchmarks + ['geometric_mean']:
        print(f"  {benchmark}:")
        sizes = get_sizes_for_benchmark(benchmark)
        for size in sizes:
            if benchmark in results[runtime] and size in results[runtime][benchmark]:
                metrics = results[runtime][benchmark][size]
                if benchmark == 'geometric_mean':
                    print(f"    Size {size}: {metrics:.2f}")
                else:
                    print(f"    Size {size}: Mean={metrics['mean']:.2f}, Median={metrics['median']:.2f}, "
                          f"StdDev={metrics['std_dev']:.2f}, 95% CI=[{metrics['ci_lower']:.2f}, {metrics['ci_upper']:.2f}]")

# Calculate and print relative performance
print("\nRelative Performance (compared to Native):")
for benchmark in benchmarks + ['geometric_mean']:
    print(f"\n{benchmark}:")
    sizes = get_sizes_for_benchmark(benchmark)
    for size in sizes:
        print(f"  Size {size}:")
        if 'Native' in results and benchmark in results['Native'] and size in results['Native'][benchmark]:
            native_mean = results['Native'][benchmark][size]['mean'] if benchmark != 'geometric_mean' else results['Native'][benchmark][size]
            for runtime in runtimes[1:]:  # Skip Native
                if runtime in results and benchmark in results[runtime] and size in results[runtime][benchmark]:
                    runtime_mean = results[runtime][benchmark][size]['mean'] if benchmark != 'geometric_mean' else results[runtime][benchmark][size]
                    relative_perf = native_mean / runtime_mean
                    print(f"    {runtime}: {relative_perf:.2f}x")

# Generate individual plots for each benchmark and size
os.makedirs("plots", exist_ok=True)

for benchmark in benchmarks:
    sizes = get_sizes_for_benchmark(benchmark)
    for size in sizes:
        plt.figure(figsize=(10, 6))
        data = []
        labels = []
        for runtime in runtimes:
            if benchmark in results[runtime] and size in results[runtime][benchmark]:
                metrics = results[runtime][benchmark][size]
                data.append(metrics['mean'])
                labels.append(runtime)

        sns.barplot(x=labels, y=data)
        plt.title(f'{benchmark} - Size {size}')
        plt.ylabel('Execution Time (ns)')
        plt.yscale('log')
        plt.xticks(rotation=45)
        plt.tight_layout()
        plt.savefig(f'plots/{benchmark}_{size}.png')
        plt.close()

# Generate LaTeX tables
def generate_latex_table(benchmark_group, sizes, caption):
    latex_table = "\\begin{table}[htbp]\n\\centering\n\\caption{" + caption + "}\n"
    latex_table += "\\begin{tabular}{l" + "r" * len(sizes) + "}\n\\hline\n"
    latex_table += "Runtime & " + " & ".join([f"Size {size}" for size in sizes]) + " \\\\ \\hline\n"

    for runtime in runtimes:
        row = [runtime]
        for size in sizes:
            if size in results[runtime]['geometric_mean']:
                row.append(f"{results[runtime]['geometric_mean'][size]:.2f}")
            else:
                row.append("-")
        latex_table += " & ".join(row) + " \\\\\n"

    latex_table += "\\hline\n\\end{tabular}\n\\end{table}"
    return latex_table

# print("\nLaTeX Tables:")
# print(generate_latex_table(vector_benchmarks, vector_sizes, "Geometric Mean Performance for Vector Operations"))
# print(generate_latex_table(matrix_benchmarks, matrix_sizes, "Geometric Mean Performance for Matrix Operations"))
# print(generate_latex_table(mandelbrot_benchmarks, mandelbrot_sizes, "Performance for Mandelbrot"))