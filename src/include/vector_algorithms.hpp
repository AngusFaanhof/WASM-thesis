#ifndef VECTOR_ALGORITHMS_HPP
#define VECTOR_ALGORITHMS_HPP

#include <vector>

void printVector(const std::vector<float>& vector);

std::vector<float> normalizeVector(std::vector<float>& vec);

std::vector<float> normalizeVector(std::vector<int>& vec);

float averageVector(std::vector<float>& vec);

float averageVector(std::vector<int>& vec);

float dotProduct(std::vector<float>& vecA, std::vector<float>& vecB);

int dotProduct(std::vector<int>& vecA, std::vector<int>& vecB);

std::vector<float> vectorAddition(std::vector<float>& a, std::vector<float>& b);

std::vector<int> vectorAddition(std::vector<int>& a, std::vector<int>& b);

#endif // VECTOR_ALGORITHMS_HPP