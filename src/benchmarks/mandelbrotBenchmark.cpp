#include <vector>

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

	std::cout << "Mandelbrot benchmarks" << std::endl;

	for (auto iterations : maxIterations) {

		std::cout << std::endl;
		std::cout << "Size: " << iterations << std::endl;

		std::cout << std::endl;
		std::cout << "Execution times: " << std::endl;

		benchmarkAndSave("mandelbrot", "none", iterations,
			[&iterations]() { return mandelbrot(800, 600, iterations); });
	}
}