#include "../include/mandelbrot.hpp"

#include <immintrin.h>
#include <iostream>

std::vector<int> mandelbrot(int pixelWidth, int pixelHeight, int maxIterations) {
    std::vector<int> mandelbrot(pixelWidth * pixelHeight);

    float xScale = (REAL_MAX - REAL_MIN) / pixelWidth;
    __m128 xScaleVector = _mm_set1_ps(xScale);

    float yScale = (IMAGINARY_MAX - IMAGINARY_MIN) / pixelHeight;

    __m128 realMin = _mm_set1_ps(REAL_MIN);
    __m128 imaginaryMin = _mm_set1_ps(IMAGINARY_MIN);

    __m128 magnitudeThreshold = _mm_set1_ps(4.0f);
    __m128i one = _mm_set1_epi32(1);
    __m128i minusOne = _mm_set1_epi32(-1);

    __m128 two = _mm_set1_ps(2.0f);

    for (int y = 0; y < pixelHeight; y++) {
        __m128 cImaginary = _mm_add_ps(imaginaryMin, _mm_set1_ps(y * yScale));

        for (int x = 0; x < pixelWidth; x += 4) {
            __m128 cReal = _mm_add_ps(realMin, _mm_mul_ps(_mm_set_ps(x + 3, x + 2, x + 1, x), xScaleVector));

            __m128 zReal = _mm_setzero_ps();
            __m128 zImaginary = _mm_setzero_ps();

            __m128i numIterations = _mm_setzero_si128();

            for (int i = 0; i < maxIterations; i++) {
                __m128 zRealSquared = _mm_mul_ps(zReal, zReal);
                __m128 zImaginarySquared = _mm_mul_ps(zImaginary, zImaginary);

                __m128 magnitude = _mm_add_ps(zRealSquared, zImaginarySquared);
                __m128i mask = _mm_castps_si128(_mm_cmplt_ps(magnitude, magnitudeThreshold));

                // all iterations >= maxIterations
                if (_mm_testz_si128(mask, mask)) break;

                numIterations = _mm_add_epi32(numIterations, _mm_and_si128(mask, one));

                __m128 newZReal = _mm_add_ps(_mm_sub_ps(zRealSquared, zImaginarySquared), cReal);
                __m128 newZImaginary = _mm_add_ps(_mm_mul_ps(two, _mm_mul_ps(zReal, zImaginary)), cImaginary);

                zReal = newZReal;
                zImaginary = newZImaginary;
            }

            _mm_storeu_si128((__m128i*)&mandelbrot[y * pixelWidth + x], numIterations);
        }
    }

    return mandelbrot;
}