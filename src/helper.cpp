#include <random>
#include <iostream>

#include "../include/helpers.h"

void printArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		if (i == size - 1)
			std::cout << array[i];
		else
			std::cout << array[i] << ",";
	}

}

void printArray(float* array, int size) {
	for (int i = 0; i < size; i++) {
		if (i == size - 1)
			std::cout << array[i];
		else
			std::cout << array[i] << ",";
	}

}

int* generateIntArray(int size) {
	int* array = new int[size];
	std::mt19937 rng(time(NULL));
	std::uniform_int_distribution<int> dist(0, 1000);

	for (int i = 0; i < size; i++) {
		array[i] = dist(rng);
	}

	return array;
}

float* gererateFloatArray(int size) {
	float* array = new float[size];
	std::mt19937 rng(time(NULL));
	std::uniform_real_distribution<float> dist(0.0f, 1.0f);

	for (int i = 0; i < size; i++) {
		array[i] = dist(rng);
	}

	return array;
}

// void printResults(int* data, int size, int* a = nullptr, int* b = nullptr) {
// 	std::cout << "Size: " << size << std::endl;

// 	// print a if not null
// 	if (a != nullptr) {
// 		std::cout << "Matrix A: [" << std::endl;;
// 		printArray(a, size);
// 		std::cout << std::endl << "]" << std::endl;
// 	}

// 	// print b if not null
// 	if (b != nullptr) {
// 		std::cout << "Matrix B: [" << std::endl;
// 		printArray(b, size);
// 		std::cout << std::endl << "]" << std::endl;
// 	}

// 	// print benchmark
// 	std::cout << "Benchmark: [" << std::endl;
// 	printArray(data, EXPERIMENT_ITERATIONS);
// 	std::cout << std::endl << "]" << std::endl;
// }

// void printResults(int* data, int size, float* a = nullptr, float* b = nullptr) {
// 	std::cout << "Size: " << size << std::endl;

// 	// print a if not null
// 	if (a != nullptr) {
// 		std::cout << "Matrix A: [" << std::endl;;
// 		printArray(a, size);
// 		std::cout << std::endl << "]" << std::endl;
// 	}

// 	// print b if not null
// 	if (b != nullptr) {
// 		std::cout << "Matrix B: [" << std::endl;
// 		printArray(b, size);
// 		std::cout << std::endl << "]" << std::endl;
// 	}

// 	// print benchmark
// 	std::cout << "Benchmark: [" << std::endl;
// 	printArray(data, EXPERIMENT_ITERATIONS);
// 	std::cout << std::endl << "]" << std::endl;
// }