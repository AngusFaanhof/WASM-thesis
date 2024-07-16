#include <random>
#include <iostream>

#include "../include/helpers.h"

std::mt19937 rng(time(NULL));

void printArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		if (i == size - 1)
			std::cout << array[i];
		else
			std::cout << array[i] << ",";
	}
}

void printArray(float* array, int size) {
	for (int i = 0; i < size; i++) {
		if (i == size - 1)
			std::cout << array[i];
		else
			std::cout << array[i] << ",";
	}

}


template<typename T>
std::vector<T> generateData(size_t size, <T> min, <T> max) {
    std::vector<T> data(size);

    if constexpr (std::is_same_v<T, int>) {
        std::uniform_int_distribution<int> dist(min, max);
        std::generate(data.begin(), data.end(), [&]() { return dist(rng); });
    }
	else if constexpr (std::is_same_v<T, float>) {
        std::uniform_real_distribution<float> dist(min, max);
        std::generate(data.begin(), data.end(), [&]() { return dist(rng); });
    }
    return data;
}
