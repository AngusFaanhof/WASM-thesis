#include <iostream>
#include <chrono>
#include <immintrin.h>
#include <random>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

std::mt19937 rng(time(NULL));

template<typename T>
std::vector<T> generateData(size_t size) {
    std::vector<T> data(size);

    if constexpr (std::is_same_v<T, int>) {
        std::uniform_int_distribution<int> dist(0, 1000);
        std::generate(data.begin(), data.end(), [&]() { return dist(rng); });
    }
	else if constexpr (std::is_same_v<T, float>) {
        std::uniform_real_distribution<float> dist(0.0f, 1.0f);
        std::generate(data.begin(), data.end(), [&]() { return dist(rng); });
    }
    return data;
}

float average(float* data, size_t dataSize) {
    __m128 sumVector = _mm_setzero_ps();

    for (size_t i = 0; i < dataSize; i += 4) {
        __m128 values = _mm_loadu_ps(&data[i]);

        sumVector = _mm_add_ps(sumVector, values);
    }

    float sum = 0.0f;
    float temp[4];

    _mm_storeu_ps(temp, sumVector);
    for (size_t j = 0; j < 4; ++j) {
        sum += temp[j];
    }

    return sum / dataSize;
}

int average(int* data, size_t dataSize) {
	__m128i sumVector = _mm_setzero_si128();

	for (size_t i = 0; i < dataSize; i += 4) {
		__m128i values = _mm_loadu_si128((__m128i*)&data[i]);

		sumVector = _mm_add_epi32(sumVector, values);
	}

	int sum = 0;
	int temp[4];

	_mm_storeu_si128((__m128i*)temp, sumVector);
	for (size_t j = 0; j < 4; ++j) {
		sum += temp[j];
	}

	return sum / dataSize;
}

template<typename T>
std::vector<long long> averageMicroBenchmark(const std::vector<T>& data, int iterations) {
	std::vector<long long> results(iterations);

	for (int i = 0; i < iterations; i++) {
		auto start = std::chrono::high_resolution_clock::now();

		average((T*)data.data(), data.size());

		auto end = std::chrono::high_resolution_clock::now();

		results[i] = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	}

	return results;
}

template<typename T>
void saveToCSV(const std::vector<T>& data, const std::vector<long long>& results, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    // Write header
    file << "Data,Time (ns)\n";

    // Write data and results
    size_t resultStart = std::min(size_t(2), results.size());  // Skip first two entries if available
    for (size_t i = 0; i < data.size(); ++i) {
        file << std::setprecision(9) << std::fixed << data[i] << ",";
        if (i < results.size() - resultStart) {
            file << results[i + resultStart];
        }
        file << "\n";
    }

    file.close();
}

int main() {
	size_t sizes[3] = {1024, 65536, 1048576};
	char** sizeCategories = {"Small", "Medium", "Large"};
	size_t size = sizes[2];
	int iterations = 1000;

	auto dataInt = generateData<int>(size);
	auto dataFloat = generateData<float>(size);

	auto resultsInt = averageMicroBenchmark(dataInt, iterations);
	auto resultsFloat = averageMicroBenchmark(dataFloat, iterations);

	// Save integer results
	std::string filenameInt = "average_int_" + std::to_string(size) + ".csv";
	saveToCSV(dataInt, resultsInt, filenameInt);

	// Save float results
	std::string filenameFloat = "average_float_" + std::to_string(size) + ".csv";
	saveToCSV(dataFloat, resultsFloat, filenameFloat);

    return 0;
}