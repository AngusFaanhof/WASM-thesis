#include <immintrin.h>

#include <iostream>
#include <random>

#include <fstream>

int REAL_MIN = -2;
int REAL_MAX = 1;
int IMAGINARY_MIN = -1.5;
int IMAGINARY_MAX = 1.5;
int MAX_ITERATIONS = 100;

void saveMandelbrot(int* mandelbrot, int pixelWidth, int pixelHeight) {
	std::ofstream file("mandelbrot.txt");

	for (int i = 0; i < pixelWidth; i++) {
		for (int j = 0; j < pixelHeight; j++) {
			file << mandelbrot[i * pixelHeight + j] << ',';
		}
		file << '\n';
	}

	file.close();
}

int main() {
	int pixelWidth = 800;
	int pixelHeight = 600;

	int* mandelbrot = new int[pixelWidth * pixelHeight];

	// unvectorized mandelbrot set
	// for (int i = 0; i < pixelWidth; i++) {
	// 	for (int j = 0; j < pixelHeight; j++) {
	// 		double cReal = REAL_MIN + (REAL_MAX - REAL_MIN) * i / pixelWidth;
	// 		double cImaginary = IMAGINARY_MIN + (IMAGINARY_MAX - IMAGINARY_MIN) * j / pixelHeight;

	// 		double zReal = 0;
	// 		double zImaginary = 0;

	// 		int n = 0;
	// 		while (zReal * zReal + zImaginary * zImaginary < 4 && n < MAX_ITERATIONS) {
	// 			double tempZReal = zReal * zReal - zImaginary * zImaginary + cReal;
	// 			zImaginary = 2 * zReal * zImaginary + cImaginary;
	// 			zReal = tempZReal;
	// 			n++;
	// 		}

	// 		mandelbrot[i * pixelHeight + j] = n;
	// 	}
	// }

	// vectorized mandelbrot set (128)
	__m128d realMin = _mm_set1_pd(REAL_MIN);
	__m128d realMax = _mm_set1_pd(REAL_MAX);
	__m128d imaginaryMin = _mm_set1_pd(IMAGINARY_MIN);
	__m128d imaginaryMax = _mm_set1_pd(IMAGINARY_MAX);

	__m128d threshold = _mm_set1_pd(4);

	__m128i one = _mm_set1_epi32(1);
	__m128i maxIterations = _mm_set1_epi32(MAX_ITERATIONS);

	for (int i = 0; i < pixelWidth; i++) {
		for (int j = 0; j < pixelHeight; j++) {
			__m128d cReal = _mm_set_pd(REAL_MIN + (REAL_MAX - REAL_MIN) * (i + 1) / pixelWidth, REAL_MIN + (REAL_MAX - REAL_MIN) * i / pixelWidth);
			__m128d cImaginary = _mm_set1_pd(IMAGINARY_MIN + (IMAGINARY_MAX - IMAGINARY_MIN) * j / pixelHeight);

			__m128d zReal = _mm_setzero_pd();
			__m128d zImaginary = _mm_setzero_pd();

			// std::cout << "i: " << i << ", j: " << j << std::endl;
			__m128i n = _mm_setzero_si128();

			while (true) {
				__m128d tempZReal = _mm_sub_pd(_mm_add_pd(_mm_mul_pd(zReal, zReal), _mm_mul_pd(zImaginary, zImaginary)), cReal);
				zImaginary = _mm_add_pd(_mm_mul_pd(_mm_set1_pd(2), _mm_mul_pd(zReal, zImaginary)), cImaginary);
				zReal = tempZReal;

				__m128d magnitude = _mm_add_pd(_mm_mul_pd(zReal, zReal), _mm_mul_pd(zImaginary, zImaginary));
				__m128i mask = _mm_castpd_si128(_mm_cmplt_pd(magnitude, threshold));
				n = _mm_add_epi32(n, _mm_and_si128(mask, one));

				// std::cout << "n: " << _mm_cvtsi128_si32(n) << std::endl;
				if (_mm_movemask_epi8(_mm_cmpeq_epi32(n, maxIterations)) == 0xFFFF) {
					break;
				}

				// increment n
				n = _mm_add_epi32(n, one);
			}

			// mandelbrot[i * pixelHeight + j] = _mm_cvtsi128_si32(n);
			_mm_storeu_si128((__m128i*)&mandelbrot[i * pixelHeight + j], n);
		}
	}


	return 0;
}