Design

input sizes
256, 16384, 1048576

Data generation
Mersenne Twister 19937 generator
Integer vectors are generated with a range from -2^32 to 2^32-1
Float vectors use a range from {min 32-bit float} to {max 32 bit float}


micro-benchmark methods
1. Vector Average (Int / Float)
2. Vector Summation (Int / Float)
3. Vector Dot Product (Int / Float)
4. Matrix Inverse (Int / Float)
5. Matrix Transpose (Int / Float)
6. Matrix Transform (Int / Float)
7. Matrix Multiplication (Int / Float)
8. Shiftrows (Int / Float)
9. Mandelbrot set
10. SIMDjson
11. Image gray scaling

Compilation phase
1. Write algorithms in C++ using <intrins.h>
2. Compile to executable with GCC
3. Compile to Wasm with Emscripten

Preperation
1. Generate data

Execution
1. Load data
2. Run micro-benchmark (100 times)
3. Record the execution times using high_resolution<nanoseconds>
4. Store execution times as .csv
5. store statistics

statistics
Size      | mean | median | std | min | max |
16		  | 95	 | 94.98  | 1.2 | 20  | 150 |

file structure
methods/
	addition.cpp
	average.cpp
	...
benchmark_utils.cpp
benchmark.cpp
benchmarks/
	bench_addition.cpp
	bench_average.cpp




Evaluating