#include "../include/matrix_algorithms.hpp"

#include <immintrin.h>
#include <iomanip>



std::vector<float> transposeMatrix(const std::vector<float>& m, size_t rowsCols) {
	std::vector<float> result(rowsCols * rowsCols);

	for (size_t i = 0; i < rowsCols; i += 4) {
		for (size_t j = 0; j < rowsCols; j += 4) {
			__m128 row0 = _mm_loadu_ps(&m[i * rowsCols + j]);
			__m128 row1 = _mm_loadu_ps(&m[(i + 1) * rowsCols + j]);
			__m128 row2 = _mm_loadu_ps(&m[(i + 2) * rowsCols + j]);
			__m128 row3 = _mm_loadu_ps(&m[(i + 3) * rowsCols + j]);

			_MM_TRANSPOSE4_PS(row0, row1, row2, row3);

			_mm_storeu_ps(&result[j * rowsCols + i], row0);
			_mm_storeu_ps(&result[(j + 1) * rowsCols + i], row1);
			_mm_storeu_ps(&result[(j + 2) * rowsCols + i], row2);
			_mm_storeu_ps(&result[(j + 3) * rowsCols + i], row3);
		}
	}

	return result;
}

std::vector<int> transposeMatrix(const std::vector<int>& m, size_t rowsCols) {
	std::vector<int> result(rowsCols * rowsCols);

	for (size_t i = 0; i < rowsCols; i += 4) {
		for (size_t j = 0; j < rowsCols; j += 4) {
			__m128i row0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[i * rowsCols + j]));
			__m128i row1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[(i + 1) * rowsCols + j]));
			__m128i row2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[(i + 2) * rowsCols + j]));
			__m128i row3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[(i + 3) * rowsCols + j]));

			// _MM_TRANSPOSE4_EPI32(row0, row1, row2, row3);
			__m128i tmp0 = _mm_unpacklo_epi32(row0, row1);
			__m128i tmp1 = _mm_unpacklo_epi32(row2, row3);
			__m128i tmp2 = _mm_unpackhi_epi32(row0, row1);
			__m128i tmp3 = _mm_unpackhi_epi32(row2, row3);

			row0 = _mm_unpacklo_epi64(tmp0, tmp1);
			row1 = _mm_unpackhi_epi64(tmp0, tmp1);
			row2 = _mm_unpacklo_epi64(tmp2, tmp3);
			row3 = _mm_unpackhi_epi64(tmp2, tmp3);

			_mm_storeu_si128(reinterpret_cast<__m128i*>(&result[j * rowsCols + i]), row0);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(&result[(j + 1) * rowsCols + i]), row1);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(&result[(j + 2) * rowsCols + i]), row2);
			_mm_storeu_si128(reinterpret_cast<__m128i*>(&result[(j + 3) * rowsCols + i]), row3);
		}
	}

	return result;
}

// code lines: 64, 66, 67, 68, 70, 71, 72, 73, 74, 76, 80
std::vector<float> multiplyMatrices(const std::vector<float>& A, const std::vector<float>& B, size_t rowsCols) {
	std::vector<float> result(rowsCols * rowsCols);

	for (size_t i = 0; i < rowsCols; i++) {
		for (size_t j = 0; j < rowsCols; j+=4) {
			__m128 sum = _mm_setzero_ps();

			for (size_t k = 0; k < rowsCols; k++) {
				__m128 a = _mm_set1_ps(A[i * rowsCols + k]);
				__m128 b = _mm_loadu_ps(&B[k * rowsCols + j]);
				sum = _mm_add_ps(sum, _mm_mul_ps(a, b));
			}

			_mm_storeu_ps(&result[i * rowsCols + j], sum);
		}
	}

	return result;
}

// code lines: 85, 87, 88, 89, 91, 92, 93, 94, 95, 97, 101
std::vector<int> multiplyMatrices(const std::vector<int>& A, const std::vector<int>& B, size_t rowsCols) {
	std::vector<int> result(rowsCols * rowsCols);

	for (size_t i = 0; i < rowsCols; i++) {
		for (size_t j = 0; j < rowsCols; j+=4) {
			__m128i sum = _mm_setzero_si128();

			for (size_t k = 0; k < rowsCols; k++) {
				__m128i a = _mm_set1_epi32(A[i * rowsCols + k]);
				__m128i b = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&B[k * rowsCols + j]));
				sum = _mm_add_epi32(sum, _mm_mullo_epi32(a, b));
			}

			_mm_storeu_si128(reinterpret_cast<__m128i*>(&result[i * rowsCols]), sum);
		}
	}

	return result;
}