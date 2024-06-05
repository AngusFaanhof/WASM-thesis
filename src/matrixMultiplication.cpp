#include <immintrin.h>
#include <iostream>

#include "../include/matrixMultiplication.h"

void multiplyMatrices(int* matrixA, int* matrixB, int rowsCols, int* matrixResult) {
	int rowsA = rowsCols, colsA = rowsCols, rowsB = rowsCols, colsB = rowsCols;
	int iterations = colsA / 4;

	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsB; j++) {
			int indexSum = 0;
			__m128i partialSum = _mm_setzero_si128();
			for (int k = 0; k < iterations; k++) {
				// std::cout << i << "," << j << "," << k << std::endl;
				__m128i a = _mm_loadu_si128((__m128i*)&matrixA[i * colsA + k * 4]);
				__m128i b = _mm_loadu_si128((__m128i*)&matrixB[j * colsB + k * 4]);
				// std::cout << "reached after" << std::endl;
				__m128i mul = _mm_mullo_epi32(a, b);
				partialSum = _mm_add_epi32(partialSum, mul);

				// add the elements of the SIMD vector together
				partialSum = _mm_hadd_epi32(partialSum, partialSum);
				partialSum = _mm_hadd_epi32(partialSum, partialSum);

				indexSum += _mm_cvtsi128_si32(partialSum);
			}

			int remainder = colsA % 4;
			for (int k = colsA - remainder; k < colsA; k++) {
				indexSum += matrixA[i * colsA + k] * matrixB[k * colsB + j];
			}

			matrixResult[i * colsB + j] += indexSum;
		}
	}


}

void multiplyMatrices(float* matrixA, float* matrixB, int rowsCols, float* matrixResult) {
	int rowsA = rowsCols, colsA = rowsCols, rowsB = rowsCols, colsB = rowsCols;

	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsB; j++) {
			float indexSum = 0;
			__m128 partialSum = _mm_setzero_ps();

			int iterations = colsA / 4;
			for (int k = 0; k < iterations; k++) {
				__m128 a = _mm_loadu_ps(&matrixA[i * colsA + k * 4]);
				__m128 b = _mm_loadu_ps(&matrixB[j * colsB + k * 4]);

				__m128 mul = _mm_mul_ps(a, b);
				partialSum = _mm_add_ps(partialSum, mul);

				// add the elements of the SIMD vector together
				partialSum = _mm_hadd_ps(partialSum, partialSum);
				partialSum = _mm_hadd_ps(partialSum, partialSum);

				indexSum += _mm_cvtss_f32(partialSum);
			}

			int remainder = colsA % 4;
			for (int k = colsA - remainder; k < colsA; k++) {
				indexSum += matrixA[i * colsA + k] * matrixB[k * colsB + j];
			}

			matrixResult[i * colsB + j] += indexSum;
		}
	}
}