import pandas as pd
import json
from tabulate import tabulate

methods = ["dotProduct", "matrixAddition", "matrixMultiplication", "mandelbrot"]
runtimes = ["CPP", "wasmtime", "wasmer", "wavm"]

data = {
	"CPP": {
		"dotProduct": {
			"int": {},
			"float": {},
		},
		"mandelbrot": {
			"int": {},
			"float": {},
		},
		"matrixAddition": {
			"int": {},
			"float": {},
		},
		"matrixMultiplication": {
			"int": {},
			"float": {},
		}
	},
	"wasmtime": {
		"dotProduct": {
			"int": {},
			"float": {},
		},
		"mandelbrot": {
			"int": {},
			"float": {},
		},
		"matrixAddition": {
			"int": {},
			"float": {},
		},
		"matrixMultiplication": {
			"int": {},
			"float": {},
		}
	},
	"wasmer": {
		"dotProduct": {
			"int": {},
			"float": {},
		},
		"mandelbrot": {
			"int": {},
			"float": {},
		},
		"matrixAddition": {
			"int": {},
			"float": {},
		},
		"matrixMultiplication": {
			"int": {},
			"float": {},
		}
	},
	"wavm": {
		"dotProduct": {
			"int": {},
			"float": {},
		},
		"mandelbrot": {
			"int": {},
			"float": {},
		},
		"matrixAddition": {
			"int": {},
			"float": {},
		},
		"matrixMultiplication": {
			"int": {},
			"float": {},
		}
	}
}

iterations = {
	"dotProduct": [64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288],
	"matrixAddition": [64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288],
	"matrixMultiplication": [16, 64, 256, 1024, 4096, 16384, 65536, 262144],
	"mandelbrot": [16, 32, 64, 128, 256, 512, 1024, 2048, 4096]
}

def gen_data():
	# read data
	for method in methods:
		for runtime in runtimes:
			for datatype in ["int", "float"]:
				t = "_i" if datatype == "int" else "_f"

				if method == "mandelbrot":
					t = ""

				path = "results/" + runtime + "/" + method + t + ".csv"

				with open(path, "r") as file:
					# enumerate readlines
					for i, line in enumerate(file.readlines()):
						times = line[:-1].split(",")
						times = [int(x) for x in times]

						df = pd.DataFrame(times)
						data[runtime][method][datatype][str(iterations[method][i])] = {
							"mean": df.mean().tolist()[0],
							"std": df.std().tolist()[0],
							"min": df.min().tolist()[0],
							"max": df.max().tolist()[0],
							"median": df.median().tolist()[0],
						}


	# # save to json file
	with open("results.json", "w") as file:
		json.dump(data, file)

gen_data()

# read data
for method in methods:
	for runtime in runtimes:
		for datatype in ["int", "float"]:
			t = "_i" if datatype == "int" else "_f"

			if method == "mandelbrot":
				t = ""

			path = "results/" + runtime + "/" + method + t + ".csv"

			with open(path, "r") as file:
				lines = [list(map(int, line.strip().split(","))) for line in file]

				transposed_lines = list(zip(*lines))
				header = iterations[method]

				df = pd.DataFrame(transposed_lines, columns=header)

				data[runtime][method][datatype] = df

def get_cold(method, datatype):
	cpp_cold = data["CPP"][method][datatype].iloc[0]
	wasmer_cold = data["wasmer"][method][datatype].iloc[0]
	wasmtime_cold = data["wasmtime"][method][datatype].iloc[0]
	wavm_cold = data["wavm"][method][datatype].iloc[0]

	cold_data = [
	[iterations["dotProduct"][i], cpp_cold.iloc[i], wasmer_cold.iloc[i], wasmtime_cold.iloc[i], wavm_cold.iloc[i]]
		for i in range(14)
	]
	cold_headers = ["Iteration", "CPP", "wasmer", "wasmtime", "wavm"]

	print("| Cold")
	print(tabulate(cold_data, headers=cold_headers, tablefmt="pipe"))

	cold_relative_data = [
	[iterations["dotProduct"][i], wasmer_cold.iloc[i] / cpp_cold.iloc[i] * 100, wasmtime_cold.iloc[i] / cpp_cold.iloc[i] * 100, wavm_cold.iloc[i] / cpp_cold.iloc[i] * 100]
		for i in range(14)
	]
	cold_relative_headers = ["Iteration", "wasmer", "wasmtime", "wavm"]

	print()
	print("| Cold relative to CPP")
	print(tabulate(cold_relative_data, headers=cold_relative_headers, tablefmt="pipe", floatfmt=".2f"))

def get_hot(method, datatype):
	cpp_hot = data["CPP"][method][datatype].iloc[1:].median()
	wasmer_hot = data["wasmer"][method][datatype].iloc[1:].median()
	wasmtime_hot = data["wasmtime"][method][datatype].iloc[1:].median()
	wavm_hot = data["wavm"][method][datatype].iloc[1:].median()

	hot_headers = ["Iteration", "CPP", "wasmer", "wasmtime", "wavm"]

	hot_data = [
		[iterations[method][i], cpp_hot.iloc[i], wasmer_hot.iloc[i], wasmtime_hot.iloc[i], wavm_hot.iloc[i]]
		for i in range(len(iterations[method]))
	]
	# add a last row with avarage of the column
	# hot_data.append(["Average", cpp_hot.mean(), wasmer_hot.mean(), wasmtime_hot.mean(), wavm_hot.mean()])

	print("|Hot means")
	print(tabulate(hot_data, headers=hot_headers, tablefmt="pipe", floatfmt=".2f"))
	print()

	hot_relative_headers = ["Iterations", "wasmer", "wasmtime", "wavm"]
	hot_relative_data = [
	[iterations[method][i], wasmer_hot.iloc[i] / cpp_hot.iloc[i] * 100, wasmtime_hot.iloc[i] / cpp_hot.iloc[i] * 100, wavm_hot.iloc[i] / cpp_hot.iloc[i] * 100]
		for i in range(len(iterations[method]))
	]


	# print("Hot relative to CPP")
	print(tabulate(hot_relative_data, headers=hot_relative_headers, tablefmt="pipe", floatfmt=".2f"))
	print()

# get_hot("dotProduct", "int")

# for method in methods:
# 	for datatype in ["int", "float"]:
# 		print(f"## {method} {datatype}")
# 		get_hot(method, datatype)
# 		print()
# 		print()
# 		print()

get_hot("mandelbrot", "int")