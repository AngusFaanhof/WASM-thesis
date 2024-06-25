#!/bin/bash

# Array of sizes
sizes=(64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288)
sizes2=(16 64 256 1024 4096 16384 65536 262144) # 1048576)
sizesm=(16 32 64 128 256 512 1024 2048 4096) # 4096)

runtimes=(wasmer wasmtime)

for l in {1..25}; do
	for size in ${sizes[@]}; do
		# matrix addition
		# dotProduct

		for runtime in ${runtimes[@]}; do
			# int
			$runtime ./benchmark.wasm 0 $size 0 >> "cold_results/$runtime/matrixAddition_i.csv"
			echo "matrixAddition $size $runtime -int done"

			$runtime ./benchmark.wasm 1 $size 0 >> "cold_results/$runtime/dotProduct_i.csv"
			echo "dotProduct $size $runtime -int done"

			# float
			$runtime ./benchmark.wasm 0 $size 1 >> "cold_results/$runtime/matrixAddition_f.csv"
			echo "matrixAddition $size $runtime -float done"

			$runtime ./benchmark.wasm 1 $size 1 >> "cold_results/$runtime/dotProduct_f.csv"
			echo "dotProduct $size $runtime -float done"
		done

		# int
		./benchmark 0 $size 0 >> "cold_results/CPP/matrixAddition_i.csv"
		echo "matrixAddition $size cpp -int done"

		./benchmark 1 $size 0 >> "cold_results/CPP/dotProduct_i.csv"
		echo "dotProduct $size cpp -int done"

		wavm run ./benchmark.wasm 0 $size 0 >> "cold_results/wavm/matrixAddition_i.csv"
		echo "matrixAddition $size wavm -int done"

		wavm run ./benchmark.wasm 1 $size 0 >> "cold_results/wavm/dotProduct_i.csv"
		echo "dotProduct $size wavm -int done"

		# float
		./benchmark 0 $size 1 >> "cold_results/CPP/matrixAddition_f.csv"
		echo "matrixAddition $size cpp -float done"

		./benchmark 1 $size 1 >> "cold_results/CPP/dotProduct_f.csv"
		echo "dotProduct $size cpp -float done"

		wavm run ./benchmark.wasm 0 $size 1 >> "cold_results/wavm/matrixAddition_f.csv"
		echo "matrixAddition $size wavm -float done"

		wavm run ./benchmark.wasm 1 $size 1 >> "cold_results/wavm/dotProduct_f.csv"
		echo "dotProduct $size wavm -float done"
	done

	for size in ${sizes2[@]}; do
		# matrix multiplication

		for runtime in ${runtimes[@]}; do
			# int
			$runtime ./benchmark.wasm 2 $size 0 >> "cold_results/$runtime/matrixMultiplication_i.csv"
			echo "matrixMultiplication $size $runtime -int done"

			$runtime ./benchmark.wasm 2 $size 1 >> "cold_results/$runtime/matrixMultiplication_f.csv"
			echo "matrixMultiplication $size $runtime -float done"
		done

		# int
		./benchmark 2 $size 0 >> "cold_results/CPP/matrixMultiplication_i.csv"
		echo "matrixMultiplication $size cpp -int done"

		wavm run ./benchmark.wasm 2 $size 0 >> "cold_results/wavm/matrixMultiplication_i.csv"
		echo "matrixMultiplication $size wavm -int done"

		# float
		./benchmark 2 $size 1 >> "cold_results/CPP/matrixMultiplication_f.csv"
		echo "matrixMultiplication $size cpp -float done"

		wavm run ./benchmark.wasm 2 $size 1 >> "cold_results/wavm/matrixMultiplication_f.csv"
		echo "matrixMultiplication $size wavm -float done"
	done

	for size in ${sizesm[@]}; do
		# mandelbrot

		for runtime in ${runtimes[@]}; do
			$runtime ./benchmark.wasm 3 $size 0 >> "cold_results/$runtime/mandelbrot.csv"
			echo "mandelbrot $size $runtime done"
		done

		./benchmark 3 $size 0 >> "cold_results/CPP/mandelbrot.csv"
		echo "mandelbrot $size cpp done"

		wavm run ./benchmark.wasm 3 $size 0 >> "cold_results/wavm/mandelbrot.csv"
		echo "mandelbrot $size wavm done"
	done
done