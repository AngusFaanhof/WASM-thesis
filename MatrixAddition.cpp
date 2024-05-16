#include <immintrin.h>
#include <iostream>
#include <random>

float MAX_VALUE = 1.0f;

float* MatrixAddition(float* matrixA, float* matrixB, int size) {
	float* matrixResult = new float[size];

	for (int i = 0; i < size; i += 4) {
		__m128 a = _mm_loadu_ps(&matrixA[i]);
		__m128 b = _mm_loadu_ps(&matrixB[i]);

		__m128 sum = _mm_add_ps(a, b);
		_mm_storeu_ps(&matrixResult[i], sum);
	}

	return matrixResult;
}

int* MatrixAddition(int* matrixA, int* matrixB, int size) {
	int* matrixResult = new int[size];

	for (int i = 0; i < size; i += 4) {
		__m128i a = _mm_loadu_si128((__m128i*)&matrixA[i]);
		__m128i b = _mm_loadu_si128((__m128i*)&matrixB[i]);

		__m128i sum = _mm_add_epi32(a, b);
		_mm_storeu_si128((__m128i*)&matrixResult[i], sum);
	}

	return matrixResult;
}

int main(int argc, char* argv[]) {
	int size = 128;

	// size provided as argument
	if (argc > 1)
		size = std::stoi(argv[1]);

	// using Mersenne Twister for random number generation
	std::mt19937 rng(time(NULL));
	std::uniform_real_distribution<float> dist(0.0f, MAX_VALUE);

	float* matrixA = new float[size];
	float* matrixB = new float[size];

	for (int i = 0; i < size; i++) {
		matrixA[i] = dist(rng);
		matrixB[i] = dist(rng);
	}

	float* resultMatrix = MatrixAddition(matrixA, matrixB, size);

	return 0;
}