#include <random>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

#include "../include/utils.hpp"

void saveToCSV(std::vector<long long> times, std::string name) {
	std::ofstream file;
	file.open(name + ".csv");

	for (auto time : times) {
		file << time << ',';
	}

	file.close();
}

std::string getFileName(std::string method, std::string type, size_t size) {
	std::string fileName = "./res/" + method + "/" + type + "_" + std::to_string(size);
	return fileName;
}