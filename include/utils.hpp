#ifndef UTILS_HPP
#define UTILS_HPP

#include <random>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

template<typename T>
void printVector(std::vector<T> vector) {
    for (size_t i = 0; i < vector.size(); i++) {
        if (i == vector.size() - 1)
            printf("%g", static_cast<double>(vector[i]));
        else
            printf("%g,", static_cast<double>(vector[i]));
    }
    printf("\n");
}

template<typename T>
std::vector<T> generateRandomVector(size_t size, T min, T max) {
    std::vector<T> data(size);
    std::mt19937 rng(time(NULL));

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

void saveToCSV(std::vector<long long> times, std::string name);

std::string getFileName(std::string method, std::string type, size_t size);

#endif // UTILS_HPP