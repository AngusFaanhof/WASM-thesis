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
void readFromFile(int method, int isFloat, int size, T** a, T** b) {
	T* newA = new T[size * size];
	T* newB = new T[size * size];

	std::string methods[] = {"matrixAddition", "dotProduct","matrixMultiplication", "mandelbrot"};
	std::string f = (isFloat == 0) ? "i" : "f";

	std::string filename = "testData/" + methods[method] + "/" + f + "_" + std::to_string(size) + ".txt";

	std::ifstream file(filename);

	std::string line;
	int i = 0;
	while (std::getline(file, line)) {
		if (line == "A:") {
			std::getline(file, line);
			std::stringstream ss(line);
			std::string token;
			while (std::getline(ss, token, ',')) {
				newA[i] = isFloat ? std::stof(token) : std::stoi(token);
				i++;
			}
		}

		else if (line == "B:") {
			std::getline(file, line);
			std::stringstream ss(line);
			std::string token;
			while (std::getline(ss, token, ',')) {
				newB[i] = isFloat ? std::stof(token) : std::stoi(token);
				i++;
			}
		}
	}

	*a = newA;
	*b = newB;
}

void writeToFile(int method, int isFloat, int size, int* data) {
	std::string methods[] = {"matrixAddition", "dotProduct","matrixMultiplication", "mandelbrot"};
	std::string f = (isFloat == 0) ? "i" : "f";

	std::string filename = "results/" + methods[method] + "/" + f + "_" + std::to_string(size) + ".txt";
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

	int* aInt = nullptr;
	int* bInt = nullptr;
	float* aFloat = nullptr;
	float* bFloat = nullptr;

	readFromFile(method, isFloat, size, &aInt, &bInt);
	readFromFile(method, isFloat, size, &aFloat, &bFloat);

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

	if (method == 3) writeToFile(method, isFloat, size, data);
	else if (isFloat == 0) writeToFile(method, isFloat, size, data);
	else writeToFile(method, isFloat, size, data);

	return 0;
}