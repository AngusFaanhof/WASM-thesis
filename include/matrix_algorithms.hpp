#ifndef MATRIX_ALGORITHMS_HPP
#define MATRIX_ALGORITHMS_HPP

#include <vector>
#include <cstddef>
#include <iostream>

template <typename T>
void printMatrix(const std::vector<T>& matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		if (i == matrix.size() - 1)
			std::cout << matrix[i];
		else
			std::cout << matrix[i] << ",";
	}
	std::cout << std::endl;
}

std::vector<float> transposeMatrix(const std::vector<float>& m, size_t rowsCols);

std::vector<int> transposeMatrix(const std::vector<int>& m, size_t rowsCols);

std::vector<float> multiplyMatrices(const std::vector<float>& A, const std::vector<float>& B, size_t rowsCols);

std::vector<int> multiplyMatrices(const std::vector<int>& A, const std::vector<int>& B, size_t rowsCols);

#endif // MATRIX_ALGORITHMS_HPP
