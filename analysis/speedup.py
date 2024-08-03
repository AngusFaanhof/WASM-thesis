import csv
import os
import numpy as np
from scipy import stats

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
                results[runtime][benchmark][size] = np.mean(data)

# Calculate speedups for each runtime
speedups = {}

for runtime in runtimes:
    speedups[runtime] = {}
    for benchmark in benchmarks:
        speedups[runtime][benchmark] = []
        sizes = get_sizes_for_benchmark(benchmark)
        prev_mean = None

        for i, size in enumerate(sizes):
            if size in results[runtime][benchmark]:
                mean = results[runtime][benchmark][size]

                if i == 0:
                    scale_factor = 1.0  # No scale factor for the first size
                else:
                    scale_factor = mean / prev_mean

                speedups[runtime][benchmark].append((size, scale_factor))
                prev_mean = mean

# Print tables
for runtime in runtimes:
    print(f"\n{runtime}")
    for benchmark in benchmarks:
        print(f"\n  {benchmark}")
        print("  Size | Scale Factor")
        print("  -----|-------------")
        for size, scale_factor in speedups[runtime][benchmark]:
            if scale_factor == 1.0:
                print(f"  {size:4d} | -")
            else:
                print(f"  {size:4d} | {scale_factor:.2f}x")

# Optionally, save to a file
with open("scale_factor_tables.txt", "w") as f:
    for runtime in runtimes:
        f.write(f"\n{runtime}\n")
        for benchmark in benchmarks:
            f.write(f"\n  {benchmark}\n")
            f.write("  Size | Scale Factor\n")
            f.write("  -----|-------------\n")
            for size, scale_factor in speedups[runtime][benchmark]:
                if scale_factor == 1.0:
                    f.write(f"  {size:4d} | -\n")
                else:
                    f.write(f"  {size:4d} | {scale_factor:.2f}x\n")

print("\nScale factor tables have been saved to 'scale_factor_tables.txt'")