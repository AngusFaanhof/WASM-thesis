import pandas as pd
import numpy as np
import os
from tabulate import tabulate
from scipy import stats

def read_csv(file_path):
    df = pd.read_csv(file_path, header=None, usecols=range(1, 50))
    return df.values.flatten()

def calculate_geometric_mean(data):
    return stats.gmean(data)

def process_benchmark(runtime, benchmark, size):
    file_path = f"Results/{runtime}/{benchmark}_{size}.csv"
    if not os.path.exists(file_path):
        return None
    data = read_csv(file_path)
    return calculate_geometric_mean(data)

def format_number(number):
    if number < 1:
        return f"\\textbf{{{number:.4f}}}"
    elif number < 10:
        return f"{number:.2f}"
    else:
        return f"{number:.0f}"

def generate_relative_geometric_mean_table(runtimes, benchmark_categories):
    table = []
    for category, (benchmarks, sizes) in benchmark_categories.items():
        for benchmark in benchmarks:
            row = [f"{category}: {benchmark}"]
            native_means = []
            for size in sizes:
                native_mean = process_benchmark('Native', benchmark, size)
                if native_mean is not None:
                    native_means.append(native_mean)

            if not native_means:
                continue

            native_geomean = calculate_geometric_mean(native_means)
            row.append("1")  # Native is always 1

            for runtime in runtimes[1:]:  # Skip 'Native'
                runtime_means = []
                for size in sizes:
                    runtime_mean = process_benchmark(runtime, benchmark, size)
                    if runtime_mean is not None:
                        runtime_means.append(runtime_mean)

                if not runtime_means:
                    row.append('-')
                else:
                    runtime_geomean = calculate_geometric_mean(runtime_means)
                    ratio = runtime_geomean / native_geomean
                    row.append(format_number(ratio))

            table.append(row)

        # Add an empty row for better readability between categories
        table.append([""] * len(runtimes))

    return table

# Define benchmarks and sizes for each category
runtimes = ["Native", "Wasmtime", "Wasmer", "Wasmedge"]

benchmark_categories = {
    "Vector": (
        ["averageVector_float", "averageVector_int", "normalizeVector_float", "normalizeVector_int",
         "vectorDotProduct_float", "vectorDotProduct_int", "vectorAddition_float", "vectorAddition_int"],
        [16, 256, 4096, 65536, 262144]
    ),
    "Matrix": (
        ["multiplyMatrices_float", "multiplyMatrices_int", "transposeMatrix_int", "transposeMatrix_float"],
        [4, 16, 64, 256, 512]
    ),
    "Mandelbrot": (
        ["mandelbrot"],
        [16, 64, 256, 1024, 4096]
    )
}

table = generate_relative_geometric_mean_table(runtimes, benchmark_categories)

# Define headers for the table
headers = ["Algorithm", "Native", "Wasmtime", "Wasmer", "WasmEdge"]

# Generate LaTeX table
latex_table = tabulate(table, headers=headers, tablefmt="latex_booktabs")

# Print the LaTeX table
print(latex_table)

# Optionally, save the LaTeX table to a file
# with open("relative_geometric_mean_comparison.tex", "w") as f:
#     f.write(latex_table)

# print("Relative geometric mean comparison table has been generated and saved as 'relative_geometric_mean_comparison.tex'.")