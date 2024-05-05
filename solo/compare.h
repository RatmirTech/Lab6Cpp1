#pragma once
#include <cstdint>

bool approximatelyEqual(float a, float b, float epsilon);
bool approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon);
bool isValidFloat(const char* str);
bool compare_bit_sequences(uint64_t num1, uint64_t num2, int start1, int end1, int start2, int end2);