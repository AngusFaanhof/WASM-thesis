#include <vector>

#include "../utils.hpp"
#include "../benchmark_base.hpp"
#include "mandelbrot.hpp"

int main() {
	std::vector<int> maxIterations = {
		16,
		64,
		256,
		1024,
		4096
	};

	for (auto iterations : maxIterations) {
		// std::cout << iterations << std::endl;
		benchmarkAndSave("mandelbrot", "none", iterations,
			[&iterations]() { return mandelbrot(800, 600, iterations); });
	}
}