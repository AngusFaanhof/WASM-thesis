# method = ["dotProduct", "matrixAddition", "matrixMultiplicaiton", "mandelbrot"]
# read ../results/{method}/i_64.txt
# extract numbers as array
# compute mean, median, std, min, max

import numpy as np
import os


file_base = "../results/"
methods = ["dotProduct", "matrixAddition", "matrixMultiplication", "mandelbrot"]
use_float = False

iterations = [64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576]
# iterations = [64, 128, 256, 512, 1024]

files = []
dot_product_base = file_base + methods[0] + "/i_"

results = {}

for i in iterations:
	temp_file_name = dot_product_base + str(i) + ".txt"

	with open(temp_file_name, "r") as f:
		lines = f.readlines()

	numbers = lines[0].strip().split(',')
	numbers = [int(num) for num in numbers]

	mean = np.mean(numbers)
	median = np.median(numbers)
	std = np.std(numbers)
	minimum = np.min(numbers)
	maximum = np.max(numbers)

	results[i] = {
		"mean": mean,
		"median": median,
		"std": std,
		"minimum": minimum,
		"maximum": maximum,
		"iterations": i
	}

# print(results)

# plot iterations vs mean

import matplotlib.pyplot as plt
# from matplotlib.ticker import ticklabel_format

x = iterations
y = [results[i]["median"] for i in iterations]

import pandas as pd

data = {
	"Iterations": x,
	"Time (NS)": y
}

df = pd.DataFrame(data)

yerr = [results[i]["std"] for i in iterations]
plt.errorbar(df["Iterations"], df["Time (NS)"], yerr=yerr, fmt='o', label='Time (NS)')
# plt.plot(df["Iterations"], df["Time (NS)"], label='Time (NS)'

# plt.scatter(df["Iterations"], df["Time (NS)"])
plt.plot(df["Iterations"], df["Time (NS)"])

plt.xscale("log")
plt.yscale("log")
plt.xticks(
	iterations,
    ['64', '128', '256', '512', '1K', '2K', '4K', '8K', '16K', '32K', '64K', '128K', '256K', '512K', '1M']
)
plt.legend()
plt.show()