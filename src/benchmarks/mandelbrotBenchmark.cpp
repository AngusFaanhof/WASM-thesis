#include <vector>
#include <cstdio>

#include "../../include/utils.hpp"
#include "../../include/benchmark_base.hpp"
#include "../../include/mandelbrot.hpp"

int main() {
    std::vector<int> maxIterations = {
        16,
        64,
        256,
        1024,
        4096
    };

    printf("Mandelbrot benchmarks\n");

    for (auto iterations : maxIterations) {
        printf("\n");
        printf("Size: %d\n", iterations);

        printf("\n");
        printf("Execution times:\n");

        benchmarkAndSave("mandelbrot", "none", iterations,
            [&iterations]() { return mandelbrot(800, 600, iterations); });
    }
}