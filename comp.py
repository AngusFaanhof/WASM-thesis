import numpy as np
from tabulate import tabulate

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
		"addition": {
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
		"addition": {
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
		"addition": {
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
		"addition": {
			"int": {},
			"float": {},
		},
		"matrixMultiplication": {
			"int": {},
			"float": {},
		}
	}
}

dirs = ["CPP", "wasmtime", "wasmer", "wavm"]
iterations = [16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576]
mandel_iterations = [16, 32, 64, 128, 256, 512, 1024, 2048, 4096]
matrix_mult_iterations = [16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576]
methods = ["dotProduct", "addition", "matrixMultiplication", "mandelbrot"]

# add_dot_sizes=(16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288)
# read results/{dirs}[i]}/addition_i_{iteration}.csv and store in data["{dirs}"]["addition"]["int"][iteration]
# read results/{dirs}[i]}/addition_f_{iteration}.csv and store in data["{dirs}"]["addition"]["float"][iteration]

for d in dirs:
	for i in iterations:
		for method in ["dotProduct", "addition"]:
			with open(f"results/{d}/{method}_i_{i}.csv", "r") as f:
				data[d][method]["int"][i] = [int(x) for x in f.read().replace("\n", ",").split(",")[:-1]]

			with open(f"results/{d}/{method}_f_{i}.csv", "r") as f:
				data[d][method]["float"][i] = [int(x) for x in f.read().replace("\n", ",").split(",")[:-1]]

	for i in mandel_iterations:
		with open(f"results/{d}/mandelbrot_{i}.csv", "r") as f:
			data[d]["mandelbrot"]["int"][i] = [int(x) for x in f.read().replace("\n", ",").split(",")[:-1]]

	for i in matrix_mult_iterations:
		with open(f"results/{d}/matrixMultiplication_i_{i}.csv", "r") as f:
			data[d]["matrixMultiplication"]["int"][i] = [int(x) for x in f.read().replace("\n", ",").split(",")[:-1]]

		with open(f"results/{d}/matrixMultiplication_f_{i}.csv", "r") as f:
			data[d]["matrixMultiplication"]["float"][i] = [int(x) for x in f.read().replace("\n", ",").split(",")[:-1]]
		# mandelbrot
stats = {
	"CPP": {
		"addition": {
			"int": {
				"mean": {},
				"std": {},
				"median": {}
			},
			"float": {
				"mean": {},
				"std": {},
				"median": {}
			}
		},
		"dotProduct": {
			"int": {
				"mean": {},
				"std": {},
				"median": {}
			},
			"float": {
				"mean": {},
				"std": {},
				"median": {}
			}
		},
		"matrixMultiplication": {
			"int": {
				"mean": {},
				"std": {},
				"median": {}
			},
			"float": {
				"mean": {},
				"std": {},
				"median": {}
			}
		},
		"mandelbrot": {
			"mean": {},
			"std": {},
			"median": {}
		}
	},
	"wasmer": {
		"addition": {
			"int": {
				"mean": {},
				"std": {},
				"median": {}
			},
			"float": {
				"mean": {},
				"std": {},
				"median": {}
			}
		},
		"dotProduct": {
			"int": {
				"mean": {},
				"std": {},
				"median": {}
			},
			"float": {
				"mean": {},
				"std": {},
				"median": {}
			}
		},
		"matrixMultiplication": {
			"int": {
				"mean": {},
				"std": {},
				"median": {}
			},
			"float": {
				"mean": {},
				"std": {},
				"median": {}
			}
		},
		"mandelbrot": {
			"mean": {},
			"std": {},
			"median": {}
		}
	},
	"wasmtime": {
		"addition": {
			"int": {
				"mean": {},
				"std": {},
				"median": {}
			},
			"float": {
				"mean": {},
				"std": {},
				"median": {}
			}
		},
		"dotProduct": {
			"int": {
				"mean": {},
				"std": {},
				"median": {}
			},
			"float": {
				"mean": {},
				"std": {},
				"median": {}
			}
		},
		"matrixMultiplication": {
			"int": {
				"mean": {},
				"std": {},
				"median": {}
			},
			"float": {
				"mean": {},
				"std": {},
				"median": {}
			}
		},
		"mandelbrot": {
			"mean": {},
			"std": {},
			"median": {}
		}
	},
	"wavm": {
		"addition": {
			"int": {
				"mean": {},
				"std": {},
				"median": {}
			},
			"float": {
				"mean": {},
				"std": {},
				"median": {}
			}
		},
		"dotProduct": {
			"int": {
				"mean": {},
				"std": {},
				"median": {}
			},
			"float": {
				"mean": {},
				"std": {},
				"median": {}
			}
		},
		"matrixMultiplication": {
			"int": {
				"mean": {},
				"std": {},
				"median": {}
			},
			"float": {
				"mean": {},
				"std": {},
				"median": {}
			}
		},
		"mandelbrot": {
			"mean": {},
			"std": {},
			"median": {}
		}
	}
}

for d in dirs:
	for t in ["int", "float"]:
		for i in iterations:
			for m in ["addition", "dotProduct"]:
				stats[d][m][t]["mean"][i] = np.mean(data[d][m][t][i])
				stats[d][m][t]["std"][i] = np.std(data[d][m][t][i])
				stats[d][m][t]["median"][i] = np.median(data[d][m][t][i])

		for i in matrix_mult_iterations:
			stats[d]["matrixMultiplication"][t]["mean"][i] = np.mean(data[d]["matrixMultiplication"][t][i])
			stats[d]["matrixMultiplication"][t]["std"][i] = np.std(data[d]["matrixMultiplication"][t][i])
			stats[d]["matrixMultiplication"][t]["median"][i] = np.median(data[d]["matrixMultiplication"][t][i])

	for i in mandel_iterations:
		stats[d]["mandelbrot"]["mean"][i] = np.mean(data[d]["mandelbrot"]["int"][i])
		stats[d]["mandelbrot"]["std"][i] = np.std(data[d]["mandelbrot"]["int"][i])
		stats[d]["mandelbrot"]["median"][i] = np.median(data[d]["mandelbrot"]["int"][i])

def print_table(metric, datatype, stats, method, iterations):
	headers = ["Iteration", "CPP", "wasmer", "wasmtime", "wavm"]

	if method == "mandelbrot":
		data = [
			[
				iterations[i],
				stats["CPP"][method][metric][iterations[i]],
				stats["wasmer"][method][metric][iterations[i]],
				stats["wasmtime"][method][metric][iterations[i]],
				stats["wavm"][method][metric][iterations[i]]
			]
			for i in range(len(iterations))
		]

	else:
		data = [
			[
				iterations[i],
				stats["CPP"][method][datatype][metric][iterations[i]],
				stats["wasmer"][method][datatype][metric][iterations[i]],
				stats["wasmtime"][method][datatype][metric][iterations[i]],
				stats["wavm"][method][datatype][metric][iterations[i]]
			]
			for i in range(len(iterations))
		]

	print(f"| {method} {datatype} {metric}")
	print(tabulate(data, headers=headers, tablefmt="grid"))

# print_table("median", "int", stats, "addition", iterations)
# print_table("median", "float", stats, "addition", iterations)
# print_table("median", "float", stats, "dotProduct")

def print_scale_table(metric, datatype, stats, method, iterations):
	headers = ["Iteration", "CPP", "wasmer", "wasmtime", "wavm"]
	if method == "mandelbrot":
		data = [
			[
				iterations[i],
				stats["CPP"][method][metric][iterations[i]] / stats["CPP"][method][metric][iterations[i-1]],
				stats["wasmer"][method][metric][iterations[i]] / stats["wasmer"][method][metric][iterations[i-1]],
				stats["wasmtime"][method][metric][iterations[i]] / stats["wasmtime"][method][metric][iterations[i-1]],
				stats["wavm"][method][metric][iterations[i]] / stats["wavm"][method][metric][iterations[i-1]]
			]
			for i in range(1,len(iterations))
		]
	else:
		data =  [
			[
				iterations[i],
				stats["CPP"][method][datatype][metric][iterations[i]] / stats["CPP"][method][datatype][metric][iterations[i-1]],
				stats["wasmer"][method][datatype][metric][iterations[i]] / stats["wasmer"][method][datatype][metric][iterations[i-1]],
				stats["wasmtime"][method][datatype][metric][iterations[i]] / stats["wasmtime"][method][datatype][metric][iterations[i-1]],
				stats["wavm"][method][datatype][metric][iterations[i]] / stats["wavm"][method][datatype][metric][iterations[i-1]]
			]
			for i in range(1,len(iterations))
		]
	data.insert(0, [iterations[0], 1, 1, 1, 1])

	# data = [iterations[0], 1, 1, 1]
	print(f"| {method} {datatype} {metric} scaling relative to previous iteration")
	print(tabulate(data, headers=headers, tablefmt="grid", floatfmt=".2f"))

# print_scale_table("mean", "int", stats, "mandelbrot", mandel_iterations)
# print_scale_table("median", "int", stats, method, iterations)
# print_scale_table("median", "float", stats, method, iterations)
# print(stats["wasmer"]["matrixMultiplication"]["int"]["mean"])

def print_relative_table(metric, datatype, stats, method, iterations):
	headers = ["Iteration", "wasmer", "wasmtime", "wavm"]

	if method == "mandelbrot":
		data = [
			[
				iterations[i],
				stats["wasmer"][method][metric][iterations[i]] / stats["CPP"][method][metric][iterations[i]],
				stats["wasmtime"][method][metric][iterations[i]] / stats["CPP"][method][metric][iterations[i]],
				stats["wavm"][method][metric][iterations[i]] / stats["CPP"][method][metric][iterations[i]]
			]
			for i in range(len(iterations))
		]
	else:
		data =  [
			[
				iterations[i],
				stats["wasmer"][method][datatype][metric][iterations[i]] / stats["CPP"][method][datatype][metric][iterations[i]],
				stats["wasmtime"][method][datatype][metric][iterations[i]] / stats["CPP"][method][datatype][metric][iterations[i]],
				stats["wavm"][method][datatype][metric][iterations[i]] / stats["CPP"][method][datatype][metric][iterations[i]]
			]
			for i in range(len(iterations))
		]

	print(f"| {method} {datatype} {metric} relative to CPP")
	print(tabulate(data, headers=headers, tablefmt="grid", floatfmt=".2f"))

method = "dotProduct"

print_relative_table("median", "int", stats, method, iterations)
print_relative_table("median", "float", stats, method, iterations)
exit()

# print_relative_table("median", "float", stats, "dotProduct")
# exit()


import matplotlib.pyplot as plt
import numpy as np

def plot_single_graph(data, iterations, operation, data_type, runtimes):
    fig, ax = plt.subplots(figsize=(12, 8))
    fig.suptitle(f"Performance Comparison Across Runtimes: {operation} - {data_type}")

    ax.set_yscale('log', base=2)
    ax.set_xlabel("Iterations")

    ax.set_xscale('log', base=2)
    ax.set_ylabel("Time (ns)")

    all_means = []

    for runtime in runtimes:
        means = []
        errors = []
        for iteration in iterations:
            values = np.array(data[runtime][operation][data_type][iteration])
            mean = np.mean(values)
            std = np.std(values)
            means.append(mean)
            errors.append(std)

        scaled_means = [(means[0] / iterations[0]) * iter for iter in iterations]

        # Plot original means
        ax.errorbar(iterations, means, yerr=errors, label=runtime, capsize=5, marker='o')

        # Plot scaled means
        # ax.plot(iterations, scaled_means, linestyle='--', label=f'{runtime} linear scaled')

        all_means.extend(means)

    ax.legend()
    ax.grid(True, which="both", ls="-", alpha=0.2)

    plt.tight_layout()
    plt.show()

# Example usage:
operation = "dotProduct"
data_type = "int"
runtimes = ["CPP", "wasmtime", "wasmer", "wavm"]
iterations = [16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288]


# Example usage:
operations = ["dotProduct", "addition"]
data_types = ["int", "float"]
runtimes = ["CPP", "wasmtime", "wasmer", "wavm"]

# plot_single_graph(data, mandel_iterations, "mandelbrot", "int", ["CPP", "wasmtime"])
# plot_single_graph(data, mandel_iterations, "mandelbrot", "int", ["CPP", "wasmer"])
# plot_single_graph(data, mandel_iterations, "mandelbrot", "int", ["CPP", "wavm"])
# plot_grouped_data(data, iterations, operations, data_types, runtimes)

# plot_grouped_data(
# 	data,
# 	mandel_iterations,
# 	["mandelbrot"],
# 	["int", "float"],
# 	runtimes
# )

# plot_grouped_data(
# 	data,
# 	matrix_mult_iterations,
# 	["matrixMultiplication"],
# 	["int", "float"],
# 	runtimes
# )

import matplotlib.pyplot as plt
import numpy as np

def plot_grouped_bar(method, datatype, runtimes, data, iterations, title):
    fig, ax = plt.subplots(figsize=(15, 8))

    bar_width = 0.8 / len(runtimes)
    opacity = 0.8

    for i, runtime in enumerate(runtimes):
        means = [np.median(data[runtime][method][datatype][iter]) for iter in iterations]
        stds = [np.std(data[runtime][method][datatype][iter]) for iter in iterations]
        positions = np.arange(len(iterations)) + i * bar_width

        ax.bar(positions, means, bar_width,
               alpha=opacity,
               label=runtime,
               yerr=stds,
               capsize=5)

    ax.set_ylabel('Execution time (ns)')
    ax.set_xlabel('Iterations')
    ax.set_title(title)
    ax.set_xticks(np.arange(len(iterations)) + bar_width * (len(runtimes) - 1) / 2)
    ax.set_xticklabels(iterations, rotation=45, ha='right')
    ax.legend()

    ax.set_yscale('log', base=2)

    plt.tight_layout()
    plt.show()

# Example usage:
method = "addition"
datatype = "int"
runtimes = ["CPP", "wasmtime", "wasmer", "wavm"]
# iterations = [16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 104]

plot_grouped_bar(method, datatype, runtimes, data, matrix_mult_iterations, "Matrix Multiplication Execution Time (int)")
def plot_relative_performance(data, iterations, operation, data_type, runtimes):
    fig, ax = plt.subplots(figsize=(12, 8))
    fig.suptitle(f"Relative Performance: {operation} - {data_type}")

    ax.set_yscale('log', base=2)
    ax.set_xlabel("Iterations")
    ax.set_ylabel("Relative Performance (C++ = 1)")

    for runtime in runtimes:
        if runtime == "CPP":
            continue
        relative_means = []
        for iteration in iterations:
            cpp_mean = np.mean(data["CPP"][operation][data_type][iteration])
            runtime_mean = np.mean(data[runtime][operation][data_type][iteration])
            relative_means.append(runtime_mean / cpp_mean)

        ax.plot(iterations, relative_means, label=runtime, marker='o')

    ax.axhline(y=1, color='black', linestyle='--', label='C++ baseline')
    ax.legend()
    ax.grid(True, which="both", ls="-", alpha=0.2)

    plt.tight_layout()
    plt.show()

# Usage example
# plot_relative_performance(data, iterations, "dotProduct", "int", runtimes)