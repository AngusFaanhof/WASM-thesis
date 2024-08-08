#ifndef BENCHMARK_BASE_HPP
#define BENCHMARK_BASE_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <functional>
#include <string>

#include "utils.hpp"

const int NUM_RUNS = 50;

template<typename Func, typename... Args>
std::vector<long long> runBenchmark(Func func, Args&&... args) {
	std::vector<long long> executionTimes;
	for (int i = 0; i < NUM_RUNS; i++) {
		auto start = std::chrono::high_resolution_clock::now();

		func(std::forward<Args>(args)...);

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		executionTimes.push_back(duration.count());
	}

	return executionTimes;
}

// Function to run benchmark and save results
template<typename Func, typename... Args>
void benchmarkAndSave(const std::string& algorithmName, const std::string& dataType, size_t size, Func func, Args&&... args) {
	auto executionTimes = runBenchmark(func, std::forward<Args>(args)...);
	std::string fileName = getFileName(algorithmName, dataType, size);

	// Execution times for {algorithmName} ({dataType}):
	// [time1, time2, time3, ...]

	std::cout << algorithmName << " (" << dataType << ")" << std::endl;
	std::cout << '[';

	for (int i = 0; i < executionTimes.size() - 1; i++) {
		std::cout << executionTimes[i] << ", ";
	}
	std::cout << executionTimes[executionTimes.size() - 1] << ']' << std::endl;
}

#endif // BENCHMARK_BASE_HPP