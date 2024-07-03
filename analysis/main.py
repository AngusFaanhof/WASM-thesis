import json

import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

with open("results.json", "r") as file:
	data = json.load(file)

# example access
# data["wasmtime"]["dotProduct"]["int"]["64"]
# "64": {
# 	"mean": 179.08,
# 	"std": 37.408688830270435,
# 	"min": 160,
# 	"max": 351,
# 	"median": 170
# },


methods = ["dotProduct", "mandelbrot", "matrixAddition", "matrixMultiplication"]
runtimes = ["CPP", "wasmtime", "wasmer", "wavm"]
data_types = ["int", "float"]

method_idx = 3

method = methods[method_idx]
datatype = "int"
metric = "Median"

def process_data(data, language, algorithm, data_type):
	records = []
	for iteration_n, stats in data[language][algorithm][data_type].items():
		# if int(iteration_n) < 4000:
		# 	continue

		record = {
			'Runtime': language,
			'Algorithm': algorithm,
			'DataType': data_type,
			'Iteration': int(iteration_n),
			'Mean': stats['mean'],
			'Std': stats['std'],
			'Min': stats['min'],
			'Max': stats['max'],
			'Median': stats['median']
		}
		records.append(record)

	return records

def plot(data, method, datatype, metric):
	cpp_records = process_data(data, 'CPP', method, datatype)
	wasmtime_records = process_data(data, 'wasmtime', method, datatype)
	wasmer_records = process_data(data, 'wasmer', method, datatype)
	wavm_records = process_data(data, 'wavm', method, datatype)

	df = pd.DataFrame(cpp_records + wasmtime_records + wasmer_records + wavm_records)

	start_y = cpp_records[0][metric]
	y_values = [start_y * 5**i for i in range(4)]


	print(y_values)

	# error bars
	means = df.pivot_table(index='Iteration', columns='Runtime', values=metric, aggfunc="mean")
	stds = df.pivot_table(index='Iteration', columns='Runtime', values='Std', aggfunc="mean")

	# Plotting
	fig, ax = plt.subplots(figsize=(10, 6))

	# Number of groups and bar width
	n_groups = len(means.index)
	bar_width = 0.2
	index = np.arange(n_groups)

	for i, runtime in enumerate(means.columns):
		ax.bar(index + i*bar_width, means[runtime], yerr=stds[runtime], width=bar_width, label=runtime)

	ax.set_xlabel('Size')
	ax.set_ylabel(f'{metric} Execution Time')
	ax.set_title(f'{metric} Execution Time by Runtime and Iteration with Std Error')
	ax.set_xticks(index + bar_width / 2)
	ax.set_xticklabels(means.index)
	ax.set_yscale('log', base=2)
	ax.legend()

	# ax.plot(index, y_values, label='wasmtime trend', marker='o', linestyle='-', color='red')


	plt.xticks(rotation=90)

	plt.tight_layout()
	plt.show()

# plot(data, method, datatype, "Mean")

def bar_plot(iteration, method):
	cpp_records = process_data(data, 'CPP', method, datatype)
	wasmtime_records = process_data(data, 'wasmtime', method, datatype)
	wasmer_records = process_data(data, 'wasmer', method, datatype)
	wavm_records = process_data(data, 'wavm', method, datatype)

	df = pd.DataFrame(cpp_records + wasmtime_records + wasmer_records + wavm_records)

    # Filter the DataFrame for the specified iteration
	filtered_df = df[df['Iteration'] == iteration]

	# Prepare data for plotting
	runtimes = ['CPP', 'wasmtime', 'wasmer', 'wavm']
	means = [filtered_df[filtered_df['Runtime'] == runtime][method].mean() for runtime in runtimes]
	stds = [filtered_df[filtered_df['Runtime'] == runtime]['Std'].mean() for runtime in runtimes]
	index = np.arange(len(runtimes))
	bar_width = 0.35

	# Create the bar plot
	fig, ax = plt.subplots()
	bars = ax.bar(index, means, bar_width, yerr=stds, label=method)

	# Add some text for labels, title, and axes ticks
	ax.set_xlabel('Runtime')
	ax.set_ylabel(f'{method} Execution Time')
	ax.set_title(f'{method} Execution Time by Runtime for Iteration {iteration}')
	ax.set_xticks(index)
	ax.set_xticklabels(runtimes)
	ax.legend()

	plt.tight_layout()
	plt.show()

bar_plot(1024, "dotProduct")
# cpp_records = process_data(data, 'CPP', method, datatype)
# wasmtime_records = process_data(data, 'wasmtime', method, datatype)
# wasmer_records = process_data(data, 'wasmer', method, datatype)
# wavm_records = process_data(data, 'wavm', method, datatype)

# df = pd.DataFrame(cpp_records + wasmtime_records + wasmer_records + wavm_records)

# means = df.pivot_table(index='Iteration', columns='Runtime', values=metric, aggfunc="mean")
# stds = df.pivot_table(index='Iteration', columns='Runtime', values='Std', aggfunc="mean")

# # Plotting
# fig, ax = plt.subplots(figsize=(10, 6))

# # Number of groups and bar width
# n_groups = len(means.index)
# bar_width = 0.2
# index = np.arange(n_groups)

# for i, runtime in enumerate(means.columns):
#     ax.bar(index + i*bar_width, means[runtime], yerr=stds[runtime], width=bar_width, label=runtime)

# ax.set_xlabel('Iteration')
# ax.set_ylabel('Median Execution Time')
# ax.set_title('Median Execution Time by Runtime and Iteration with Std Error')
# ax.set_xticks(index + bar_width / 2)
# ax.set_xticklabels(means.index)
# ax.set_yscale('log', base=2)
# ax.legend()

# plt.xticks(rotation=90)

# plt.tight_layout()
# plt.show()