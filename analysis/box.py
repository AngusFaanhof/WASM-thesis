import os
import csv
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

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

def get_sizes_for_benchmark(benchmark):
    if benchmark in vector_benchmarks:
        return vector_sizes
    elif benchmark in matrix_benchmarks:
        return matrix_sizes
    elif benchmark in mandelbrot_benchmarks:
        return mandelbrot_sizes
    else:
        return []

def read_csv(file_path):
    with open(file_path, 'r') as f:
        return [int(x) for x in f.read().strip().split(',')]

def create_distribution_plot(benchmark, size, data):
    plt.figure(figsize=(12, 6))
    sns.set_style("whitegrid")

    df = pd.DataFrame({runtime: pd.Series(data[runtime]) for runtime in data.keys()})

    # Create box plot
    sns.boxplot(data=df)

    plt.title(f"Distribution of {benchmark} (Size: {size})")
    plt.ylabel("Time (nanoseconds)")
    plt.yscale('log')  # Use log scale for better visualization

    # Add exact median values as text
    medians = df.median()
    for i, median in enumerate(medians):
        plt.text(i, plt.ylim()[1], f'{median:,.0f}',
                 horizontalalignment='center', verticalalignment='bottom',
                 rotation=45, fontsize=8)

    plt.tight_layout()

    # Create 'plots' directory if it doesn't exist
    os.makedirs('boxplots', exist_ok=True)

    plt.savefig(f'boxplots/{benchmark}_{size}_distribution.png')
    plt.close()

def main():
    for benchmark in benchmarks:
        sizes = get_sizes_for_benchmark(benchmark)
        for size in sizes:
            data = {}
            for runtime in runtimes:
                file_path = f"Results/{runtime}/{benchmark}_{size}.csv"
                try:
                    data[runtime] = read_csv(file_path)
                except FileNotFoundError:
                    print(f"File not found: {file_path}")
                    continue

            if data:  # Only create plot if we have data
                create_distribution_plot(benchmark, size, data)
                print(f"Created distribution plot for {benchmark} (Size: {size})")

if __name__ == "__main__":
    main()