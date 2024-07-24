#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <immintrin.h>

#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <type_traits>

template<typename T>
class Matrix {
public:
    Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols), data_(rows * cols, T()) {}

    Matrix(size_t rows, size_t cols, const std::vector<T>& data)
        : rows_(rows), cols_(cols), data_(data) {
        if (data.size() != rows * cols) {
            throw std::invalid_argument("Data size does not match matrix dimensions");
        }
    }

    void setData(const std::vector<T>& newData) {
        if (newData.size() != rows_ * cols_) {
            throw std::invalid_argument("New data size does not match matrix dimensions");
        }
        data_ = newData;
    }

    T& operator()(size_t row, size_t col) {
        return data_[row * cols_ + col];
    }

    const T& operator()(size_t row, size_t col) const {
        return data_[row * cols_ + col];
    }

    void print() const {
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j) {
                if constexpr (std::is_floating_point_v<T>) {
                    std::cout << std::setw(10) << std::setprecision(4) << (*this)(i, j) << " ";
                } else {
                    std::cout << std::setw(10) << (*this)(i, j) << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }
    const std::vector<T>& data() const { return data_; }

private:
    size_t rows_, cols_;
    std::vector<T> data_;
};

using MatrixF = Matrix<float>;
using MatrixI = Matrix<int>;


MatrixF transposeMatrix(MatrixF& m) {
	MatrixF result(m.cols(), m.rows());

	for (size_t i = 0; i < m.rows(); i += 4) {
		for (size_t j = 0; j < m.cols(); j += 4) {
			__m128 row0 = _mm_loadu_ps(&m(i, j));
			__m128 row1 = _mm_loadu_ps(&m(i + 1, j));
			__m128 row2 = _mm_loadu_ps(&m(i + 2, j));
			__m128 row3 = _mm_loadu_ps(&m(i + 3, j));

			_MM_TRANSPOSE4_PS(row0, row1, row2, row3);

			_mm_storeu_ps(&result(j, i), row0);
			_mm_storeu_ps(&result(j + 1, i), row1);
			_mm_storeu_ps(&result(j + 2, i), row2);
			_mm_storeu_ps(&result(j + 3, i), row3);
		}
	}

	return result;
}

MatrixI transposeMatrix(MatrixI& m) {
	MatrixI result(m.cols(), m.rows());

    for (size_t i = 0; i < m.rows(); i += 4) {
        for (size_t j = 0; j < m.cols(); j += 4) {
            __m128i row0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m(i, j)));
            __m128i row1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m(i + 1, j)));
            __m128i row2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m(i + 2, j)));
            __m128i row3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m(i + 3, j)));

			// _MM_TRANSPOSE4_EPI32(row0, row1, row2, row3);
            __m128i tmp0 = _mm_unpacklo_epi32(row0, row1);
            __m128i tmp1 = _mm_unpacklo_epi32(row2, row3);
            __m128i tmp2 = _mm_unpackhi_epi32(row0, row1);
            __m128i tmp3 = _mm_unpackhi_epi32(row2, row3);

            row0 = _mm_unpacklo_epi64(tmp0, tmp1);
            row1 = _mm_unpackhi_epi64(tmp0, tmp1);
            row2 = _mm_unpacklo_epi64(tmp2, tmp3);
            row3 = _mm_unpackhi_epi64(tmp2, tmp3);

            _mm_storeu_si128(reinterpret_cast<__m128i*>(&result(j, i)), row0);
            _mm_storeu_si128(reinterpret_cast<__m128i*>(&result(j + 1, i)), row1);
            _mm_storeu_si128(reinterpret_cast<__m128i*>(&result(j + 2, i)), row2);
            _mm_storeu_si128(reinterpret_cast<__m128i*>(&result(j + 3, i)), row3);
        }
    }

    return result;
}

MatrixF multiplyMatrices(MatrixF& A, MatrixF& B) {
	MatrixF result(A.rows(), B.cols());

	for (size_t i = 0; i < A.rows(); i++) {
        for (size_t j = 0; j < B.cols(); j += 4) {
            __m128 sum = _mm_setzero_ps();

            for (size_t k = 0; k < A.cols(); k++) {
                __m128 a = _mm_set1_ps(A(i, k));
                __m128 b = _mm_loadu_ps(&B(k, j));
                sum = _mm_add_ps(sum, _mm_mul_ps(a, b));
            }

            _mm_storeu_ps(&result(i, j), sum);
        }
    }

	return result;
}

MatrixI multiplyMatrices(MatrixI& A, MatrixI& B) {
	MatrixI result(A.rows(), B.cols());

	for (size_t i = 0; i < A.rows(); i++) {
		for (size_t j = 0; j < B.cols(); j += 4) {
			__m128i sum = _mm_setzero_si128();

			for (size_t k = 0; k < A.cols(); k++) {
				__m128i a = _mm_set1_epi32(A(i, k));
				__m128i b = _mm_loadu_si128((__m128i*)&B(k, j));
				sum = _mm_add_epi32(sum, _mm_mullo_epi32(a, b));
			}

			_mm_storeu_si128((__m128i*)&result(i, j), sum);
		}
	}

	return result;
}

#endif // MATRIX_HPP