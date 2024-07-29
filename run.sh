#!/bin/bash

# run matrix, mandelbrot, vector
# put output in files
# post process outputs to get execution times, and test data

# C++ / Native
# bin/mandelbrot | python3 unpack_mandelbrot.py Native
# bin/matrix | python3 unpack_matrix.py Native
# bin/vector | python3 unpack_vector.py Native

# # Wasmer
# wasmer run bin/mandelbrot.wasm | python3 unpack_mandelbrot.py Wasmer
# wasmer run bin/matrix.wasm | python3 unpack_matrix.py Wasmer
# wasmer run bin/vector.wasm | python3 unpack_vector.py Wasmer

# # Wasmtime
# wasmtime bin/mandelbrot.wasm | python3 unpack_mandelbrot.py Wasmtime
# wasmtime bin/matrix.wasm | python3 unpack_matrix.py Wasmtime
# wasmtime bin/vector.wasm | python3 unpack_vector.py Wasmtime

# Wasmedge
wasmedge run bin/matrix.wasm | python3 unpack_matrix.py WasmEdge
wasmedge run bin/vector.wasm | python3 unpack_vector.py WasmEdge
wasmedge run bin/mandelbrot.wasm | python3 unpack_mandelbrot.py WasmEdge
