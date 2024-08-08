import os
import csv
import numpy as np
from tabulate import tabulate
from scipy import stats

def process_file(file_path):
    with open(file_path, 'r') as f:
        reader = csv.reader(f)
        data = next(reader)  # Read the single line

    # Convert to numpy array and skip the first element
    numbers = np.array(data[1:], dtype=float)

    # Compute statistics
    return {
        "Mean": np.mean(numbers),
        "Median": np.median(numbers),
        "Std Dev": np.std(numbers),
        "Min": np.min(numbers),
        "Max": np.max(numbers),
        "Geometric Mean": stats.gmean(numbers)
    }

def process_benchmark(runtime, benchmark, size):
    file_path = f"Results/{runtime}/{benchmark}_{size}.csv"
    if os.path.exists(file_path):
        return process_file(file_path)
    return None

def geometric_mean_table(runtimes, benchmarks, sizes):
    table = []
    for benchmark in benchmarks:
        for size in sizes:
            row = [benchmark, size]
            native_metrics = process_benchmark('Native', benchmark, size)
            if native_metrics is None:
                continue
            native_gmean = native_metrics["Geometric Mean"]

            for runtime in runtimes[1:]:  # Skip 'Native'
                metrics = process_benchmark(runtime, benchmark, size)
                if metrics is None:
                    row.append('-')
                else:
                    ratio = metrics["Geometric Mean"] / native_gmean
                    row.append(f"{ratio:.2f}")

            table.append(row)

    return table

def full_stats_table(runtimes, benchmarks, sizes):
    table = []
    for runtime in runtimes:
        for benchmark in benchmarks:
            for size in sizes:
                metrics = process_benchmark(runtime, benchmark, size)
                if metrics is None:
                    continue
                row = [runtime, benchmark, size]
                row.extend([f"{metrics[stat]:.2f}" for stat in ["Mean", "Median", "Std Dev", "Min", "Max", "Geometric Mean"]])
                table.append(row)

    return table

def main():
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

    # Generate geometric mean tables
    print("Geometric Mean Ratio Tables:")
    for benchmark_type, benchmarks, sizes in [
        ("Vector Operations", vector_benchmarks, vector_sizes),
        ("Matrix Operations", matrix_benchmarks, matrix_sizes),
        ("Mandelbrot", mandelbrot_benchmarks, mandelbrot_sizes)
    ]:
        print(f"\n{benchmark_type}:")
        table = geometric_mean_table(runtimes, benchmarks, sizes)
        headers = ["Benchmark", "Size"] + runtimes[1:]
        print(tabulate(table, headers=headers, tablefmt="grid"))

    # Generate full stats table
    print("\nFull Statistics Table:")
    full_table = full_stats_table(runtimes, benchmarks, vector_sizes + matrix_sizes + mandelbrot_sizes)
    headers = ["Runtime", "Benchmark", "Size", "Mean", "Median", "Std Dev", "Min", "Max", "Geometric Mean"]
    print(tabulate(full_table, headers=headers, tablefmt="grid"))

if __name__ == "__main__":
    main()