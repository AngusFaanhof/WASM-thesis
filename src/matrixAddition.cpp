#include <immintrin.h>

#include "../include/matrixAddition.h"

void addMatrices(float* matrixA, float* matrixB, int size, float* matrixResult) {
	for (int i = 0; i < size; i += 4) {
		__m128 a = _mm_loadu_ps(&matrixA[i]);
		__m128 b = _mm_loadu_ps(&matrixB[i]);

		__m128 sum = _mm_add_ps(a, b);
		_mm_storeu_ps(&matrixResult[i], sum);
	}
}

void addMatrices(int* matrixA, int* matrixB, int size, int* matrixResult) {
	for (int i = 0; i < size; i += 4) {
		__m128i a = _mm_loadu_si128((__m128i*)&matrixA[i]);
		__m128i b = _mm_loadu_si128((__m128i*)&matrixB[i]);

		__m128i sum = _mm_add_epi32(a, b);
		_mm_storeu_si128((__m128i*)&matrixResult[i], sum);
	}
}