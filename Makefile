# Makefile

# Compiler settings
CXX = g++
EMCC = em++
CXXFLAGS = -mavx2 -g -Wall -pedantic
EMCCFLAGS = -mavx -msimd128

# Source files
SRCS = src/benchmark.cpp src/matrixAddition.cpp src/helper.cpp src/dotProduct.cpp src/matrixMultiplication.cpp src/mandelbrot.cpp

# Output files
OUT_CPP = benchmark
OUT_WASM = benchmark.wasm

# Targets
.PHONY: all cpp wasm

all: cpp wasm

cpp:
	$(CXX) $(CXXFLAGS) -o $(OUT_CPP) $(SRCS)

wasm:
	$(EMCC) $(EMCCFLAGS) -o $(OUT_WASM) $(SRCS)

ccopy: cpp
	./$(OUT_CPP) | xclip -selection clipboard