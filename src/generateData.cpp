#include <iostream>
#include <chrono>
#include <cstring>
#include <cmath>
#include <fstream>
#include <sstream>

#include "../include/helpers.h"

template <typename T>
void writeToFile(int method, int isFloat, int size, T* a, T* b) {
	std::string methods[] = {"matrixAddition", "dotProduct","matrixMultiplication", "mandelbrot"};
	std::string f = (isFloat == 0) ? "i" : "f";

	std::string filename = "testData/" + methods[method] + "/" + f + "_" + std::to_string(size) + ".txt";

	if (method != 3) {
		std::ofstream file(filename);

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
}

int main(int argc, char** args) {
	int method = atoi(args[1]);
	int size = atoi(args[2]);
	bool isFloat = strcmp(args[3], "1") == 0;

	int* aInt = generateIntArray(size);
	int* bInt = generateIntArray(size);

	float* aFloat = gererateFloatArray(size);
	float* bFloat = gererateFloatArray(size);

	if (isFloat == 0) writeToFile(method, isFloat, size, aInt, bInt);
	else writeToFile(method, isFloat, size, aFloat, bFloat);


	return 0;
}