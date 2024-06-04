#include <iostream>
#include <chrono>

#include "../include/helpers.h"
#include "../include/matrixAddition.h"
#include "../include/dotProduct.h"
#include "../include/matrixMultiplication.h"
#include "../include/mandelbrot.h"

int EXPERIMENT_ITERATIONS = 25;

void printResults(int* data, int size, int* a = nullptr, int* b = nullptr) {
	std::cout << "Size: " << size << std::endl;

	// print a if not null
	if (a != nullptr) {
		std::cout << "Matrix A: [";
		printArray(a, size);
		std::cout << "]" << std::endl;
	}

	// print b if not null
	if (b != nullptr) {
		std::cout << "Matrix B: [";
		printArray(b, size);
		std::cout << "]" << std::endl;
	}

	// print benchmark
	for (int i = 0; i < EXPERIMENT_ITERATIONS; i++) {
		std::cout << i << ": " << data[i] << "Ms" << std::endl;
	}
}

void printResults(int* data, int size, float* a = nullptr, float* b = nullptr) {
	std::cout << "Size: " << size << std::endl;

	// print a if not null
	if (a != nullptr) {
		std::cout << "Matrix A: [";
		printArray(a, size);
		std::cout << "]" << std::endl;
	}

	// print b if not null
	if (b != nullptr) {
		std::cout << "Matrix B: [";
		printArray(b, size);
		std::cout << "]" << std::endl;
	}

	// print benchmark
	for (int i = 0; i < EXPERIMENT_ITERATIONS; i++) {
		std::cout << i << ": " << data[i] << "Ms" << std::endl;
	}
}

int main(int argc, char** args) {
	int data[EXPERIMENT_ITERATIONS];

	int size = 500;

	int* aInt = generateIntArray(size);
	int* bInt = generateIntArray(size);

	float* aFloat = gererateFloatArray(size);
	float* bFloat = gererateFloatArray(size);

	for (int i = 0; i < EXPERIMENT_ITERATIONS; i++) {
		auto start = std::chrono::high_resolution_clock::now();

		addMatrices(aInt, bInt, 100);
		// dotProduct(a,b, size);
		// multiplyMatrices(a, size, size, b, size, size);
		// vectorizedMandelbrot(800, 600, size);

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		data[i] = duration.count();
	}

	// printResults(data, size, aFloat, bFloat);
	printResults(data, size, aInt, bInt);
	// printResults(data, size);

	return 0;
}