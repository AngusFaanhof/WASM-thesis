# Makefile

# Compiler settings
CXX = g++
EMCC = em++
CXXFLAGS = -mavx -I./src/include
EMCCFLAGS = -mavx -msimd128 -I./src/include

#include path
INCLUDE = -I./src/include

# Source files
SRCS = src/mandelbrot.cpp src/matrix_algorithms.cpp src/vector_algorithms.cpp


# Output files
OUT_CPP = bin/benchmark
OUT_WASM = bin/benchmark.wasm

# Targets
.PHONY: all matrix vector mandelbrot

all: matrix vector mandelbrot wasmtime, wasmer, wasmedge

# cpp:
# 	$(CXX) $(CXXFLAGS) -o $(OUT_CPP) $(SRCS)

# wasm:
# 	$(EMCC) $(EMCCFLAGS) -o $(OUT_WASM) $(SRCS)

# cbench:
# 	$(CXX) $(CXXFLAGS) -o $(OUT_CPP) $(SRCS2)

# wbench:
# 	$(EMCC) $(EMCCFLAGS) -o $(OUT_WASM) $(SRCS2)



# make file creates the following
# matrix {C++ and WebAssembly} file=src/benchmarks/matrixBenchmarks.cpp
# vector {C++ and WebAssembly} file=src/benchmarks/vectorBenchmarks.cpp
# mandelbrot {C++ and WebAssembly} file=src/benchmarks/mandelbrotBenchmark.cpp

matrixBenchmark = src/benchmarks/matrixBenchmarks.cpp
vectorBenchmark = src/benchmarks/vectorBenchmarks.cpp
mandelbrotBenchmark = src/benchmarks/mandelbrotBenchmark.cpp

matrix:
	$(CXX) $(CXXFLAGS) -o bin/matrix $(matrixBenchmark) src/matrix_algorithms.cpp
	$(EMCC) $(EMCCFLAGS) -o bin/matrix.wasm $(matrixBenchmark) src/matrix_algorithms.cpp

vector:
	$(CXX) $(CXXFLAGS) -o bin/vector $(vectorBenchmark) src/vector_algorithms.cpp
	$(EMCC) $(EMCCFLAGS) -s MAXIMUM_MEMORY=4GB -o bin/vector.wasm $(vectorBenchmark) src/vector_algorithms.cpp

# g++ -mavx -I./src/include -o mtest src/benchmarks/mandelbrotBenchmark.cpp src/mandelbrot.cpp
mandelbrot:
	$(CXX) $(CXXFLAGS) -o bin/mandelbrot $(mandelbrotBenchmark) src/mandelbrot.cpp
	$(EMCC) $(EMCCFLAGS) -o bin/mandelbrot.wasm $(mandelbrotBenchmark) src/mandelbrot.cpp

inspect:
	$(CXX) $(CXXFLAGS) -g -o bin/inspect src/inspect.cpp $(SRCS)
	$(EMCC) $(EMCCFLAGS) -g -o bin/inspect.wasm src/inspect.cpp $(SRCS)

wasmtime:
	wasmtime compile bin/mandelbrot.wasm -o bin/mandelbrot_time.cwasm
	wasmtime compile bin/matrix.wasm -o bin/matrix_time.cwasm
	wasmtime compile bin/vector.wasm -o bin/vector_time.cwasm

wasmer:
	wasmer compile -o bin/vector_mer.wasmu bin/vector.wasm
	wasmer compile -o bin/matrix_mer.wasmu bin/matrix.wasm
	wasmer compile -o bin/mandelbrot_mer.wasmu bin/mandelbrot.wasm

wasmedge:
	wasmedge compile bin/vector.wasm bin/vector_edge.cwasm
	wasmedge compile bin/matrix.wasm bin/matrix_edge.cwasm
	wasmedge compile bin/mandelbrot.wasm bin/mandelbrot_edge.cwasm