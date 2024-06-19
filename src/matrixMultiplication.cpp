#include <immintrin.h>
#include <iostream>
#include <cmath>

#include "../include/matrixMultiplication.h"

void multiplyMatrices(int* matrixA, int* matrixB, int rowsCols, int* matrixResult) {
	int rows = sqrt(rowsCols);
	int iterations = rows / 4;

	for (int aI = 0; aI < rows; aI++) {
		for (int bI = 0; bI < rows; bI++) {

			int indexSum = 0;
			for (int k = 0; k < iterations; k++) {
				__m128i a = _mm_load_si128((__m128i*)&matrixA[(aI + k) * 4]);
				__m128i b = _mm_load_si128((__m128i*)&matrixB[(bI + k) * 4]);

				__m128i mul = _mm_mullo_epi32(a, b);

				__m128i partialSum = _mm_setzero_si128();
				partialSum = _mm_add_epi32(partialSum, mul);

				partialSum = _mm_hadd_epi32(partialSum, partialSum);
				partialSum = _mm_hadd_epi32(partialSum, partialSum);

				indexSum += _mm_cvtsi128_si32(partialSum);
			}

			matrixResult[aI * rows + bI] = indexSum;
		}
	}
}

void multiplyMatrices(float* matrixA, float* matrixB, int rowsCols, float* matrixResult) {
	int rows = sqrt(rowsCols);
	int iterations = rows / 4;

	for (int aI = 0; aI < rows; aI++) {
		for (int bI = 0; bI < rows; bI++) {

			int indexSum = 0;
			for (int k = 0; k < iterations; k++) {
				__m128 a = _mm_loadu_ps(&matrixA[(aI + k) * 4]);
				__m128 b = _mm_loadu_ps(&matrixB[(bI + k) * 4]);

				__m128 mul = _mm_mul_ps(a, b);

				__m128 partialSum = _mm_setzero_ps();
				partialSum = _mm_add_ps(partialSum, mul);

				partialSum = _mm_hadd_ps(partialSum, partialSum);
				partialSum = _mm_hadd_ps(partialSum, partialSum);

				indexSum += _mm_cvtss_f32(partialSum);
			}

			matrixResult[aI * rows + bI] = indexSum;
		}
	}
}