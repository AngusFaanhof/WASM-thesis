# Makefile

# Compiler settings
CXX = g++
EMCC = em++
CXXFLAGS = -mavx -I./include
EMCCFLAGS = -mavx -msimd128 -I./include -std=c++17

#include path
INCLUDE = -I./include

# Source files
SRCS = src/mandelbrot.cpp src/matrix_algorithms.cpp src/vector_algorithms.cpp src/utils.cpp


# Output files
OUT_CPP = bin/benchmark
OUT_WASM = bin/benchmark.wasm

# Targets
.PHONY: all matrix vector mandelbrot

all: matrix vector mandelbrot wasmtime wasmer wasmedge

matrixBenchmark = src/benchmarks/matrixBenchmarks.cpp src/matrix_algorithms.cpp src/utils.cpp
vectorBenchmark = src/benchmarks/vectorBenchmarks.cpp src/vector_algorithms.cpp src/utils.cpp
mandelbrotBenchmark = src/benchmarks/mandelbrotBenchmark.cpp src/mandelbrot.cpp src/utils.cpp

matrix:
	$(CXX) $(CXXFLAGS) -o bin/native/matrix $(matrixBenchmark)
	$(EMCC) $(EMCCFLAGS) -o bin/matrix.wasm $(matrixBenchmark)

vector:
	$(CXX) $(CXXFLAGS) -o bin/native/vector $(vectorBenchmark)
	$(EMCC) $(EMCCFLAGS) -o bin/vector.wasm $(vectorBenchmark)

mandelbrot:
	$(CXX) $(CXXFLAGS) -o bin/native/mandelbrot $(mandelbrotBenchmark)
	$(EMCC) $(EMCCFLAGS) -o bin/mandelbrot.wasm $(mandelbrotBenchmark)

inspect:
	$(CXX) $(CXXFLAGS) -g -o bin/inspect src/inspect.cpp $(SRCS)
	$(EMCC) $(EMCCFLAGS) -g -o bin/inspect.wasm src/inspect.cpp $(SRCS)

wasmtime:
	wasmtime compile bin/mandelbrot.wasm -o bin/wasmtime/mandelbrot.cwasm
	wasmtime compile bin/matrix.wasm -o bin/wasmtime/matrix.cwasm
	wasmtime compile bin/vector.wasm -o bin/wasmtime/vector.cwasm

wasmer:
	wasmer compile -o bin/wasmer/vector.wasmu bin/vector.wasm
	wasmer compile -o bin/wasmer/matrix.wasmu bin/matrix.wasm
	wasmer compile -o bin/wasmer/mandelbrot.wasmu bin/mandelbrot.wasm

wasmedge:
	wasmedge compile bin/vector.wasm bin/wasmedge/vector.cwasm
	wasmedge compile bin/matrix.wasm bin/wasmedge/matrix.cwasm
	wasmedge compile bin/mandelbrot.wasm bin/wasmedge/mandelbrot.cwasm