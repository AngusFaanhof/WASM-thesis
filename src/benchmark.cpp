#include <iostream>
#include <chrono>

#include "../include/helpers.h"
#include "../include/MatrixAddition.h"
#include "../include/dotProduct.h"
#include "../include/MatrixMultiplication.h"
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

int main(int argc, char** args) {
	int data[EXPERIMENT_ITERATIONS];

	int size = 500;

	int* a = generateIntArray(size);
	int* b = generateIntArray(size);

	for (int i = 0; i < EXPERIMENT_ITERATIONS; i++) {
		auto start = std::chrono::high_resolution_clock::now();

		// addMatrices(a, b, 100);
		// dotProduct(a,b, size);
		// multiplyMatrices(a, size, size, b, size, size);
		// vectorizedMandelbrot(800, 600, size);


		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		data[i] = duration.count();
	}

	printResults(data, size);

	return 0;
}