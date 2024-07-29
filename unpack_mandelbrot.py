# example usage
# bin/vectorBenchmark | python3 extract_data.py Wasmtime

# example input
"""
Vector algorithms
Execution times for normalizeVector (float) with size 4:
{2425,491,401,381,381,}
Execution times for averageVector (float) with size 4:
{291,110,110,101,100,}
Execution times for vectorDotProduct (float) with size 4:
{210,111,140,100,101,}
Execution times for vectorAddition (float) with size 4:
{711,341,340,341,341,}
Execution times for normalizeVector (int) with size 4:
{671,391,391,400,380,}
Execution times for averageVector (int) with size 4:
{190,121,131,120,120,}
Execution times for vectorDotProduct (int) with size 4:
{191,110,110,100,110,}
Execution times for vectorAddition (int) with size 4:
{1052,441,430,391,340,}
Test data:
floatVectorsA:
size: 4
0.503277,0.647936,0.0659201,0.851062,
floatVectorsB:
size: 4
0.503277,0.647936,0.0659201,0.851062,
intVectorsA:
size: 4
503,648,65,851
intVectorsB:
size: 4
503,648,65,851
"""

# examples output
# Results/Wasmtime/normalizeVector_float_4.csv
# 2425,491,401,381,381
# TestData/Wasmtime/normalizeVector_float_4.csv
# 0.503277,0.647936,0.0659201,0.851062

# Results/Wasmtime/averageVector_float_4.csv
# 291,110,110,101,100
# TestData/Wasmtime/averageVector_float_4.csv
# 0.503277,0.647936,0.0659201,0.851062

# Results/Wasmtime/vectorDotProduct_float_4.csv
# 210,111,140,100,101
# TestData/Wasmtime/vectorDotProduct_float_4.csv
# A: 0.503277,0.647936,0.0659201,0.851062
# B: 0.503277,0.647936,0.0659201,0.851062

# Results/Wasmtime/vectorAddition_float_4.csv
# 711,341,340,341,341
# TestData/Wasmtime/vectorAddition_float_4.csv
# A: 0.503277,0.647936,0.0659201,0.851062
# B: 0.503277,0.647936,0.0659201,0.851062

# Results/Wasmtime/normalizeVector_int_4.csv
# 671,391,391,400,380
# TestData/Wasmtime/normalizeVector_int_4.csv
# 503,648,65,851

# Results/Wasmtime/averageVector_int_4.csv
# 190,121,131,120,120
# TestData/Wasmtime/averageVector_int_4.csv
# 503,648,65,851

# Results/Wasmtime/vectorDotProduct_int_4.csv
# 191,110,110,100,110
# TestData/Wasmtime/vectorDotProduct_int_4.csv
# A: 503,648,65,851
# B: 503,648,65,851

# Results/Wasmtime/vectorAddition_int_4.csv
# 1052,441,430,391,340
# TestData/Wasmtime/vectorAddition_int_4.csv
# A: 503,648,65,851
# B: 503,648,65,851

# example output
# Results/Wasmtime/mandelbrot_100.csv
# 79064280,55198158,54932476,54646143,55016505

# Results/Wasmtime/mandelbrot_200.csv
# 96305358,98608855,98283640,96174470,96330004

# Results/Wasmtime/mandelbrot_300.csv
# 137998807,137769593,138162164,137594261,139709121

import sys
import os

def process_input(input_text, output_dir):
    lines = input_text.strip().split('\n')
    current_size = None
    current_times = None

    for line in lines:
        if line.startswith("Execution times for mandelbrot"):
            if current_size and current_times:
                write_output(output_dir, current_size, current_times)
            current_size = line.split()[-1].rstrip(':')
        elif line.startswith("{") and line.endswith("}"):
            current_times = line.strip("{}").split(',')
            current_times = [t.strip() for t in current_times if t.strip()]

    if current_size and current_times:
        write_output(output_dir, current_size, current_times)

def write_output(output_dir, size, times):
    filename = f"mandelbrot_{size}.csv"
    filepath = os.path.join(output_dir, filename)
    os.makedirs(output_dir, exist_ok=True)
    with open(filepath, 'w') as f:
        f.write(','.join(times))

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python extract_data.py <output_directory>")
        sys.exit(1)

    output_dir = os.path.join("Results", sys.argv[1])
    input_text = sys.stdin.read()
    process_input(input_text, output_dir)