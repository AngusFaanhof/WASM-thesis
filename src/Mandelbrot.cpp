#include <immintrin.h>

#include <iostream>

int REAL_MIN = -2;
int REAL_MAX = 1;
double IMAGINARY_MIN = -1.5;
double IMAGINARY_MAX = 1.5;
int MAX_ITERATIONS = 100;

int* unvectorizedMandelbrot(int pixelWidth, int pixelHeight) {
	int* mandelbrot = new int[pixelWidth * pixelHeight];

	float xScale = static_cast<float>((REAL_MAX - REAL_MIN)) / pixelWidth;
	float yScale = static_cast<float>(IMAGINARY_MAX - IMAGINARY_MIN) / pixelHeight;

	for (int y = 0; y < pixelHeight; y++) {
		for (int x = 0; x < pixelWidth; x++) {
			float cReal = REAL_MIN + x * xScale;
			float cImaginary = IMAGINARY_MIN + y * yScale;

			float zReal = 0;
			float zImaginary = 0;

			int n = 0;
			while (n < MAX_ITERATIONS) {
				float zRealSquared = zReal * zReal;
				float zImaginarySquared = zImaginary * zImaginary;

				float magnitude = zRealSquared + zImaginarySquared;
				if (magnitude >= 4) break;

				float tempZReal = zRealSquared - zImaginarySquared + cReal;
				zImaginary = 2 * zReal * zImaginary + cImaginary;
				zReal = tempZReal;

				n++;
			}

			mandelbrot[y * pixelWidth + x] = n;
		}
	}

	return mandelbrot;
}

int* vectorizedMandelbrot(int pixelWidth, int pixelHeight) {
	int* mandelbrot = new int[pixelWidth * pixelHeight];

	float xScale = static_cast<float>((REAL_MAX - REAL_MIN)) / pixelWidth;
	float yScale = static_cast<float>(IMAGINARY_MAX - IMAGINARY_MIN) / pixelHeight;

	__m128 realMin = _mm_set1_ps(REAL_MIN);
	__m128 xScaleVector = _mm_set1_ps(xScale);

	__m128 imaginaryMin = _mm_set1_ps(IMAGINARY_MIN);
	__m128 yScaleVector = _mm_set1_ps(yScale);

	__m128 magnitudeThreshold = _mm_set1_ps(4.0f);
	__m128i one =_mm_set1_epi32(1);

	for (int y = 0; y < pixelHeight; y++) {
		for (int x = 0; x < pixelWidth; x += 4) {
			__m128 cReal = _mm_add_ps(realMin, _mm_mul_ps(_mm_set_ps(x + 3, x + 2, x+ 1, x + 0), xScaleVector));
			__m128 cImaginary = _mm_add_ps(imaginaryMin, _mm_mul_ps(_mm_set1_ps(y), yScaleVector));

			__m128 zReal = _mm_setzero_ps();
			__m128 zImaginary = _mm_setzero_ps();

			__m128i numIterations = _mm_set1_epi32(0);

			int n = 0;
			while (n < MAX_ITERATIONS) {
				__m128 zRealSquared = _mm_mul_ps(zReal, zReal);
				__m128 zImaginarySquared = _mm_mul_ps(zImaginary, zImaginary);

				__m128 magnitude = _mm_add_ps(zRealSquared, zImaginarySquared);
				__m128i mask = _mm_castps_si128(_mm_cmplt_ps(magnitude, magnitudeThreshold));
				numIterations = _mm_add_epi32(numIterations, _mm_and_si128(mask, one));

				if (_mm_testz_si128(mask, _mm_set1_epi32(-1))) break;

				__m128 tempZReal = _mm_sub_ps(zRealSquared, zImaginarySquared);
				tempZReal = _mm_add_ps(tempZReal, cReal);

				zImaginary = _mm_add_ps(_mm_mul_ps(_mm_set1_ps(2), _mm_mul_ps(zReal, zImaginary)), cImaginary);
				zReal = tempZReal;

				n++;
			}

			_mm_storeu_si128((__m128i*)&mandelbrot[(y * pixelWidth) + x], numIterations);
		}
	}

	return mandelbrot;
}

int main() {
	int pixelWidth = 800;
	int pixelHeight = 600;

	int* mandelbrot = vectorizedMandelbrot(pixelWidth, pixelHeight);
	int* mandelbrot2 = unvectorizedMandelbrot(pixelWidth, pixelHeight);

	return 0;
}