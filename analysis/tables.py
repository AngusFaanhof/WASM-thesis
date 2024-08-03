import pandas as pd
import numpy as np
import os
from tabulate import tabulate

def read_csv(file_path):
    df = pd.read_csv(file_path, header=None, usecols=range(1, 50))
    return df.values.flatten()

def calculate_metrics(data):
    mean = np.mean(data)
    stdev = np.std(data)
    return mean, stdev

def process_benchmark(runtime, benchmark, size):
    file_path = f"Results/{runtime}/{benchmark}_{size}.csv"
    if not os.path.exists(file_path):
        return None
    data = read_csv(file_path)
    return calculate_metrics(data)

def generate_detailed_table(runtimes, benchmarks, sizes):
    table = []
    for benchmark in benchmarks:
        for size in sizes:
            native_metrics = process_benchmark('Native', benchmark, size)
            if native_metrics is None:
                continue

            row = [f"{benchmark} (size: {size})"]

            for runtime in runtimes:
                metrics = process_benchmark(runtime, benchmark, size)
                if metrics is None:
                    row.append('-')
                else:
                    mean, stdev = metrics
                    row.append(f"{mean:.2e} ± {stdev:.2e}")

            table.append(row)

    return table

runtimes = ["Native", "Wasmtime", "Wasmer", "Wasmedge"]
benchmarks = [
    "vectorDotProduct_float", "vectorDotProduct_int",
    "averageVector_float", "averageVector_int",
    "transposeMatrix_float", "transposeMatrix_int"
]

vector_sizes = [16, 4096, 262144]  # Example sizes, adjust as needed
matrix_sizes = [16, 256, 512]  # Example sizes, adjust as needed

# Generate detailed table
detailed_table = generate_detailed_table(runtimes, benchmarks, vector_sizes + matrix_sizes)

# Define headers for the table
headers = ["Benchmark"] + runtimes

# Generate LaTeX table
latex_table = tabulate(detailed_table, headers=headers, tablefmt="latex_booktabs")

# Print the LaTeX table
print(latex_table)

# Optionally, save the LaTeX table to a file
with open("detailed_benchmark_results.tex", "w") as f:
    f.write(latex_table)