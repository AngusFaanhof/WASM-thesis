#include <immintrin.h>
#include <iostream>
#include <random>

int MAX_VALUE = 100;

float dotProduct(float* a, float* b, int size) {
	__m128 partialSum = _mm_setzero_ps();

	for (int i = 0; i < size; i += 4) {
		__m128 aVec = _mm_loadu_ps(&a[i]);
		__m128 bVec = _mm_loadu_ps(&b[i]);

		__m128 mul = _mm_mul_ps(aVec, bVec);
		partialSum = _mm_add_ps(partialSum, mul);
	}

	// collapse the SIMD vector into a single float
	partialSum = _mm_hadd_ps(partialSum, partialSum);
	partialSum = _mm_hadd_ps(partialSum, partialSum);

	return _mm_cvtss_f32(partialSum);
}

// int main(int argc, char* argv[]) {
// 	// seed random number generator
// 	srand(time(NULL));

// 	int size;
// 	if (argc > 1) {
// 		size = std::stoi(argv[1]);
// 		if (size <= 0) {
// 			std::cout << "Invalid size argument. Using default size: " << size << std::endl;
// 			size = 8;
// 		}
// 	}

// 	float* a = new float[size];
// 	float* b = new float[size];

// 	for (int i = 0; i < size; i++) {
// 		a[i] = static_cast<float>(rand() % MAX_VALUE);
// 		b[i] = static_cast<float>(rand() % MAX_VALUE);
// 	}

// 	float result = dotProduct(a, b, size);

// 	return 0;
// }