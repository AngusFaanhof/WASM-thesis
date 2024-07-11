# BSc Thesis: SIMD Performance in WebAssembly Runtimes

This repository contains the source code and benchmarks for my Bachelor's thesis investigating SIMD performance in WebAssembly runtimes.

## Source Code

The source code for the benchmarks can be found in the `src/` directory.

## Compilation

To compile the benchmark executables, use the following commands:

- For C++: `make cpp`
- For WebAssembly: `make wasm`
- For both: `make all`

## Running the Benchmark

Execute `experiment.sh` to run the full benchmark suite. Please note that this can take a considerable amount of time.

For individual benchmark runs:

- For WebAssembly: `{runtime} run benchmark.wasm {method} {size} {useFloat}`
- For native: `./benchmark {method} {size} {useFloat}`

### Arguments

#### Methods

| ID | Method               |
|----|----------------------|
| 0  | Vector Addition      |
| 1  | Dot Product          |
| 2  | Matrix Multiplication|
| 3  | Mandelbrot           |

#### Size Options

- **Vector Addition & Dot Product:**
  16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576

- **Matrix Multiplication:**
  16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576

- **Mandelbrot:**
  16, 32, 64, 128, 256, 512, 1024, 2048, 4096

#### Data Type

*Required only for methods 0, 1, and 2*

| ID | Type    |
|----|---------|
| 0  | Integer |
| 1  | Float   |

## Example Usage

```bash
# Run Vector Addition benchmark with size 1024 using floats on Wasmtime
wasmtime run benchmark.wasm 0 1024 1

# Run Mandelbrot benchmark with 256 iterations natively
./benchmark 3 256