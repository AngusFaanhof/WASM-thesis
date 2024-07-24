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
		16, 32, 64
	};

	for (auto size : sizes) {
		MatrixF dataFA(size, size, generateRandomVector<float>(size * size, 0.0f, 1.0f));
		MatrixF dataFB(size, size, generateRandomVector<float>(size * size, 0.0f, 1.0f));
		MatrixI dataIA(size, size, generateRandomVector<int>(size * size, 0, 1000));
		MatrixI dataIB(size, size, generateRandomVector<int>(size * size, 0, 1000));

		// Benchmark transposeMatrix (float)
		benchmarkAndSave("transposeMatrix", "float", size,
			[&dataFA]() { return transposeMatrix(dataFA); });

		// Benchmark transposeMatrix (int)
		benchmarkAndSave("transposeMatrix", "int", size,
			[&dataIA]() { return transposeMatrix(dataIA); });

		// Benchmark multiplyMatrices (float)
		benchmarkAndSave("multiplyMatrices", "float", size,
			[&dataFA, &dataFB]() { return multiplyMatrices(dataFA, dataFB); });

		// Benchmark multiplyMatrices (int)
		benchmarkAndSave("multiplyMatrices", "int", size,
			[&dataIA, &dataIB]() { return multiplyMatrices(dataIA, dataIB); });
	}

	return 0;
}