#include "compare.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <regex>
bool approximatelyEqual(float a, float b, float epsilon) {

    return std::fabs(a - b) <= epsilon;
}

bool approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon) {
    return std::fabs(a - b) <= std::max(absEpsilon, std::fabs(a) * relEpsilon);
}

bool isValidFloat(const char* str) {
    std::regex floatRegex(R"(^[+-]?(?:(?:\d+\.\d*|\.\d+|\d+)(?:[eE][+-]?\d+)?|\d+[eE][+-]?\d+)$)");
    return std::regex_match(str, floatRegex);
}

bool compare_bit_sequences(uint64_t num1, uint64_t num2, int start1, int end1, int start2, int end2) {
    uint64_t mask1 = (1ULL << (end1 - start1 + 1)) - 1;
    uint64_t mask2 = (1ULL << (end2 - start2 + 1)) - 1;

    mask1 <<= start1;
    mask2 <<= start2;

    uint64_t sequence1 = (num1 & mask1) >> start1;
    uint64_t sequence2 = (num2 & mask2) >> start2;

    return sequence1 == sequence2;
}