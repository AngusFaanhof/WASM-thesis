#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP

#include <vector>

// Configuration parameters
const float REAL_MIN = -2.0f;
const float REAL_MAX = 1.0f;
const float IMAGINARY_MIN = -1.5f;
const float IMAGINARY_MAX = 1.5f;

std::vector<int> mandelbrot(int pixelWidth, int pixelHeight, int maxIterations);

#endif // MANDELBROT_HPP
