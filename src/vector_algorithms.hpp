#ifndef VECTOR_ALGORITHMS_HPP
#define VECTOR_ALGORITHMS_HPP

#include <iostream>
#include <chrono>
#include <immintrin.h>
#include <random>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

void printVector(const std::vector<float>& vector) {
	for (int i = 0; i < vector.size(); i++) {
		std::cout << vector.at(i) << ",";
	}
	std::cout << std::endl;
}

std::vector<float> normalizeVector(std::vector<float>& vec) {
    size_t size = vec.size();
    __m128 sum = _mm_setzero_ps();

    // sum of squares
    for (size_t i = 0; i < size; i += 4) {
        __m128 values = _mm_loadu_ps(&vec[i]);
        sum = _mm_add_ps(sum, _mm_mul_ps(values, values));
    }

    sum = _mm_hadd_ps(sum, sum);
    sum = _mm_hadd_ps(sum, sum);

    // inverse square root
    __m128 invSqrt = _mm_rsqrt_ps(sum);

    std::vector<float> result(size);

    // normalize vector
    for (size_t i = 0; i < size; i += 4) {
        __m128 values = _mm_loadu_ps(&vec[i]);
        __m128 normalized = _mm_mul_ps(values, invSqrt);
        _mm_storeu_ps(&result[i], normalized);
    }

    return result;
}

std::vector<float> normalizeVector(std::vector<int>& vec) {
    size_t size = vec.size();
    __m128i sum_int = _mm_setzero_si128();

    // sum of elements
    for (size_t i = 0; i < size; i += 4) {
        __m128i values = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&vec[i]));
        sum_int = _mm_add_epi32(sum_int, values);
    }

	// convert to float
	__m128 sum = _mm_cvtepi32_ps(sum_int);

    sum = _mm_hadd_ps(sum, sum);
    sum = _mm_hadd_ps(sum, sum);

    // inverse square root
    __m128 invSqrt = _mm_rsqrt_ps(sum);

    std::vector<float> result(size);

    // normalize vector
    for (size_t i = 0; i < size; i += 4) {
		__m128i valuesI = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&vec[i]));
		__m128 values = _mm_cvtepi32_ps(sum_int);
        __m128 normalized = _mm_mul_ps(values, invSqrt);
        _mm_storeu_ps(&result[i], normalized);
    }

    return result;
}

float averageVector(std::vector<float>& vec) {
    size_t size = vec.size();
    __m128 sum = _mm_setzero_ps();

    // sum of elements
    for (size_t i = 0; i < size; i += 4) {
        __m128 values = _mm_loadu_ps(&vec[i]);
        sum = _mm_add_ps(sum, values);
    }

    __m128 divided = _mm_div_ps(sum, _mm_set1_ps(static_cast<float>(size)));

    sum = _mm_hadd_ps(divided, divided);
    sum = _mm_hadd_ps(sum, sum);

    return _mm_extract_ps(sum, 0);
}

float averageVector(std::vector<int>& vec) {
    size_t size = vec.size();
    __m128i sum_int = _mm_setzero_si128();

    // sum of elements
    for (size_t i = 0; i < size; i += 4) {
        __m128i values = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&vec[i]));
        sum_int = _mm_add_epi32(sum_int, values);
    }

	// convert to float
	__m128 sum = _mm_cvtepi32_ps(sum_int);

    __m128 divided = _mm_div_ps(sum, _mm_set1_ps(static_cast<float>(size)));

    sum = _mm_hadd_ps(divided, divided);
    sum = _mm_hadd_ps(sum, sum);

    return _mm_extract_ps(sum, 0);
}

float dotProduct(std::vector<float>& vecA, std::vector<float>& vecB) {
	size_t size = vecA.size();
	__m128 sum = _mm_setzero_ps();

	for (int i = 0; i < size; i += 4) {
		__m128 a = _mm_loadu_ps(&vecA[i]);
		__m128 b = _mm_loadu_ps(&vecB[i]);

		__m128 mul = _mm_mul_ps(a, b);

		sum = _mm_add_ps(sum, mul);
	}

	sum = _mm_hadd_ps(sum, sum);
	sum = _mm_hadd_ps(sum, sum);

	return _mm_extract_ps(sum, 0);
}

int dotProduct(std::vector<int>& vecA, std::vector<int>& vecB) {
	size_t size = vecA.size();
	__m128i sum = _mm_setzero_si128();

	for (size_t i = 0; i < size; i += 4) {
		__m128i a = _mm_loadu_si128((__m128i*)&vecA[i]);
		__m128i b = _mm_loadu_si128((__m128i*)&vecB[i]);

		__m128i mul = _mm_mullo_epi32(a, b);

		sum = _mm_add_epi32(sum, mul);
	}

	sum = _mm_hadd_epi32(sum, sum);
	sum = _mm_hadd_epi32(sum, sum);

	return _mm_extract_epi32(sum, 0);
}

std::vector<float> vectorAddition(std::vector<float>& a, std::vector<float>& b) {
	std::vector<float> result(a.size());

	for (int i = 0; i < a.size(); i += 4) {
		__m128 vecA = _mm_loadu_ps(&a[i]);
		__m128 vecB = _mm_loadu_ps(&b[i]);

		__m128 sum = _mm_add_ps(vecA, vecB);
		_mm_storeu_ps(&result[i], sum);
	}

	return result;
}

std::vector<int> vectorAddition(std::vector<int>& a, std::vector<int>& b) {
	std::vector<int> result(a.size());

	for (int i = 0; i < a.size(); i += 4) {
		__m128i vecA = _mm_loadu_si128((__m128i*)&a[i]);
		__m128i vecB = _mm_loadu_si128((__m128i*)&b[i]);

		__m128i sum = _mm_add_epi32(vecA, vecB);
		_mm_storeu_si128((__m128i*)&result[i], sum);
	}

	return result;
}

#endif // VECTOR_ALGORITHMS_HPP