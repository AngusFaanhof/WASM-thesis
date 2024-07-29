import sys
import os

def process_input(input_text, output_dir):
    lines = input_text.strip().split('\n')
    execution_data = []
    test_data = {}

    for line in lines:
        if line.startswith("Execution times for"):
            parts = line.split()
            algorithm = parts[3]
            data_type = parts[4].strip('()')
            size = parts[-1].rstrip(':')
        elif line.startswith("{") and line.endswith("}"):
            times = line.strip("{}").split(',')
            times = [t.strip() for t in times if t.strip()]
            execution_data.append((algorithm, data_type, size, times))
        elif line.startswith("Test data:"):
            parse_test_data(lines[lines.index(line)+1:], test_data)

    for algorithm, data_type, size, times in execution_data:
        write_output(output_dir, algorithm, data_type, size, times, test_data)

def parse_test_data(data_lines, test_data):
    current_matrix = None
    current_size = None
    matrix_data = []
    for line in data_lines:
        line = line.strip()
        if line.endswith(':'):
            if current_matrix and matrix_data:
                test_data[current_matrix][current_size] = matrix_data
            current_matrix = line.rstrip(':')
            test_data[current_matrix] = {}
            current_size = None
            matrix_data = []
        elif line.startswith('size:'):
            if matrix_data:
                test_data[current_matrix][current_size] = matrix_data
            current_size = line.split(':')[1].strip()
            matrix_data = []
        elif line:
            matrix_data.append(line.rstrip(','))
    if current_matrix and current_size and matrix_data:
        test_data[current_matrix][current_size] = matrix_data

def write_output(output_dir, algorithm, data_type, size, times, test_data):
    results_dir = os.path.join("Results", output_dir)
    test_data_dir = os.path.join("TestData", output_dir)
    os.makedirs(results_dir, exist_ok=True)
    os.makedirs(test_data_dir, exist_ok=True)

    # Write results
    results_filename = f"{algorithm}_{data_type}_{size}.csv"
    results_filepath = os.path.join(results_dir, results_filename)
    with open(results_filepath, 'w') as f:
        f.write(','.join(times))

    # Write test data
    test_data_filename = f"{algorithm}_{data_type}_{size}.csv"
    test_data_filepath = os.path.join(test_data_dir, test_data_filename)
    try:
        with open(test_data_filepath, 'w') as f:
            if algorithm == 'multiplyMatrices':
                f.write(f"A:\n{format_matrix(test_data[data_type + 'MatricesA'][size])}\n\n")
                f.write(f"B:\n{format_matrix(test_data[data_type + 'MatricesB'][size])}")
            else:
                f.write(f"{format_matrix(test_data[data_type + 'MatricesA'][size])}")
    except KeyError:
        print(f"Warning: Test data not found for {algorithm}_{data_type}_{size}")

def format_matrix(matrix_data):
    return '\n'.join(matrix_data)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python extract_data_matrices.py <output_directory>")
        sys.exit(1)

    output_dir = sys.argv[1]
    input_text = sys.stdin.read()
    process_input(input_text, output_dir)