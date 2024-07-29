#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <functional>
#include <string>

#include "../utils.hpp"
#include "../matrix_algorithms.hpp"
#include "../benchmark_base.hpp"

// # algorithms
// transposeMatrix(MatrixF& m) [float / int]
// - MatrixF res = transposeMatrix(MatrixF& m)
// - MatrixI res = transposeMatrix(MatrixI& m)
// multiplyMatrices(MatrixF& A, MatrixF& B) [float / int]
// - MatrixF res = multiplyMatrices(MatrixF& A, MatrixF& B)
// - MatrixI res = multiplyMatrices(MatrixI& A, MatrixI& B)

int main() {
	std::vector<size_t> sizes = {
		4, 8
	};

	std::vector<std::vector<float>> floatMatricesA;
    std::vector<std::vector<float>> floatMatricesB;
    std::vector<std::vector<int>> intMatricesA;
    std::vector<std::vector<int>> intMatricesB;

	std::cout << "Matrix algorithms" << std::endl;

	for (int i = 0; i < sizes.size(); i++) {
		size_t size = sizes.at(i);

		std::vector<float> matrixFA = generateRandomVector<float>(size * size, 0.0f, 1.0f);
		std::vector<float> matrixFB = generateRandomVector<float>(size * size, 0.0f, 1.0f);
		std::vector<int> matrixIA = generateRandomVector<int>(size * size, 0, 1000);
		std::vector<int> matrixIB = generateRandomVector<int>(size * size, 0, 1000);

		floatMatricesA.push_back(matrixFA);
        floatMatricesB.push_back(matrixFB);
        intMatricesA.push_back(matrixIA);
        intMatricesB.push_back(matrixIB);

		// Benchmark transposeMatrix (float)
		benchmarkAndSave("transposeMatrix", "float", size,
			[&matrixFA, size]() { return transposeMatrix(matrixFA, size); });

		// Benchmark transposeMatrix (int)
		benchmarkAndSave("transposeMatrix", "int", size,
			[&matrixIA, size]() { return transposeMatrix(matrixIA, size); });

		// Benchmark multiplyMatrices (float)
		benchmarkAndSave("multiplyMatrices", "float", size,
			[&matrixFA, &matrixFB, size]() { return multiplyMatrices(matrixFA, matrixFB, size); });

		// Benchmark multiplyMatrices (int)
		benchmarkAndSave("multiplyMatrices", "int", size,
			[&matrixIA, &matrixIB, size]() { return multiplyMatrices(matrixIA, matrixIB, size); });
	}

	std::cout << "Test data: " << std::endl;

	// print floatMatricesA
	std::cout << "floatMatricesA: " << std::endl;
	for (int i = 0; i < floatMatricesA.size(); i++) {
		std::cout << "size: " << sizes.at(i) << std::endl;

		printMatrix(floatMatricesA.at(i), sizes.at(i));
	}

	// print floatMatricesB
	std::cout << "floatMatricesB: " << std::endl;
	for (int i = 0; i < floatMatricesB.size(); i++) {
		std::cout << "size: " << sizes.at(i) << std::endl;

		printMatrix(floatMatricesB.at(i), sizes.at(i));
	}

	// print intMatricesA
	std::cout << "intMatricesA: " << std::endl;
	for (int i = 0; i < intMatricesA.size(); i++) {
		std::cout << "size: " << sizes.at(i) << std::endl;

		printMatrix(intMatricesA.at(i), sizes.at(i));
	}

	// print intMatricesB
	std::cout << "intMatricesB: " << std::endl;
	for (int i = 0; i < intMatricesB.size(); i++) {
		std::cout << "size: " << sizes.at(i) << std::endl;

		printMatrix(intMatricesB.at(i), sizes.at(i));
	}

	return 0;
}