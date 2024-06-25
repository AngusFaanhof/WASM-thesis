#include <iostream>
#include <chrono>
#include <cstring>
#include <cmath>
#include <fstream>
#include <sstream>

#include "../include/helpers.h"
#include "../include/matrixAddition.h"
#include "../include/dotProduct.h"
#include "../include/matrixMultiplication.h"
#include "../include/mandelbrot.h"

int EXPERIMENT_ITERATIONS = 25;

template <typename T>
void readFromFile(int method, int isFloat, int size, T* a, T* b) {
	std::string methods[] = {"matrixAddition", "dotProduct","matrixMultiplication", "mandelbrot"};
	std::string f = (isFloat == 0) ? "i" : "f";

	std::string filename = "testData/" + methods[method] + "/" + f + "_" + std::to_string(size) + ".txt";

	std::ifstream file(filename);
	std::string line;

	// read A:
	std::getline(file, line);
	std::getline(file, line);
	std::istringstream iss(line);

	int num;
	int i = 0;
	while (iss >> num) {
		if (iss.peek() == ',') iss.ignore();

		a[i] = num;
		i++;
	}

	// read B:
	std::getline(file, line);
	std::getline(file, line);
	std::istringstream iss2(line);

	i = 0;
	while (iss2 >> num) {
		if (iss2.peek() == ',') iss2.ignore();

		b[i] = num;
		i++;
	}

	file.close();
}

void printResults(long long* data) {
	for (int i = 0; i < EXPERIMENT_ITERATIONS - 1; i++) {
		std::cout << data[i] << ",";
	}
	std::cout << data[EXPERIMENT_ITERATIONS - 1] << std::endl;
}

void floatOperations(int method, int size, long long* data) {
	float* a = new float[size];
	float* b = new float[size];

	readFromFile(method, 1, size, a, b);

	float* floatResult = new float[size];

	for (int i = 0; i < EXPERIMENT_ITERATIONS; i++) {
		auto start = std::chrono::high_resolution_clock::now();

		if (method == 0 || method == 2) addMatrices(a, b, size, floatResult);
		if (method == 1) dotProduct(a, b, size);
		if (method == 2) multiplyMatrices(a, b, size, floatResult);

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		data[i] = duration.count();
	}
}

void intOperations(int method, int size, long long* data) {
	int* a = new int[size];
	int* b = new int[size];

	readFromFile(method, 0, size, a, b);

	int* intResult = new int[size];

	for (int i = 0; i < EXPERIMENT_ITERATIONS; i++) {
		auto start = std::chrono::high_resolution_clock::now();

		if (method == 0) addMatrices(a, b, size, intResult);
		if (method == 1) dotProduct(a, b, size);
		if (method == 2) multiplyMatrices(a, b, size, intResult);

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		data[i] = duration.count();
	}
}

void mandelbrotOperation(int size, long long* data) {
	int* mandelbrotResult = new int[800 * 600];
	for (int i = 0; i < EXPERIMENT_ITERATIONS; i++) {
		auto start = std::chrono::high_resolution_clock::now();

		vectorizedMandelbrot(800, 600, size, mandelbrotResult);

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		data[i] = duration.count();
	}
}

int main(int argc, char** args) {
	long long* data = new long long[EXPERIMENT_ITERATIONS];

	int method = atoi(args[1]);
	int size = atoi(args[2]);
	bool isFloat = strcmp(args[3], "1") == 0;

	if (method == 3) {
		mandelbrotOperation(size, data);
	} else if (isFloat == 0) {
		intOperations(method, size, data);
	} else {
		floatOperations(method, size, data);
	}

	printResults(data);

	return 0;
}