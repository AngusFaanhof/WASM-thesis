#include <immintrin.h>
#include <iostream>

#include "../include/MatrixAddition.h"

float* addMatrices(float* matrixA, float* matrixB, int size) {
	float* matrixResult = new float[size];

	int iterations = size / 4;
	for (int i = 0; i < iterations; i++) {
		__m128 a = _mm_loadu_ps(&matrixA[i]);
		__m128 b = _mm_loadu_ps(&matrixB[i]);

		__m128 sum = _mm_add_ps(a, b);
		_mm_storeu_ps(&matrixResult[i], sum);
	}

	// remaining elements
	int remainder = size % 4;
	for (int i = size - remainder; i < size; i++) {
		matrixResult[i] = matrixA[i] + matrixB[i];
	}

	return matrixResult;
}

int* addMatrices(int* matrixA, int* matrixB, int size) {
	int* matrixResult = new int[size];

	int iterations = size / 4;
	for (int i = 0; i < iterations; i++) {
		__m128i a = _mm_loadu_si128((__m128i*)&matrixA[i * 4]);
		__m128i b = _mm_loadu_si128((__m128i*)&matrixB[i * 4]);
		__m128i sum = _mm_add_epi32(a, b);
		_mm_storeu_si128((__m128i*)&matrixResult[i * 4], sum);
	}

	// remaining elements
	int remainder = size % 4;
	for (int i = size - remainder; i < size; i++) {
		matrixResult[i] = matrixA[i] + matrixB[i];
	}

	return matrixResult;
}