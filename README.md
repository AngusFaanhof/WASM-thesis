# WebAssembly SIMD Performance Benchmark Suite

This repository contains the benchmark suite used in the thesis "Benchmarking SIMD Performance Across WASM Runtimes" by Angus Faanhof.

## Installation

### Prerequisites

Ensure you have the following software versions installed:

- Wasmtime-cli 20.0.0
- Wasmer 4.3.5
- WasmEdge 0.14.0
- Emscripten 3.1.58
- GCC 11.4.0
- Python 3.12.3

### Setup

1. Clone this repository
2. Update the wasmer_path, wasmtime_path, and wasmedge_path variables in scripts/run.sh

## Usage

1. Compile the benchmarks:
> make all
2. Run the benchmarks:
> sudo analysis/run.sh
3. Get result overview:
> ptyhon3 overview.py