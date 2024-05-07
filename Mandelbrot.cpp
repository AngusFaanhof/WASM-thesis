#include <immintrin.h>

#include <iostream>
#include <random>

#include <fstream>

int REAL_MIN = -2;
int REAL_MAX = 1;
int IMAGINARY_MIN = -1.5;
int IMAGINARY_MAX = 1.5;
int MAX_ITERATIONS = 100;

int main() {
	int pixelWidth = 800;
	int pixelHeight = 600;

	int* mandelbrot = new int[pixelWidth * pixelHeight];

	// unvectorized mandelbrot set
	for (int i = 0; i < pixelWidth; i++) {
		for (int j = 0; j < pixelHeight; j++) {
			double real = REAL_MIN + (REAL_MAX - REAL_MIN) * i / pixelWidth;
			double imaginary = IMAGINARY_MIN + (IMAGINARY_MAX - IMAGINARY_MIN) * j / pixelHeight;

			double zReal = 0;
			double zImaginary = 0;

			int n = 0;
			while (zReal * zReal + zImaginary * zImaginary < 4 && n < MAX_ITERATIONS) {
				double temp = zReal * zReal - zImaginary * zImaginary + real;
				zImaginary = 2 * zReal * zImaginary + imaginary;
				zReal = temp;
				n++;
			}

			mandelbrot[i * pixelHeight + j] = n;
		}
	}

	std::ofstream file("mandelbrot.txt");
	if (!file) {
		std::cerr << "Unable to open file for writing.\n";
		return 1;
	}

	for (int i = 0; i < pixelWidth; i++) {
		for (int j = 0; j < pixelHeight; j++) {
			file << mandelbrot[i * pixelHeight + j] << ',';
		}
		file << '\n';
	}

	file.close();

	return 0;
}