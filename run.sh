#!/bin/bash

add_dot_sizes=(16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288)
matrix_mult_sizes=(16 64 256 1024 4096 16384 65536 262144 1048576)
mandelbrot_iterations=(16 32 64 128 256 512 1024 2048 4096)

# matrixAddition
{
	for size in ${add_dot_sizes[@]}; do
		# int
		{
			# cpp
			./benchmark 0 $size 0 >> "results/CPP/matrixAddition_i.csv"
			echo "cpp matrixAddition -int $size"

			# wasmer
			wasmer ./benchmark.wasm 0 $size 0 >> "results/wasmer/matrixAddition_i.csv"
			echo "wasmer matrixAddition -int $size"

			# wasmtime
			wasmtime ./benchmark.wasm 0 $size 0 >> "results/wasmtime/matrixAddition_i.csv"
			echo "wasmtime matrixAddition -int $size"

			# wavm
			wavm run ./benchmark.wasm 0 $size 0 >> "results/wavm/matrixAddition_i.csv"
			echo "wavm matrixAddition -int $size"
		}

		# float
		{
			# cpp
			./benchmark 0 $size 1 >> "results/CPP/matrixAddition_f.csv"
			echo "cpp matrixAddition -float $size"

			# wasmer
			wasmer ./benchmark.wasm 0 $size 1 >> "results/wasmer/matrixAddition_f.csv"
			echo "wasmer matrixAddition -float $size"

			# wasmtime
			wasmtime ./benchmark.wasm 0 $size 1 >> "results/wasmtime/matrixAddition_f.csv"
			echo "wasmtime matrixAddition -float $size"

			# wavm
			wavm run ./benchmark.wasm 0 $size 1 >> "results/wavm/matrixAddition_f.csv"
			echo "wavm matrixAddition -float $size"
		}
	done
}

# # dotProduct
# {
# 	for size in ${add_dot_sizes[@]}; do
# 		# int
# 		{
# 			# cpp
# 			./benchmark 1 $size 0 >> "results/CPP/dotProduct_i.csv"
# 			echo "cpp dotProduct -int $size"

# 			# wasmer
# 			wasmer ./benchmark.wasm 1 $size 0 >> "results/wasmer/dotProduct_i.csv"
# 			echo "wasmer dotProduct -int $size"

# 			# wasmtime
# 			wasmtime ./benchmark.wasm 1 $size 0 >> "results/wasmtime/dotProduct_i.csv"
# 			echo "wasmtime dotProduct -int $size"

# 			# wavm
# 			wavm run ./benchmark.wasm 1 $size 0 >> "results/wavm/dotProduct_i.csv"
# 			echo "wavm dotProduct -int $size"
# 		}

# 		# float
# 		{
# 			# cpp
# 			./benchmark 1 $size 1 >> "results/CPP/dotProduct_f.csv"
# 			echo "cpp dotProduct -float $size"

# 			# wasmer
# 			wasmer ./benchmark.wasm 1 $size 1 >> "results/wasmer/dotProduct_f.csv"
# 			echo "wasmer dotProduct -float $size"

# 			# wasmtime
# 			wasmtime ./benchmark.wasm 1 $size 1 >> "results/wasmtime/dotProduct_f.csv"
# 			echo "wasmtime dotProduct -float $size"

# 			# wavm
# 			wavm run ./benchmark.wasm 1 $size 1 >> "results/wavm/dotProduct_f.csv"
# 			echo "wavm dotProduct -float $size"
# 		}
# 	done
# }

# # matrixMultiplication
# {
# 	for size in ${matrix_mult_sizes[@]}; do
# 		# int
# 		{
# 			# cpp
# 			./benchmark 2 $size 0 >> "results/CPP/matrixMultiplication_i.csv"
# 			echo "cpp matrixMultiplication -int $size"

# 			# wasmer
# 			wasmer ./benchmark.wasm 2 $size 0 >> "results/wasmer/matrixMultiplication_i.csv"
# 			echo "wasmer matrixMultiplication -int $size"

# 			# wasmtime
# 			wasmtime ./benchmark.wasm 2 $size 0 >> "results/wasmtime/matrixMultiplication_i.csv"
# 			echo "wasmtime matrixMultiplication -int $size"

# 			# wavm
# 			wavm run ./benchmark.wasm 2 $size 0 >> "results/wavm/matrixMultiplication_i.csv"
# 			echo "wavm matrixMultiplication -int $size"
# 		}

# 		# float
# 		{
# 			# cpp
# 			./benchmark 2 $size 1 >> "results/CPP/matrixMultiplication_f.csv"
# 			echo "cpp matrixMultiplication -float $size"

# 			# wasmer
# 			wasmer ./benchmark.wasm 2 $size 1 >> "results/wasmer/matrixMultiplication_f.csv"
# 			echo "wasmer matrixMultiplication -float $size"

# 			# wasmtime
# 			wasmtime ./benchmark.wasm 2 $size 1 >> "results/wasmtime/matrixMultiplication_f.csv"
# 			echo "wasmtime matrixMultiplication -float $size"

# 			# wavm
# 			wavm run ./benchmark.wasm 2 $size 1 >> "results/wavm/matrixMultiplication_f.csv"
# 			echo "wavm matrixMultiplication -float $size"
# 		}
# 	done
# }

# # mandelbrot
# {
# 	for size in ${mandelbrot_iterations[@]}; do
# 		# cpp
# 		./benchmark 3 $size 0 >> "results/CPP/mandelbrot.csv"
# 		echo "cpp mandelbrot $size"

# 		# wasmer
# 		wasmer ./benchmark.wasm 3 $size 0 >> "results/wasmer/mandelbrot.csv"
# 		echo "wasmer mandelbrot $size"

# 		# wasmtime
# 		wasmtime ./benchmark.wasm 3 $size 0 >> "results/wasmtime/mandelbrot.csv"
# 		echo "wasmtime mandelbrot $size"

# 		# wavm
# 		wavm run ./benchmark.wasm 3 $size 0 >> "results/wavm/mandelbrot.csv"
# 		echo "wavm mandelbrot $size"
# 	done
# }