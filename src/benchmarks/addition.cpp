#include <immintrin.h>
#include <iostream>
#include <chrono>

// #include "../include/matrixAddition.h"

void addition(float* a, float* b, int size, float* result) {
	for (int i = 0; i < size; i += 4) {
		__m128 vecA = _mm_loadu_ps(&a[i]);
		__m128 vecB = _mm_loadu_ps(&b[i]);

		__m128 sum = _mm_add_ps(vecA, vecB);
		_mm_storeu_ps(&result[i], sum);
	}
}

void addition(int* a, int* b, int size, int* result) {
	for (int i = 0; i < size; i += 4) {
		__m128i vecA = _mm_loadu_si128((__m128i*)&a[i]);
		__m128i vecB = _mm_loadu_si128((__m128i*)&b[i]);

		__m128i sum = _mm_add_epi32(vecA, vecB);
		_mm_storeu_si128((__m128i*)&result[i], sum);
	}
}

int main() {
	int sizes = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};

	for (int i = 0; i < sizes.size(); i++) {
		int size = sizes[i];

		float* a = new float[size];
		float* b = new float[size];
		float* result = new float[size];

		for (int j = 0; j < size; j++) {
			a[j] = 1.0f;
			b[j] = 2.0f;
		}

		// start timer
		auto start = std::chrono::high_resolution_clock::now();
		addition(a, b, size, result);
		auto end = std::chrono::high_resolution_clock::now();

		delete[] a;
		delete[] b;
		delete[] result;
	}


}