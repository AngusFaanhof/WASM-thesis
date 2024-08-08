#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <functional>
#include <string>

#include "../../include/utils.hpp"
#include "../../include/matrix_algorithms.hpp"
#include "../../include/benchmark_base.hpp"

// # algorithms
// transposeMatrix(MatrixF& m) [float / int]
// - MatrixF res = transposeMatrix(MatrixF& m)
// - MatrixI res = transposeMatrix(MatrixI& m)
// multiplyMatrices(MatrixF& A, MatrixF& B) [float / int]
// - MatrixF res = multiplyMatrices(MatrixF& A, MatrixF& B)
// - MatrixI res = multiplyMatrices(MatrixI& A, MatrixI& B)

int main() {
	// squared sizes = 16, 256, 4096, 65536, 1048576
	std::vector<size_t> sizes = {
		4,
		16,
		64,
		256,
		512
	};

	std::cout << "Matrix benchmarks" << std::endl;

	for (auto size : sizes) {
		std::vector<float> matrixFA = generateRandomVector<float>(size * size, 0.0f, 1.0f);
		std::vector<float> matrixFB = generateRandomVector<float>(size * size, 0.0f, 1.0f);
		std::vector<int> matrixIA = generateRandomVector<int>(size * size, 0, 1000);
		std::vector<int> matrixIB = generateRandomVector<int>(size * size, 0, 1000);

		std::cout << std::endl;
		std::cout << "Size: " << size << std::endl;

		std::cout << "Test data: " << std::endl;
		std::cout << "Float Matrix A: " << std::endl;
		printMatrix(matrixFA);

		std::cout << "Float Matrix B: " << std::endl;
		printMatrix(matrixFB);

		std::cout << "Int Matrix A: " << std::endl;
		printMatrix(matrixIA);

		std::cout << "Int Matrix B: " << std::endl;
		printMatrix(matrixIB);


		std::cout << std::endl;
		std::cout << "Execution times: " << std::endl;

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


	return 0;
}