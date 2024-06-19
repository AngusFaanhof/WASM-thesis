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

void writeToFile(int method, int isFloat, int size, int* data) {
	// std::string methods[] = {"matrixAddition", "dotProduct","matrixMultiplication", "mandelbrot"};
	// std::string f = (isFloat == 0) ? "i" : "f";

	// std::string filename = "results/" + methods[method] + "/" + f + "_" + std::to_string(size) + ".txt";
	// // std::ofstream file(filename);

	for (int i = 0; i < EXPERIMENT_ITERATIONS - 1; i++) {
		std::cout << data[i] << ",";
	}
	std::cout << data[EXPERIMENT_ITERATIONS - 1] << std::endl;

	// file.close();
}

int main(int argc, char** args) {
	int data[EXPERIMENT_ITERATIONS];

	int method = atoi(args[1]);
	int size = atoi(args[2]);
	bool isFloat = strcmp(args[3], "1") == 0;

	int* aInt = new int[size];
	int* bInt = new int[size];

	float* aFloat = new float[size];
	float* bFloat = new float[size];

	if (method == 3) int a = 1;
	else if (isFloat == 0) readFromFile(method, isFloat, size, aInt, bInt);
	else readFromFile(method, isFloat, size, aFloat, bFloat);

	int* mandelbrotResult = new int[800 * 600];

	int* intResult = new int[size];
	float* floatResult = new float[size];
	int* mulRes = new int[size];
	float* floatMulRes = new float[size];

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

	if (method == 3) writeToFile(method, isFloat, size, data);
	else if (isFloat == 0) writeToFile(method, isFloat, size, data);
	else writeToFile(method, isFloat, size, data);

	return 0;
}