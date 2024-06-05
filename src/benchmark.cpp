#include <iostream>
#include <chrono>
#include <cstring>
#include <cmath>

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
		std::cout << "Matrix A: [" << std::endl;;
		printArray(a, size);
		std::cout << std::endl << "]" << std::endl;
	}

	// print b if not null
	if (b != nullptr) {
		std::cout << "Matrix B: [" << std::endl;
		printArray(b, size);
		std::cout << std::endl << "]" << std::endl;
	}

	// print benchmark
	std::cout << "Benchmark: [" << std::endl;
	printArray(data, EXPERIMENT_ITERATIONS);
	std::cout << std::endl << "]" << std::endl;
}

void printResults(int* data, int size, float* a = nullptr, float* b = nullptr) {
	std::cout << "Size: " << size << std::endl;

	// print a if not null
	if (a != nullptr) {
		std::cout << "Matrix A: [" << std::endl;;
		printArray(a, size);
		std::cout << std::endl << "]" << std::endl;
	}

	// print b if not null
	if (b != nullptr) {
		std::cout << "Matrix B: [" << std::endl;
		printArray(b, size);
		std::cout << std::endl << "]" << std::endl;
	}

	// print benchmark
	std::cout << "Benchmark: [" << std::endl;
	printArray(data, EXPERIMENT_ITERATIONS);
	std::cout << std::endl << "]" << std::endl;
}

int main(int argc, char** args) {
	int data[EXPERIMENT_ITERATIONS];

	int method = atoi(args[1]);
	int size = atoi(args[2]);
	bool isFloat = strcmp(args[3], "1") == 0;

	int* aInt = generateIntArray(size);
	int* bInt = generateIntArray(size);

	float* aFloat = gererateFloatArray(size);
	float* bFloat = gererateFloatArray(size);

	// tempsize is sqrt of size
	int* mandelbrotResult = new int[800 * 600];

	int* intResult = new int[size];
	float* floatResult = new float[size];
	int* mulRes = new int[size * size];
	float* floatMulRes = new float[size * size];

	for (int i = 0; i < EXPERIMENT_ITERATIONS; i++) {
		auto start = std::chrono::high_resolution_clock::now();

		if (method == 3) vectorizedMandelbrot(800, 600, size, mandelbrotResult); // size = iterations

		else if (isFloat == 0) {
			if (method == 0) addMatrices(aInt, bInt, size, intResult);
			if (method == 1) dotProduct(aInt, bInt, size);
			if (method == 2) multiplyMatrices(aInt, bInt, size, mulRes);
		}

		else {
			if (method == 0) addMatrices(aFloat, bFloat, size, floatResult);
			if (method == 1) dotProduct(aFloat, bFloat, size);
			if (method == 2) multiplyMatrices(aFloat, bFloat, size, floatMulRes);
		}

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		data[i] = duration.count();
	}


	if (method == 3) printResults(data, size, (int*)nullptr, (int*)nullptr);

	else if (isFloat == 0) {
		if (method == 0) printResults(data, size, aInt, bInt);
		if (method == 1) printResults(data, size, aInt, bInt);
		if (method == 2) printResults(data, size, aInt, bInt);
	}
	else {
		if (method == 0) printResults(data, size, aFloat, bFloat);
		if (method == 1) printResults(data, size, aFloat, bFloat);
		if (method == 2) printResults(data, size, aFloat, bFloat);
	}

	return 0;
}