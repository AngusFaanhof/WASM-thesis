#include <immintrin.h>
#include <iostream>
#include <random>

int MAX_VALUE = 10000;
int DEFAULT_ROWS = 128;
int DEFAULT_COLS = 128;

int* generateRandomMatrix(int rows, int cols) {
	int* matrix = new int[rows * cols];

	for (int i = 0; i < rows * cols; i++) {
		matrix[i] = rand() % MAX_VALUE;
	}

	return matrix;
}

int* MatrixMultiplication(int* matrixA, int rowsA, int colsA, int* matrixB, int rowsB, int colsB) {
	int* matrixResult = new int[rowsA * colsB];

	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsB; j++) {
			int indexSum = 0;
			__m128i partialSum = _mm_setzero_si128();

			for (int k = 0; k < colsA; k += 4) {
				__m128i a = _mm_loadu_si128((__m128i*)&matrixA[i * colsA + k]);
				__m128i b = _mm_loadu_si128((__m128i*)&matrixB[j * colsB + k]);

				__m128i mul = _mm_mullo_epi32(a, b);
				partialSum = _mm_add_epi32(partialSum, mul);

				// add the elements of the SIMD vector together
				partialSum = _mm_hadd_epi32(partialSum, partialSum);
				partialSum = _mm_hadd_epi32(partialSum, partialSum);

				indexSum += _mm_cvtsi128_si32(partialSum);
			}

			matrixResult[i * colsB + j] += indexSum;
		}
	}

	return matrixResult;
}


int main(int argc, char** args) {
	// seed random number generator
	srand(time(NULL));

	int rowsA = (argc > 1) ? atoi(args[1]) : DEFAULT_ROWS;
	int colsA = (argc > 2) ? atoi(args[2]) : DEFAULT_COLS;
	int rowsB = (argc > 3) ? atoi(args[3]) : DEFAULT_ROWS;
	int colsB = (argc > 4) ? atoi(args[4]) : DEFAULT_COLS;

	if (colsA != rowsB) {
		std::cout << "Matrix dimensions are not compatible for multiplication" << std::endl;
		return 1;
	}

	int* matrixA = generateRandomMatrix(rowsA, colsA);
	int* matrixB = generateRandomMatrix(rowsB, colsB);
	int* matrixResult = MatrixMultiplication(matrixA, rowsA, colsA, matrixB, rowsB, colsB);

	return 0;
}