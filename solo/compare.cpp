#include "compare.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <regex>

bool float_approximatelyEqual(float a, float b, float epsilon) {

    return std::fabs(a - b) <= epsilon;
}

bool float_approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon) {
    return std::fabs(a - b) <= std::max(absEpsilon, std::fabs(a) * relEpsilon);
}

bool isValidFloat(const char* str) {
    std::regex floatRegex(R"(^[+-]?(?:(?:\d+\.\d*|\.\d+|\d+)(?:[eE][+-]?\d+)?|\d+[eE][+-]?\d+)$)");
    return std::regex_match(str, floatRegex);
}

bool double_approximatelyEqual(double a, double b, double epsilon) {

    return std::fabs(a - b) <= epsilon;
}

bool double_approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) {
    return std::fabs(a - b) <= std::max(absEpsilon, std::fabs(a) * relEpsilon);
}