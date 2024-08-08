#include <iostream>
#include <vector>

// include mandelbrot, matrix_algorithms, vector_algorithms
#include "../include/mandelbrot.hpp"
#include "../include/matrix_algorithms.hpp"
#include "../include/vector_algorithms.hpp"

/* METHOD CALLS
mandelbrot(800, 600, 16);
transposeMatrix(std::vector<float>(16 * 16, 1.0f), 16);
transposeMatrix(std::vector<int>(16 * 16, 1), 16);
multiplyMatrix(std::vector<float>(16 * 16, 1.0f), std::vector<float>(16 * 16, 1.0f), 16);
multiplyMatrix(std::vector<int>(16 * 16, 1), std::vector<int>(16 * 16, 1), 16);
normalizeVector(std::vector<float>(16, 1.0f));
normalizeVector(std::vector<int>(16, 1));
averageVector(std::vector<float>(16, 1.0f));
averageVector(std::vector<int>(16, 1));
dotProduct(std::vector<float>(16, 1.0f), std::vector<float>(16, 1.0f));
dotProduct(std::vector<int>(16, 1), std::vector<int>(16, 1));
vectorAddition(std::vector<float>(16, 1.0f), std::vector<float>(16, 1.0f));
vectorAddition(std::vector<int>(16, 1), std::vector<int>(16, 1));
*/

int main() {
	std::vector<int> intVector(16, 1);
	std::vector<float> floatVector(16, 1.0f);

	std::vector<int> mandelbrotResult = mandelbrot(800, 600, 16);
	std::vector<float> transposedFloatMatrix = transposeMatrix(floatVector, 4);
	std::vector<int> transposedIntMatrix = transposeMatrix(intVector, 4);
	std::vector<float> multipliedFloatMatrix = multiplyMatrices(floatVector, floatVector, 4);
	std::vector<int> multipliedIntMatrix = multiplyMatrices(intVector, intVector, 4);
	std::vector<float> normalizedFloatVector = normalizeVector(floatVector);
	std::vector<float> normalizedIntVector = normalizeVector(intVector);
	float averageFloat = averageVector(floatVector);
	float averageInt = averageVector(intVector);
	float dotProductFloat = dotProduct(floatVector, floatVector);
	int dotProductInt = dotProduct(intVector, intVector);
	std::vector<float> addedFloatVector = vectorAddition(floatVector, floatVector);
	std::vector<int> addedIntVector = vectorAddition(intVector, intVector);

	return 0;
}