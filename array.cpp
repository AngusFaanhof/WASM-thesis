#include <iostream>
#include <random>

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
	std::mt19937 rng(time(NULL));
	std::uniform_int_distribution<int> dist(0, 1000);

	for (int i = 0; i < size; i++) {
		array[i] = dist(rng);
	}

	return array;
}

float* gererateFloatArray(int size) {
	float* array = new float[size];
	std::mt19937 rng(time(NULL));
	std::uniform_real_distribution<float> dist(0.0f, 1.0f);

	for (int i = 0; i < size; i++) {
		array[i] = dist(rng);
	}

	return array;
}

int main(int argc, char* argv[]) {
	int size = 128;
	int option = 0;

	// size provided as argument
	if (argc > 1)
		size = std::stoi(argv[1]);

	if (argc > 2)
		option = std::stoi(argv[2]);

	// std::mt19937 rng(time(NULL));

	int* matrixA;
	float* matrixB;

	std::cout << "{";
	switch (option) {
		case 0:
			// Integer array
			matrixA = generateIntArray(size);
			printArray(matrixA, size);
			break;
		case 1:
			// Float array
			matrixB = gererateFloatArray(size);
			printArray(matrixB, size);
			break;
	}

	std::cout << "};" << std::endl;

	return 0;
}