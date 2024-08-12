#include <vector>
#include <chrono>
#include <fstream>
#include <functional>
#include <string>
#include <cstdio>

#include "../../include/utils.hpp"
#include "../../include/vector_algorithms.hpp"
#include "../../include/benchmark_base.hpp"

int main() {
    std::vector<size_t> sizes = {
        16,
        256,
        4096,
        65536,
        262144
    };

    printf("Vector benchmarks\n");

    for (auto size : sizes) {
        std::vector<float> dataFA = generateRandomVector<float>(size, 0.0f, 1.0f);
        std::vector<float> dataFB = generateRandomVector<float>(size, 0.0f, 1.0f);
        std::vector<int> dataIA = generateRandomVector<int>(size, 0, 1000);
        std::vector<int> dataIB = generateRandomVector<int>(size, 0, 1000);

        printf("\n");
        printf("Size: %zu\n", size);

        printf("Test data:\n");
        printf("Float Vector A:\n");
        printVector(dataFA);

        printf("Float Vector B:\n");
        printVector(dataFB);

        printf("Int Vector A:\n");
        printVector(dataIA);

        printf("Int Vector B:\n");
        printVector(dataIB);

        printf("\n");
        printf("Execution times:\n");

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

    return 0;
}