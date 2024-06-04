#include <immintrin.h>

#include "../include/dotProduct.h"

float dotProduct(float* a, float* b, int size) {
	__m128 partialSum = _mm_setzero_ps();

	int iterations = size / 4;
	for (int i = 0; i < iterations; i++) {
		__m128 aVec = _mm_loadu_ps(&a[i]);
		__m128 bVec = _mm_loadu_ps(&b[i]);

		__m128 mul = _mm_mul_ps(aVec, bVec);
		partialSum = _mm_add_ps(partialSum, mul);
	}

	// collapse the SIMD vector into a single float
	partialSum = _mm_hadd_ps(partialSum, partialSum);
	partialSum = _mm_hadd_ps(partialSum, partialSum);

	float result = _mm_cvtss_f32(partialSum);

	// remaining elements
	int remainder = size % 4;
	for (int i = size - remainder; i < size; i++) {
		result += a[i] * b[i];
	}

	return result;
}

int dotProduct(int* a, int* b, int size) {
	__m128i partialSum = _mm_setzero_si128();

	int iterations = size / 4;
	for (int i = 0; i < iterations; i++) {
		__m128i aVec = _mm_loadu_si128((__m128i*)&a[i]);
		__m128i bVec = _mm_loadu_si128((__m128i*)&b[i]);

		__m128i mul = _mm_mullo_epi32(aVec, bVec);
		partialSum = _mm_add_epi32(partialSum, mul);
	}

	// collapse the SIMD vector into a single int
	partialSum = _mm_hadd_epi32(partialSum, partialSum);
	partialSum = _mm_hadd_epi32(partialSum, partialSum);

	int result = _mm_cvtsi128_si32(partialSum);

	// remaining elements
	int remainder = size % 4;
	for (int i = size - remainder; i < size; i++) {
		result += a[i] * b[i];
	}

	return _mm_cvtsi128_si32(partialSum);

}