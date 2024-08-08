import sys
import os
import re
import csv

def parse_input(input_text):
    data = {}
    sections = input_text.split('\n\n')
    current_size = None
    benchmark_category = None

    for section in sections:
        if section.startswith("Vector benchmarks"):
            benchmark_category = "Vector"
        elif section.startswith("Matrix benchmarks"):
            benchmark_category = "Matrix"
        elif section.startswith("Mandelbrot benchmarks"):
            benchmark_category = "Mandelbrot"

        elif section.startswith("Size: ") and benchmark_category == "Mandelbrot":
            current_size = int(section.split(': ')[1].split('\n')[0])
            data[current_size] = {'execution_times': {}}
            data[current_size]['test_data'] = {}

        elif section.startswith("Size: ") and benchmark_category != "Mandelbrot":
            current_size = int(section.split(': ')[1].split('\n')[0])
            data[current_size] = {'test_data': {}, 'execution_times': {}}
            sub_sections = section.split('\n')
            test_data = None
            values = None

            for sub_section in section.split('\n')[2:]:

                if sub_section.endswith(': '):
                    values = sub_section[:-2]

                else:
                    test_data = eval("[" + sub_section + "]")
                    data[current_size]['test_data'][values] = test_data


        elif section.startswith("Execution times:"):
            algorihm = None
            times = None

            for sub_section in section.split('\n')[1:]:
                if not sub_section.startswith('['):
                    algorithm = sub_section

                if sub_section.startswith('['):
                    times = eval(sub_section)
                    data[current_size]['execution_times'][algorithm] = times

        else:
            print(section)

    return data


def save_csv(data, runtime, output_dir):
    # print(data.items())
    for size, size_data in data.items():
        # Save test data
        for algorithm, values in size_data['test_data'].items():
            if 'Float' in algorithm:
                datatype = 'float'
            elif 'Int' in algorithm:
                datatype = 'int'
            elif "none" in algorithm:
                datatype = ''

            filename = f"{output_dir}/TestData/{runtime}/{algorithm.replace(' ', '_')}_{size}.csv".replace('(none)', '')
            os.makedirs(os.path.dirname(filename), exist_ok=True)
            with open(filename, 'w', newline='') as f:
                writer = csv.writer(f, lineterminator='')
                writer.writerow(values)

        # Save execution times
        for algorithm, times in size_data['execution_times'].items():
            match = re.match(r'(\w+)\s*\((\w+)\)', algorithm)
            if match:
                algo_name, datatype = match.groups()
                filename = f"{output_dir}/Results/{runtime}/{algo_name}_{datatype}_{size}.csv"
                if datatype == 'none':
                    filename = f"{output_dir}/Results/{runtime}/{algo_name}_{size}.csv"
                os.makedirs(os.path.dirname(filename), exist_ok=True)
                with open(filename, 'w', newline='') as f:
                    writer = csv.writer(f, lineterminator='')
                    writer.writerow(times)

def main():
    if len(sys.argv) != 2:
        print("Usage: python script.py <runtime>")
        sys.exit(1)

    runtime = sys.argv[1]
    input_text = sys.stdin.read()

    data = parse_input(input_text)
    save_csv(data, runtime, '.')

if __name__ == "__main__":
    main()