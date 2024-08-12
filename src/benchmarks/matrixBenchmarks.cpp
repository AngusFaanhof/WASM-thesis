#include <vector>
#include <chrono>
#include <fstream>
#include <functional>
#include <string>
#include <cstdio>

#include "../../include/utils.hpp"
#include "../../include/matrix_algorithms.hpp"
#include "../../include/benchmark_base.hpp"

int main() {
    std::vector<size_t> sizes = {
        4,
        16,
        64,
        256,
        512
    };

    printf("Matrix benchmarks\n");

    for (auto size : sizes) {
        std::vector<float> matrixFA = generateRandomVector<float>(size * size, 0.0f, 1.0f);
        std::vector<float> matrixFB = generateRandomVector<float>(size * size, 0.0f, 1.0f);
        std::vector<int> matrixIA = generateRandomVector<int>(size * size, 0, 1000);
        std::vector<int> matrixIB = generateRandomVector<int>(size * size, 0, 1000);

        printf("\n");
        printf("Size: %zu\n", size);

        printf("Test data:\n");
        printf("Float Matrix A:\n");
        printMatrix(matrixFA);

        printf("Float Matrix B:\n");
        printMatrix(matrixFB);

        printf("Int Matrix A:\n");
        printMatrix(matrixIA);

        printf("Int Matrix B:\n");
        printMatrix(matrixIB);

        printf("\n");
        printf("Execution times:\n");

        // Benchmark transposeMatrix (float)
        benchmarkAndSave("transposeMatrix", "float", size,
            [&matrixFA, size]() { return transposeMatrix(matrixFA, size); });

        // Benchmark transposeMatrix (int)
        benchmarkAndSave("transposeMatrix", "int", size,
            [&matrixIA, size]() { return transposeMatrix(matrixIA, size); });

        // Benchmark multiplyMatrices (float)
        benchmarkAndSave("multiplyMatrices", "float", size,
            [&matrixFA, &matrixFB, size]() { return multiplyMatrices(matrixFA, matrixFB, size); });

        // Benchmark multiplyMatrices (int)
        benchmarkAndSave("multiplyMatrices", "int", size,
            [&matrixIA, &matrixIB, size]() { return multiplyMatrices(matrixIA, matrixIB, size); });
    }

    return 0;
}