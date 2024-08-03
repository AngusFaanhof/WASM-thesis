import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import os

def read_csv(file_path):
    df = pd.read_csv(file_path, header=None, usecols=range(1, 50))
    return df.values.flatten()

def calculate_mean(data):
    return np.mean(data)

def process_benchmark(runtime, benchmark, size):
    file_path = f"Results/{runtime}/{benchmark}_{size}.csv"
    if not os.path.exists(file_path):
        return None
    data = read_csv(file_path)
    return calculate_mean(data)

def generate_heatmap_data(runtimes, benchmarks, sizes):
    data = {}
    for runtime in runtimes[1:]:  # Skip 'Native'
        runtime_data = []
        for benchmark in benchmarks:
            benchmark_data = []
            for size in sizes:
                native_mean = process_benchmark('Native', benchmark, size)
                runtime_mean = process_benchmark(runtime, benchmark, size)
                if native_mean is None or runtime_mean is None:
                    benchmark_data.append(np.nan)
                else:
                    ratio = runtime_mean / native_mean
                    benchmark_data.append(ratio)
            runtime_data.append(benchmark_data)
        data[runtime] = runtime_data
    return data

def create_heatmap(data, runtime, benchmarks, sizes, category):
    plt.figure(figsize=(12, 8))
    sns.set(font_scale=1.1)

    # Create heatmap
    ax = sns.heatmap(data, annot=True, fmt=".2f", cmap="RdYlGn_r", center=1,
                     xticklabels=sizes, yticklabels=benchmarks, cbar_kws={'label': 'Runtime / Native'})

    # Customize the plot
    plt.title(f"{category} Benchmarks: {runtime} vs Native")
    plt.xlabel("Size")
    plt.ylabel("Benchmark")

    # Rotate x-axis labels for better readability
    plt.xticks(rotation=45, ha='right')

    # Adjust layout and save
    plt.tight_layout()
    plt.savefig(f"heatmaps/{category.lower()}_{runtime.lower()}_heatmap.png", dpi=300, bbox_inches='tight')
    plt.close()

# Define benchmarks and sizes
runtimes = ["Native", "Wasmtime", "Wasmer", "Wasmedge"]

vector_benchmarks = [
    "averageVector_float", "averageVector_int", "normalizeVector_float", "normalizeVector_int",
    "vectorDotProduct_float", "vectorDotProduct_int", "vectorAddition_float", "vectorAddition_int"
]
vector_sizes = [16, 256, 4096, 65536, 262144]

matrix_benchmarks = [
    "multiplyMatrices_float", "multiplyMatrices_int", "transposeMatrix_int", "transposeMatrix_float"
]
matrix_sizes = [4, 16, 64, 256, 512]

mandelbrot_benchmarks = ["mandelbrot"]
mandelbrot_sizes = [16, 64, 256, 1024, 4096]

# Generate heatmap data
vector_data = generate_heatmap_data(runtimes, vector_benchmarks, vector_sizes)
matrix_data = generate_heatmap_data(runtimes, matrix_benchmarks, matrix_sizes)
mandelbrot_data = generate_heatmap_data(runtimes, mandelbrot_benchmarks, mandelbrot_sizes)

# Create heatmaps for each runtime and category
for runtime in runtimes[1:]:
    create_heatmap(vector_data[runtime], runtime, vector_benchmarks, vector_sizes, "Vector")
    create_heatmap(matrix_data[runtime], runtime, matrix_benchmarks, matrix_sizes, "Matrix")
    create_heatmap(mandelbrot_data[runtime], runtime, mandelbrot_benchmarks, mandelbrot_sizes, "Mandelbrot")

print("Heatmaps have been generated and saved as PNG files.")