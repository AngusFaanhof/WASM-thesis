#include <iostream>
#include <chrono>
#include <cstring>
#include <cmath>
#include <fstream>

#include "../include/helpers.h"
#include "../include/matrixAddition.h"
#include "../include/dotProduct.h"
#include "../include/matrixMultiplication.h"
#include "../include/mandelbrot.h"

int EXPERIMENT_ITERATIONS = 25;


template <typename T>
void writeToFile(int method, int isFloat, int size, T* a, T* b, int* data) {
	std::string methods[] = {"matrixAddition", "dotProduct","matrixMultiplication", "mandelbrot"};
	std::string f = (isFloat == 0) ? "i" : "f";

	std::string filename = "results/" + methods[method] + "/" + f + "_" + std::to_string(size) + ".txt";
	std::string dataFile = "testData/" + methods[method] + "/" + f + "_" + std::to_string(size) + ".txt";

	if (method != 3) {
		std::ofstream file(dataFile);

		file << "A:" << std::endl;
		for (int i = 0; i < size - 1; i++) {
			file << a[i] << ",";
		}
		file << a[size - 1] << std::endl;

		file << "B:" << std::endl;
		for (int i = 0; i < size - 1; i++) {
			file << b[i] << ",";
		}
		file << b[size - 1] << std::endl;
		file.close();
	}

	std::ofstream file(filename);

	for (int i = 0; i < EXPERIMENT_ITERATIONS - 1; i++) {
		file << data[i] << ",";
	}
	file << data[EXPERIMENT_ITERATIONS - 1] << std::endl;
	file.close();
}

int main(int argc, char** args) {
	int data[EXPERIMENT_ITERATIONS];

	int method = atoi(args[1]);
	int size = atoi(args[2]);
	bool isFloat = strcmp(args[3], "1") == 0;

	int* aInt = generateIntArray(size * size);
	int* bInt = generateIntArray(size * size);

	float* aFloat = gererateFloatArray(size * size);
	float* bFloat = gererateFloatArray(size * size);

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

	if (method == 3) writeToFile(method, isFloat, size, aInt, bInt, data);

	else if (isFloat == 0) {
		if (method == 0) writeToFile(method, isFloat, size, aInt, bInt, data);
		if (method == 1) writeToFile(method, isFloat, size, aInt, bInt, data);
		if (method == 2) writeToFile(method, isFloat, size, aInt, bInt, data);
	}
	else {
		if (method == 0) writeToFile(method, isFloat, size, aFloat, bFloat, data);
		if (method == 1) writeToFile(method, isFloat, size, aFloat, bFloat, data);
		if (method == 2) writeToFile(method, isFloat, size, aFloat, bFloat, data);
	}

	return 0;
}