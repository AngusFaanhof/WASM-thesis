#!/bin/bash

add_dot_sizes=(16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576)
matrix_mult_sizes=(16 64 256 1024 4096 16384 65536 262144 1048576)
mandelbrot_iterations=(16 32 64 128 256 512 1024 2048 4096)

for i in {1..5}; do
	runtime="CPP"

	for size in ${add_dot_sizes[@]}; do
		./benchmark 0 $size 1 >> "results/CPP/matrixMultiplication_f_${size}.csv"
		echo "${runtime} -float $size Addition"

		./benchmark 0 $size 0 >> "results/CPP/matrixMultiplication_i_${size}.csv"
		echo "${runtime} -int $size Addition"

		./benchmark 1 $size 1 >> "results/CPP/dotProduct_f_${size}.csv"
		echo "${runtime} -float $size Dot Product"

		./benchmark 1 $size 0 >> "results/CPP/dotProduct_i_${size}.csv"
		echo "${runtime} -int $size Dot Product"
	done

	for size in ${matrix_mult_sizes[@]}; do
		./benchmark 2 $size 1 >> "results/CPP/matrixMultiplication_f_${size}.csv"
		echo "${runtime} -float $size Matrix Multiplication"

		./benchmark 2 $size 0 >> "results/CPP/matrixMultiplication_i_${size}.csv"
		echo "${runtime} -int $size Matrix Multiplication"
	done

	for size in ${mandelbrot_iterations[@]}; do
		./benchmark 3 $size 0 >> "results/CPP/mandelbrot_${size}.csv"
		echo "${runtime} $size Mandelbrot"
	done

	runtime="wasmer"

	for size in ${add_dot_sizes[@]}; do
		${runtime_path} run ./benchmark.wasm 0 $size 1 >> "results/${runtime}/matrixMultiplication_f_${size}.csv"
		echo "${runtime} -float $size Addition"

		${runtime_path} run ./benchmark.wasm 0 $size 0 >> "results/${runtime}/matrixMultiplication_i_${size}.csv"
		echo "${runtime} -int $size Addition"

		${runtime_path} run ./benchmark.wasm 1 $size 1 >> "results/${runtime}/dotProduct_f_${size}.csv"
		echo "${runtime} -float $size Dot Product"

		${runtime_path} run ./benchmark.wasm 1 $size 0 >> "results/${runtime}/dotProduct_i_${size}.csv"
		echo "${runtime} -int $size Dot Product"
	done

	for size in ${matrix_mult_sizes[@]}; do
		${runtime_path} run ./benchmark.wasm 2 $size 1 >> "results/${runtime}/matrixMultiplication_f_${size}.csv"
		echo "${runtime} -float $size Matrix Multiplication"

		${runtime_path} run ./benchmark.wasm 2 $size 0 >> "results/${runtime}/matrixMultiplication_i_${size}.csv"
		echo "${runtime} -int $size Matrix Multiplication"
	done

	for size in ${mandelbrot_iterations[@]}; do
		${runtime_path} run ./benchmark.wasm 3 $size 0 >> "results/${runtime}/mandelbrot_${size}.csv"
		echo "${runtime} $size Mandelbrot"
	done

	runtime="wasmtime"

	for size in ${add_dot_sizes[@]}; do
		${runtime_path} run ./benchmark.wasm 0 $size 1 >> "results/${runtime}/matrixMultiplication_f_${size}.csv"
		echo "${runtime} -float $size Addition"

		${runtime_path} run ./benchmark.wasm 0 $size 0 >> "results/${runtime}/matrixMultiplication_i_${size}.csv"
		echo "${runtime} -int $size Addition"

		${runtime_path} run ./benchmark.wasm 1 $size 1 >> "results/${runtime}/dotProduct_f_${size}.csv"
		echo "${runtime} -float $size Dot Product"

		${runtime_path} run ./benchmark.wasm 1 $size 0 >> "results/${runtime}/dotProduct_i_${size}.csv"
		echo "${runtime} -int $size Dot Product"
	done

	for size in ${matrix_mult_sizes[@]}; do
		${runtime_path} run ./benchmark.wasm 2 $size 1 >> "results/${runtime}/matrixMultiplication_f_${size}.csv"
		echo "${runtime} -float $size Matrix Multiplication"

		${runtime_path} run ./benchmark.wasm 2 $size 0 >> "results/${runtime}/matrixMultiplication_i_${size}.csv"
		echo "${runtime} -int $size Matrix Multiplication"
	done

	for size in ${mandelbrot_iterations[@]}; do
		${runtime_path} run ./benchmark.wasm 3 $size 0 >> "results/${runtime}/mandelbrot_${size}.csv"
		echo "${runtime} $size Mandelbrot"
	done

	runtime="wavm"

	for size in ${add_dot_sizes[@]}; do
		${runtime_path} run ./benchmark.wasm 0 $size 1 >> "results/${runtime}/matrixMultiplication_f_${size}.csv"
		echo "${runtime} -float $size Addition"

		${runtime_path} run ./benchmark.wasm 0 $size 0 >> "results/${runtime}/matrixMultiplication_i_${size}.csv"
		echo "${runtime} -int $size Addition"

		${runtime_path} run ./benchmark.wasm 1 $size 1 >> "results/${runtime}/dotProduct_f_${size}.csv"
		echo "${runtime} -float $size Dot Product"

		${runtime_path} run ./benchmark.wasm 1 $size 0 >> "results/${runtime}/dotProduct_i_${size}.csv"
		echo "${runtime} -int $size Dot Product"
	done

	for size in ${matrix_mult_sizes[@]}; do
		${runtime_path} run ./benchmark.wasm 2 $size 1 >> "results/${runtime}/matrixMultiplication_f_${size}.csv"
		echo "${runtime} -float $size Matrix Multiplication"

		${runtime_path} run ./benchmark.wasm 2 $size 0 >> "results/${runtime}/matrixMultiplication_i_${size}.csv"
		echo "${runtime} -int $size Matrix Multiplication"
	done

	for size in ${mandelbrot_iterations[@]}; do
		${runtime_path} run ./benchmark.wasm 3 $size 0 >> "results/${runtime}/mandelbrot_${size}.csv"
		echo "${runtime} $size Mandelbrot"
	done
done