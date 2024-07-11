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

int* generateIntArray(int size) {
	int* array = new int[size];
	std::uniform_int_distribution<int> dist(0, 1000);

	for (int i = 0; i < size; i++) {
		array[i] = dist(rng);
	}

	return array;
}

float* gererateFloatArray(int size) {
	float* array = new float[size];
	std::uniform_real_distribution<float> dist(0.0f, 1.0f);

	for (int i = 0; i < size; i++) {
		array[i] = dist(rng);
	}

	return array;
}
