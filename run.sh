#!/bin/bash

# Array of sizes
sizes=(64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576)
sizes2=(16 64 256 1024 4096 16384 65536 262144 1048576)
sizesm=(16 32 64 128 256 512 1024 2048 4096)

# Loop over sizes
# for size in "${sizes[@]}"; do
# 	./benchmark 0 $size 0 0
# done


# WASM

# INT
# matrixAddition
# {
	for size in "${sizes[@]}"; do
		wasmtime ./benchmark.wasm 0 $size 0 1 >> "results/WASM/matrixAddition.txt"
	done

	# dotProduct
	for size in "${sizes[@]}"; do
		wasmtime ./benchmark.wasm 1 $size 0 1 >> "results/WASM/dotProduct.txt"
	done

	# matrixMultiplicaiton
	for size in "${sizes2[@]}"; do
		wasmtime ./benchmark.wasm 2 $size 0 1 >> "results/WASM/matrixMultiplication.txt"
	done

	# mandelbrot
	for size in "${sizesm[@]}"; do
		wasmtime ./benchmark.wasm 3 $size 0 1 >> "results/WASM/mandelbrot.txt"
	done

	# FLOAT

	# matrixAddition
	for size in "${sizes[@]}"; do
		wasmtime ./benchmark.wasm 0 $size 1 1 >> "results/WASM/matrixAddition.txt"
	done

	# dotProduct
	for size in "${sizes[@]}"; do
		wasmtime ./benchmark.wasm 1 $size 1 1 >> "results/WASM/dotProduct.txt"
	done

	# matrixMultiplicaiton
	for size in "${sizes2[@]}"; do
		wasmtime ./benchmark.wasm 2 $size 1 1 >> "results/WASM/matrixMultiplication.txt"
	done
# }
# CPP

{
	# INT
	# matrixAddition
	for size in "${sizes[@]}"; do
		./benchmark 0 $size 0 0 >> "results/CPP/matrixAddition.txt"
		echo "matrixAddition $size done"
	done

	# dotProduct
	for size in "${sizes[@]}"; do
		./benchmark 1 $size 0 0 >> "results/CPP/dotProduct.txt"
		echo "dotProduct $size done"
	done

	# matrixMultiplicaiton
	for size in "${sizes2[@]}"; do
		./benchmark 2 $size 0 0 >> "results/CPP/matrixMultiplication.txt"
		echo "matrixMultiplication $size done"
	done

	# mandelbrot
	for size in "${sizesm[@]}"; do
		./benchmark 3 $size 0 0 >> "results/CPP/mandelbrot.txt"
		echo "mandelbrot $size done"
	done

	# FLOAT

	# matrixAddition
	for size in "${sizes[@]}"; do
		./benchmark 0 $size 1 0 >> "results/CPP/matrixAddition.txt"
		echo "matrixAddition $size done"
	done

	# dotProduct
	for size in "${sizes[@]}"; do
		./benchmark 1 $size 1 0 >> "results/CPP/dotProduct.txt"
		echo "dotProduct $size done"
	done

	# matrixMultiplicaiton
	for size in "${sizes2[@]}"; do
		./benchmark 2 $size 1 0 >> "results/CPP/matrixMultiplication.txt"
		echo "matrixMultiplication $size done"
	done
}