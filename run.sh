#!/bin/bash

# run matrix, mandelbrot, vector
# put output in files
# post process outputs to get execution times, and test data

# bin/vector | python3 unpack_vector.py Native
# echo "Finished running native vector"

# wasmer run bin/vector.wasm | python3 unpack_vector.py Wasmer
# echo "Finished running wasmer vector"

# wasmtime bin/vector.wasm | python3 unpack_vector.py Wasmtime
# echo "Finished running wasmtime vector"

# wasmedge run bin/vector.wasm | python3 unpack_vector.py WasmEdge
# echo "Finished running wasmedge vector"

# bin/matrix | python3 unpack_matrix.py Native
# echo "Finished running native matrix"

# wasmer run bin/matrix.wasm | python3 unpack_matrix.py Wasmer
# echo "Finished running wasmer matrix"

# wasmtime bin/matrix.wasm | python3 unpack_matrix.py Wasmtime
# echo "Finished running wasmtime matrix"

# wasmedge --enable-jit run bin/matrix.wasm | python3 unpack_matrix.py WasmEdge
# echo "Finished running wasmedge matrix"

# C++ / Native
# bin/matrix | python3 unpack_matrix.py Native
# echo "Finished running native matrix"

bin/vector | python3 unpack_vector.py Native
echo "Finished running native vector"

# bin/mandelbrot | python3 unpack_mandelbrot.py Native
# echo "Finished running native mandelbrot"

# # Wasmer
# wasmer run bin/matrix_mer.wasmu | python3 unpack_matrix.py Wasmer
# echo "Finished running wasmer matrix"

wasmer run bin/vector_mer.wasmu | python3 unpack_vector.py Wasmer
echo "Finished running wasmer vector"

# wasmer run bin/mandelbrot_mer.wasmu | python3 unpack_mandelbrot.py Wasmer
# echo "Finished running wasmer mandelbrot"

# # Wasmtime
# wasmtime --allow-precompiled bin/matrix_time.cwasm | python3 unpack_matrix.py Wasmtime
# echo "Finished running wasmtime matrix"

wasmtime --allow-precompiled bin/vector_time.cwasm | python3 unpack_vector.py Wasmtime
echo "Finished running wasmtime vector"

# wasmtime --allow-precompiled bin/mandelbrot_time.cwasm | python3 unpack_mandelbrot.py Wasmtime
# echo "Finished running wasmtime mandelbrot"

# Wasmedge
# wasmedge run bin/matrix_edge.cwasm | python3 unpack_matrix.py Wasmedge
# echo "Finished running wasmedge matrix"

wasmedge run bin/vector_edge.cwasm | python3 unpack_vector.py Wasmedge
echo "Finished running wasmedge vector"

# wasmedge run bin/mandelbrot_edge.cwasm | python3 unpack_mandelbrot.py Wasmedge
# echo "Finished running wasmedge mandelbrot"