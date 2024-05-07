# plot a mandelbrot set, based on a 1d array of iterations

import numpy as np
import matplotlib.pyplot as plt

from PIL import Image

# file format
# 1,1,1....1\n {pixelWidth} times
# 2,2,2....2\n
# ... {pixelHeight} times

width = 800
height = 600

# open mandelbrot.txt
# split on new line
# split on comma

with open('mandelbrot.txt', 'r') as f:
	lines = f.read().split('\n')

iterations = []
for line in lines:
	iterations.append(line.split(','))

for row in iterations:
	for i in range(len(row)):
		row[i] = int(row[i])

# convert to numpy array of ints
iterations = np.array(iterations, dtype=int)
iterations = (iterations / iterations.max() * 255).astype(np.uint8)
img = Image.fromarray(iterations)
img.show()

# plot the mandelbrot set based on iterations
plt.imshow(iterations, cmap='hot', interpolation='nearest')