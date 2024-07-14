#include <immintrin.h>

#include "../include/dotProduct.h"

float dotProduct(float* a, float* b, int size) {
	float result = 0;

	for (int i = 0; i < size; i += 4) {
		__m128 aVec = _mm_loadu_ps(&a[i]);
		__m128 bVec = _mm_loadu_ps(&b[i]);

		__m128 mul = _mm_mul_ps(aVec, bVec);

		float* regValues = (float*)&mul;
		result += regValues[0] + regValues[1] + regValues[2] + regValues[3];
	}

	return result;
}

int dotProduct(int* a, int* b, int size) {
	int result = 0;

	for (int i = 0; i < size; i += 4) {
		__m128i aVec = _mm_loadu_si128((__m128i*)&a[i]);
		__m128i bVec = _mm_loadu_si128((__m128i*)&b[i]);

		__m128i mul = _mm_mullo_epi32(aVec, bVec);

		int* regValues = (int*) &mul;
		result += regValues[0] + regValues[1] + regValues[2] + regValues[3];
	}

	return result;
}