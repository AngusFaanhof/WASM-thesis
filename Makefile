# Makefile

# Compiler settings
CXX = g++
EMCC = em++
CXXFLAGS = -mavx -g -Wall -pedantic
EMCCFLAGS = -mavx -msimd128

# Source files
SRCS = src/benchmark.cpp src/matrixAddition.cpp src/helper.cpp src/dotProduct.cpp src/matrixMultiplication.cpp src/mandelbrot.cpp
SRCS2 = src/benchmarks/mandelbrotBenchmark.cpp src/benchmarks/matrixBenchmarks.cpp src/benchmarks/vectorBenchmarks.cpp

# Output files
OUT_CPP = bin/benchmark
OUT_WASM = bin/benchmark.wasm

# Targets
.PHONY: all cpp wasm

all: matrix vector mandelbrot

cpp:
	$(CXX) $(CXXFLAGS) -o $(OUT_CPP) $(SRCS)

wasm:
	$(EMCC) $(EMCCFLAGS) -o $(OUT_WASM) $(SRCS)

cbench:
	$(CXX) $(CXXFLAGS) -o $(OUT_CPP) $(SRCS2)

wbench:
	$(EMCC) $(EMCCFLAGS) -o $(OUT_WASM) $(SRCS2)



# make file creates the following
# matrix {C++ and WebAssembly} file=src/benchmarks/matrixBenchmarks.cpp
# vector {C++ and WebAssembly} file=src/benchmarks/vectorBenchmarks.cpp
# mandelbrot {C++ and WebAssembly} file=src/benchmarks/mandelbrotBenchmark.cpp

matrixBenchmark = src/benchmarks/matrixBenchmarks.cpp
vectorBenchmark = src/benchmarks/vectorBenchmarks.cpp
mandelbrotBenchmark = src/benchmarks/mandelbrotBenchmark.cpp

matrix:
	$(CXX) $(CXXFLAGS) -o bin/matrix $(matrixBenchmark)
	$(EMCC) $(EMCCFLAGS) -o bin/matrix.wasm $(matrixBenchmark)

vector:
	$(CXX) $(CXXFLAGS) -o bin/vector $(vectorBenchmark)
	$(EMCC) $(EMCCFLAGS) -o bin/vector.wasm $(vectorBenchmark)

mandelbrot:
	$(CXX) $(CXXFLAGS) -o bin/mandelbrot $(mandelbrotBenchmark)
	$(EMCC) $(EMCCFLAGS) -o bin/mandelbrot.wasm $(mandelbrotBenchmark)
