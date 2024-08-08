#!/bin/bash

wasmer_path="/home/angus/.wasmer/bin/wasmer"
wasmtime_path="/home/angus/.wasmtime/bin/wasmtime"
wasmedge_path="/home/angus/.wasmedge/bin/wasmedge"

# C++ / Native
nice -n -20 bin/native/matrix | python3 scripts/unpack.py Native
echo "Finished running native matrix"

nice -n -20 bin/native/vector | python3 scripts/unpack.py Native
echo "Finished running native vector"

nice -n -20 bin/native/mandelbrot | python3 scripts/unpack.py Native
echo "Finished running native mandelbrot"

# Wasmer
nice -n -20 ${wasmer_path} run bin/matrix.wasm | python3 scripts/unpack.py Wasmer
echo "Finished running wasmer matrix"

nice -n -20 ${wasmer_path} run bin/vector.wasm | python3 scripts/unpack.py Wasmer
echo "Finished running wasmer vector"

nice -n -20 ${wasmer_path} run bin/mandelbrot.wasm | python3 scripts/unpack.py Wasmer
echo "Finished running wasmer mandelbrot"

# # Wasmtime
nice -n -20 ${wasmtime_path} --allow-precompiled bin/wasmtime/matrix.cwasm | python3 scripts/unpack.py Wasmtime
echo "Finished running wasmtime matrix"

nice -n -20 ${wasmtime_path} --allow-precompiled bin/wasmtime/vector.cwasm | python3 scripts/unpack.py Wasmtime
echo "Finished running wasmtime vector"

nice -n -20 ${wasmtime_path} --allow-precompiled bin/wasmtime/mandelbrot.cwasm | python3 scripts/unpack.py Wasmtime
echo "Finished running wasmtime mandelbrot"

# # Wasmedge
nice -n -20 ${wasmedge_path} run bin/wasmedge/matrix.cwasm | python3 scripts/unpack.py Wasmedge
echo "Finished running wasmedge matrix"

nice -n -20 ${wasmedge_path} run bin/wasmedge/vector.cwasm | python3 scripts/unpack.py Wasmedge
echo "Finished running wasmedge vector"

nice -n -20 ${wasmedge_path} run bin/wasmedge/mandelbrot.cwasm | python3 scripts/unpack.py Wasmedge
echo "Finished running wasmedge mandelbrot"