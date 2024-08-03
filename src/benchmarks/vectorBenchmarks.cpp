#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <functional>
#include <string>

#include "../utils.hpp"
#include "vector_algorithms.hpp"
#include "../benchmark_base.hpp"

int main() {
    std::vector<size_t> sizes = {
		16,
		256,
		4096,
		65536,
		262144
	};

	std::cout << "Vector algorithms" << std::endl;

	std::vector<std::vector<float>> floatVectorsA;
    std::vector<std::vector<float>> floatVectorsB;
    std::vector<std::vector<int>> intVectorsA;
    std::vector<std::vector<int>> intVectorsB;

    for (auto size : sizes) {
        std::vector<float> dataFA = generateRandomVector<float>(size, 0.0f, 1.0f);
        std::vector<float> dataFB = generateRandomVector<float>(size, 0.0f, 1.0f);
        std::vector<int> dataIA = generateRandomVector<int>(size, 0, 1000);
        std::vector<int> dataIB = generateRandomVector<int>(size, 0, 1000);

		// std::cout << "\n\n" << dataFA[0] << std::endl;
		// break;

		floatVectorsA.push_back(dataFA);
        floatVectorsB.push_back(dataFB);
        intVectorsA.push_back(dataIA);
        intVectorsB.push_back(dataIB);


        // Benchmark normalizeVector (float)
        benchmarkAndSave("normalizeVector", "float", size,
            [&dataFA]() { return normalizeVector(dataFA); });

        // Benchmark averageVector (float)
        benchmarkAndSave("averageVector", "float", size,
            [&dataFA]() { return averageVector(dataFA); });

        // Benchmark dotProduct (float)
        benchmarkAndSave("vectorDotProduct", "float", size,
            [&dataFA, &dataFB]() { return dotProduct(dataFA, dataFB); });

        // Benchmark vectorAddition (float)
        benchmarkAndSave("vectorAddition", "float", size,
            [&dataFA, &dataFB]() { return vectorAddition(dataFA, dataFB); });

        // Benchmark normalizeVector (int)
        benchmarkAndSave("normalizeVector", "int", size,
            [&dataIA]() { return normalizeVector(dataIA); });

        // Benchmark averageVector (int)
        benchmarkAndSave("averageVector", "int", size,
            [&dataIA]() { return averageVector(dataIA); });

        // Benchmark dotProduct (int)
        benchmarkAndSave("vectorDotProduct", "int", size,
            [&dataIA, &dataIB]() { return dotProduct(dataIA, dataIB); });

        // Benchmark vectorAddition (int)
        benchmarkAndSave("vectorAddition", "int", size,
            [&dataIA, &dataIB]() { return vectorAddition(dataIA, dataIB); });
    }

	std::cout << "Test data: " << std::endl;

	// print floatVectorsA
	std::cout << "floatVectorsA: " << std::endl;
	for (int i = 0; i < floatVectorsA.size(); i++) {
		std::cout << "size: " << sizes.at(i) << std::endl;

		printVector(floatVectorsA.at(i));
	}

	// print floatVectorsB
	std::cout << "floatVectorsB: " << std::endl;
	for (int i = 0; i < floatVectorsB.size(); i++) {
		std::cout << "size: " << sizes.at(i) << std::endl;

		printVector(floatVectorsB.at(i));
	}

	// print intVectorsA
	std::cout << "intVectorsA: " << std::endl;
	for (int i = 0; i < intVectorsA.size(); i++) {
		std::cout << "size: " << sizes.at(i) << std::endl;

		printVector(intVectorsA.at(i));
	}

	// print intVectorsB
	std::cout << "intVectorsB: " << std::endl;
	for (int i = 0; i < intVectorsB.size(); i++) {
		std::cout << "size: " << sizes.at(i) << std::endl;

		printVector(intVectorsB.at(i));
	}

    return 0;
}