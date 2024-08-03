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

# def create_distribution_plot(benchmark, size, data):
#     plt.figure(figsize=(12, 6))
#     sns.set_style("whitegrid")

#     df = pd.DataFrame({runtime: pd.Series(data[runtime]) for runtime in data.keys()})

#     sns.violinplot(data=df)
#     plt.title(f"Comparison of {benchmark} (Size: {size})")
#     plt.ylabel("Execution time (nanoseconds)", fontsize=12)
#     plt.xlabel("Runtime", fontsize=12)
#     # plt.yscale('log')  # Use log scale for better visualization

#     # Add exact median values as text
#     for i, runtime in enumerate(data.keys()):
#         median = df[runtime].median()
#         plt.text(i, median, f'{median:,.0f}', ha='center', va='bottom', fontweight='bold')
#         # plt.text(i, plt.ylim()[1], f'{median:,.0f}',
#         #          horizontalalignment='center', verticalalignment='bottom',
#         #          rotation=45, fontsize=8)
#     plt.ylim(bottom=0)
#     # plt.legend(labels=data.keys(), title="Runtime")
#     plt.tight_layout()

#     # Create 'plots' directory if it doesn't exist
#     os.makedirs('violet', exist_ok=True)

#     plt.savefig(f'violet/{benchmark}_{size}_distribution.png', dpi=300)
#     plt.close()


def create_distribution_plot(benchmark, size, data):
    plt.figure(figsize=(12, 6))
    sns.set_style("whitegrid")
    sns.set_palette('deep')

    df = pd.DataFrame({runtime: pd.Series(data[runtime]) for runtime in data.keys()})

    box_plot = sns.boxplot(data=df, showfliers=False, whis=1.5)
    # sns.stripplot(data=df, color=".3", size=3, alpha=0.6)

    # sns.violinplot(data=df)
    plt.title(f"Comparison of {benchmark}")
    plt.suptitle(f"Vector size: {size}", fontsize=12)
    plt.ylabel("Execution time (nanoseconds)", fontsize=12)
    plt.xlabel("Runtime", fontsize=12)
    # plt.yscale('log')  # Use log scale for better visualization

    plt.yscale('log')  # Use log scale for better visualization

    medians = df.median()
    means = df.mean()
    std_devs = df.std()

    # for i, (median, mean, std) in enumerate(zip(medians, means, std_devs)):
    #     plt.text(i, median, f'Median: {median:.0f}', ha='center', va='bottom', fontweight='bold')
    #     plt.text(i, mean, f'Mean: {mean:.0f}\nStd: {std:.0f}', ha='center', va='top', fontweight='bold')

    # plt.ylim(bottom=50, top=df.max().max() * 1.1)


    # plt.ylim(bottom=50, top=df.max().max() * 1.1)
    # plt.legend(labels=df.columns, title="Runtime")
    plt.tight_layout()

    # Create 'plots' directory if it doesn't exist
    os.makedirs('violet', exist_ok=True)

    plt.savefig(f'violet/{benchmark}_{size}_distribution.png', dpi=300)
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