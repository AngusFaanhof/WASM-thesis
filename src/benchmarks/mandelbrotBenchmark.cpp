#include <vector>

#include "../utils.hpp"
#include "../benchmark_base.hpp"
#include "mandelbrot.hpp"

int main() {
	std::vector<int> maxIterations = { 100, 200, 300 };

	for (auto iterations : maxIterations) {
		// std::cout << iterations << std::endl;
		benchmarkAndSave("mandelbrot", "none", iterations,
			[&iterations]() { return mandelbrot(800, 600, iterations); });
	}
}