#ifndef MATRIX_ALGORITHMS_HPP
#define MATRIX_ALGORITHMS_HPP

#include <vector>
#include <cstddef>
#include <iostream>

template <typename T>
void printMatrix(const std::vector<T>& matrix, size_t size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << matrix.at(i * size + j) << ",";
		}
		std::cout << std::endl;
	}
}

std::vector<float> transposeMatrix(const std::vector<float>& m, size_t rowsCols);

std::vector<int> transposeMatrix(const std::vector<int>& m, size_t rowsCols);

std::vector<float> multiplyMatrices(const std::vector<float>& A, const std::vector<float>& B, size_t rowsCols);

std::vector<int> multiplyMatrices(const std::vector<int>& A, const std::vector<int>& B, size_t rowsCols);

#endif // MATRIX_ALGORITHMS_HPP
