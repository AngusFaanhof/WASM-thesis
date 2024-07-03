#!/bin/bash

add_dot_sizes=(16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288) #1048576)

# matrix_mult_sizes=(16 64 256 1024 4096 16384 65536 262144 1048576)
matrix_mult_sizes=(1048576 262144 65536 16384 4096 1024 256 64 16)
# mandelbrot_iterations=(16 32 64 128 256 512 1024 2048 4096)
mandelbrot_iterations=(4096 2048 1024 512 256 128 64 32 16)

# loop 5 times
# for i in {1..5}; do
# 	for size in ${matrix_mult_sizes[@]}; do
# 		./benchmark 2 $size 1 >> "results/CPP/matrixMultiplication_f_${size}.csv"
# 		echo "-float $size"
# 	done
# done

# runtime="wasmtime"
# runtime_path="/home/angus/.wasmtime/bin/wasmtime"

# runtime="wasmer"
# runtime_path="/home/angus/.wasmer/bin/wasmer"

# runtime_path="/usr/bin/wavm"
# runtime="wavm"

runtime="CPP"

# method="addition"
# for i in {1..5}; do
# 	for size in ${add_dot_sizes[@]}; do
# 		# ${runtime_path} run ./benchmark.wasm 0 $size 0 >> "results/${runtime}/${method}_i_${size}.csv"
# 		./benchmark 0 $size 0 >> "results/${runtime}/${method}_i_${size}.csv"
# 		echo "-int $size"
# 	done

# 	for size in ${add_dot_sizes[@]}; do
# 		# ${runtime_path} run ./benchmark.wasm 0 $size 1 >> "results/${runtime}/${method}_f_${size}.csv"
# 		./benchmark 0 $size 1 >> "results/${runtime}/${method}_f_${size}.csv"
# 		echo "-float $size"
# 	done
# done

# method="dotProduct"
# for i in {1..5}; do
# 	for size in ${add_dot_sizes[@]}; do
# 		# ${runtime_path} run ./benchmark.wasm 1 $size 0 >> "results/${runtime}/${method}_i_${size}.csv"
# 		./benchmark 1 $size 0 >> "results/${runtime}/${method}_i_${size}.csv"
# 		echo "-int $size"
# 	done

# 	for size in ${add_dot_sizes[@]}; do
# 		# ${runtime_path} run ./benchmark.wasm 1 $size 1 >> "results/${runtime}/${method}_f_${size}.csv"
# 		./benchmark 1 $size 1 >> "results/${runtime}/${method}_f_${size}.csv"
# 		echo "-float $size"
# 	done
# done

# method="matrixMultiplication"
# # for i in {1..2}; do
# for size in ${matrix_mult_sizes[@]}; do
# 	for i in {1..2}; do
# 	# ${runtime_path} run ./benchmark.wasm 2 $size 0 >> "results/${runtime}/${method}_i_${size}.csv"
# 		./benchmark 2 $size 1 >> "results/${runtime}/${method}_f_${size}.csv"
# 		echo "-float $size"

# 		./benchmark 2 $size 0 >> "results/${runtime}/${method}_i_${size}.csv"
# 		echo "-int $size"
# 	done
# done
# done
# mandelbrot_iterations=(2048 1024) 512 256 128 64 32 16)
# method="mandelbrot"
# # for size in ${mandelbrot_iterations[@]}; do
# # 	# for i in {1.}; do
# # 		# ${runtime_path} run ./benchmark.wasm 3 $size 0 >> "results/${runtime}/${method}_${size}.csv"
# # 	./benchmark 3 $size 0 >> "results/${runtime}/${method}_${size}.csv"
# # 	echo "-int $size"
# # 	# done
# # done
# mandelbrot_iterations=(512 256 128 64 32 16)
# for i in {1..4}; do
# 	for size in ${mandelbrot_iterations[@]}; do
# 		# ${runtime_path} run ./benchmark.wasm 3 $size 0 >> "results/${runtime}/${method}_${size}.csv"
# 		./benchmark 3 $size 0 >> "results/${runtime}/${method}_${size}.csv"
# 		echo "-int $size"
# 	done
# done


mandelbrot_iterations=(4096 2048 1024 512 256 128 64 32 16)

runtime="wasmer"
runtime_path="/home/angus/.wasmer/bin/wasmer"

method="matrixMultiplication"
# for i in {1..2}; do
for size in ${matrix_mult_sizes[@]}; do
	for i in {1..5}; do
		${runtime_path} run ./benchmark.wasm 2 $size 1 >> "results/${runtime}/${method}_f_${size}.csv"
		# ./benchmark 2 $size 1 >> "results/${runtime}/${method}_f_${size}.csv"
		echo "-float $method $size"

		${runtime_path} run ./benchmark.wasm 2 $size 0 >> "results/${runtime}/${method}_i_${size}.csv"
		# ./benchmark 2 $size 0 >> "results/${runtime}/${method}_i_${size}.csv"
		echo "-int $method $size"
	done
done
# done

method="mandelbrot"
for size in ${mandelbrot_iterations[@]}; do
	for i in {1..5}; do
		${runtime_path} run ./benchmark.wasm 3 $size 0 >> "results/${runtime}/${method}_${size}.csv"
		# ./benchmark 3 $size 0 >> "results/${runtime}/${method}_${size}.csv"
		echo "-int $size"
	done
done

runtime="wasmtime"
runtime_path="/home/angus/.wasmtime/bin/wasmtime"

method="matrixMultiplication"
for i in {1..5}; do
	for size in ${matrix_mult_sizes[@]}; do
		${runtime_path} run ./benchmark.wasm 2 $size 1 >> "results/${runtime}/${method}_f_${size}.csv"
		# ./benchmark 2 $size 1 >> "results/${runtime}/${method}_f_${size}.csv"
		echo "-float $method $size"

		${runtime_path} run ./benchmark.wasm 2 $size 0 >> "results/${runtime}/${method}_i_${size}.csv"
		# ./benchmark 2 $size 0 >> "results/${runtime}/${method}_i_${size}.csv"
		echo "-int $method $size"
	done
done

method="mandelbrot"
for i in {1..5}; do
	for size in ${mandelbrot_iterations[@]}; do
		${runtime_path} run ./benchmark.wasm 3 $size 0 >> "results/${runtime}/${method}_${size}.csv"
		# ./benchmark 3 $size 0 >> "results/${runtime}/${method}_${size}.csv"
		echo "-int $size"
	done
done