#include <immintrin.h>
#include <iostream>
#include <cmath>

#include "../include/matrixMultiplication.h"

void multiplyMatrices(int* matrixA, int* matrixB, int size, int* matrixResult) {
	int rows = sqrt(size);
	int cols = rows;
	int iterations = rows / 4; // iterations per row

	for (int aI = 0; aI < rows; aI++) {
		for (int bI = 0; bI < cols; bI++) {

			int indexSum = 0;
			// __m128i sum = _mm_setzero_si128();
			for (int k = 0; k < iterations; k++) {
				__m128i a = _mm_load_si128((__m128i*)&matrixA[(aI + k) * 4]);
				__m128i b = _mm_load_si128((__m128i*)&matrixB[(bI + k) * 4]); // assume b is transposed

				__m128i mul = _mm_mullo_epi32(a, b);

				int* regValues = (int*)&mul;
				indexSum += regValues[0] + regValues[1] + regValues[2] + regValues[3];
			}

			matrixResult[aI * rows + bI] = indexSum;
		}
	}
}

void multiplyMatrices(float* matrixA, float* matrixB, int size, float* matrixResult) {
	int rows = sqrt(size);
	int cols = rows;
	int iterations = rows / 4; // iterations per row

	for (int aI = 0; aI < rows; aI++) {
		for (int bI = 0; bI < cols; bI++) {

			int indexSum = 0;
			for (int k = 0; k < iterations; k++) {
				__m128 a = _mm_loadu_ps(&matrixA[(aI + k) * 4]);
				__m128 b = _mm_loadu_ps(&matrixB[(bI + k) * 4]);

				__m128 mul = _mm_mul_ps(a, b);

				float* regValues = (float*)&mul;
				indexSum += regValues[0] + regValues[1] + regValues[2] + regValues[3];
			}

			matrixResult[aI * rows + bI] = indexSum;
		}
	}
}

