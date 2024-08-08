import pandas as pd
import numpy as np
from scipy import stats
import os
from tabulate import tabulate

def read_csv(file_path):
    # Read the CSV file without headers, and ignore the first column
    df = pd.read_csv(file_path, header=None, usecols=range(1, 50))
    return df

def calculate_metrics(data):
    mean = np.mean(data)
    median = np.median(data)
    stdev = np.std(data)
    ci = stats.t.interval(0.95, len(data)-1, loc=mean, scale=stats.sem(data))
    return mean, median, stdev, ci

def process_benchmark(runtime, benchmark, size):
    file_path = f"Results/{runtime}/{benchmark}_{size}.csv"
    if not os.path.exists(file_path):
        return None
    df = read_csv(file_path)
    # Flatten the dataframe to a 1D array for metric calculation
    data = df.values.flatten()
    return calculate_metrics(data)

def generate_table(runtimes, benchmarks, sizes):
    table = []
    for benchmark in benchmarks:
        for size in sizes:
            row = [benchmark, size]
            native_metrics = process_benchmark('Native', benchmark, size)
            if native_metrics is None:
                continue
            native_mean = native_metrics[0]

            for runtime in runtimes[1:]:  # Skip 'Native'
                metrics = process_benchmark(runtime, benchmark, size)
                if metrics is None:
                    row.append('-')
                else:
                    ratio = metrics[0] / native_mean
                    row.append(f"{ratio:.1f}")

            table.append(row)

    return table

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

# Generate tables for each benchmark type
vector_table = generate_table(runtimes, vector_benchmarks, vector_sizes)
matrix_table = generate_table(runtimes, matrix_benchmarks, matrix_sizes)
mandelbrot_table = generate_table(runtimes, mandelbrot_benchmarks, mandelbrot_sizes)

# Combine all tables
final_table = vector_table + matrix_table + mandelbrot_table

# Define headers for the table
headers = ["Algorithm", "Size", "Wasmtime / Native", "Wasmer / Native", "WasmEdge / Native"]

# Generate LaTeX table
latex_table = tabulate(final_table, headers=headers, tablefmt="latex_booktabs")
table = tabulate(final_table, headers=headers, tablefmt="grid")

# Print the LaTeX table
print(table)

# Optionally, save the LaTeX table to a file
with open("analysis/tables/benchmark_results.tex", "w") as f:
    f.write(latex_table)