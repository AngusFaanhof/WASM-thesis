// #include <immintrin.h>
#include <iostream>
#include <random>
#include <chrono>

// #include "sources/MatrixMultiplication.h"
#include "../include/MatrixAddition.h"
#include "../include/helpers.h"
#include "../include/dotProduct.h"
#include "../include/MatrixMultiplication.h"

int EXPERIMENT_ITERATIONS = 25;

int main(int argc, char** args) {
	int data[EXPERIMENT_ITERATIONS];

	int size = 10;

	int* a = generateIntArray(size * size);
	int* b = generateIntArray(size * size);

	for (int i = 0; i < EXPERIMENT_ITERATIONS; i++) {
		auto start = std::chrono::high_resolution_clock::now();

		// addMatrices(a, b, 100);
		multiplyMatrices(a, size, size, b, size, size);

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		data[i] = duration.count();
	}

	// format
	// size
	// a: [1,....,,n]
	// b: [1,....,,n]
	// 0: {MS}ms
	// 1: {MS}ms
	// ..
	// 9: {MS}ms

	// print size
	// std::cout << "Size: " << size << std::endl;

	// print a
	// std::cout << "Matrix A: [";
	// printArray(a, size);
	// std::cout << "]" << std::endl;

	// print b
	// std::cout << "Matrix B: [";
	// printArray(b, size);
	// std::cout << "]" << std::endl;

	// print benchmark
	for (int i = 0; i < EXPERIMENT_ITERATIONS; i++) {
		std::cout << i << ": " << data[i] << "Ms" << std::endl;
	}


	return 0;
}