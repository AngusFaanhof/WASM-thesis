# import numpy as np
# import matplotlib.pyplot as plt
# import csv

# # Read the CSV file
# add_dot_sizes = [16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288]
# m_size = [16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576]
# # mandelbrot_iterations=(16 32 64 128 256 512 1024 2048 4096)
# # m_iterations =
# sizes = add_dot_sizes

# data = []
# with open('results/wavm/matrixAddition_i.csv', 'r') as file:
#     csv_reader = csv.reader(file)
#     for row in csv_reader:
#         data.append([int(x) for x in row])

# # Calculate medians
# medians = [np.mean(row) for row in data]

# # Create the plot
# plt.figure(figsize=(12, 8))

# # Plot the actual data
# plt.boxplot(data, positions=sizes, widths=0.6)

# # Plot the line that starts with the median of the first value and follows 2x
# first_median = medians[0]
# theoretical = [first_median * (2**i) for i in range(len(sizes))]
# plt.plot(sizes, theoretical, 'r--', label='2x growth')

# # Set the scale
# plt.xscale('log', base=2)
# plt.yscale('log', base=2)

# # Set labels and title
# plt.xlabel('Input Size')
# plt.ylabel('Execution Time (ns)')
# plt.title('Dot Product Performance (Float)')

# # Set x-axis ticks
# plt.xticks(sizes, sizes)

# # Add legend
# plt.legend()

# # Add grid
# plt.grid(True, which="both", ls="-", alpha=0.2)

# # Show the plot
# plt.tight_layout()
# plt.show()

# #########

import numpy as np
import matplotlib.pyplot as plt
import csv
import os

def read_csv(file_path):
    with open(file_path, 'r') as file:
        csv_reader = csv.reader(file)
        return [[int(x) for x in row] for row in csv_reader]

# Define sizes and runtimes
sizes = [16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288]
runtimes = ['CPP', 'wasmer', 'wasmtime', 'wavm']

# Read data and calculate medians
medians = {}
for runtime in runtimes:
    file_path = f'results/{runtime}/matrixAddition_i.csv'
    if os.path.exists(file_path):
        data = read_csv(file_path)
        medians[runtime] = [np.median(row) for row in data]
    else:
        print(f"Warning: File not found - {file_path}")
        medians[runtime] = [0] * len(sizes)  # placeholder data

# Set up the plot
fig, ax = plt.subplots(figsize=(15, 8))

# Set the width of each bar and the positions of the bars
width = 0.2
x = np.arange(len(sizes))

# Plot bars for each runtime
for i, runtime in enumerate(runtimes):
    ax.bar(x + i*width, medians[runtime], width, label=runtime)

# Customize the plot
ax.set_ylabel('Median Execution Time (ns)')
ax.set_xlabel('Input Size')
ax.set_title('Dot Product Performance Comparison (Float)')
ax.set_xticks(x + width * 1.5)
ax.set_xticklabels(sizes)
ax.legend()

# Use log scale for y-axis
ax.set_yscale('log', base=2)

# Rotate x-axis labels for better readability
plt.setp(ax.get_xticklabels(), rotation=45, ha='right')

# Add grid lines
ax.grid(True, which='major', axis='y', linestyle='--', alpha=0.7)

# Adjust layout and display the plot
plt.tight_layout()
plt.show()