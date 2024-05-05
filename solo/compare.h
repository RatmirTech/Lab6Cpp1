#pragma once
#include <cstdint>

bool float_approximatelyEqual(float a, float b, float epsilon);
bool float_approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon);

bool isValidFloat(const char* str);

bool double_approximatelyEqual(double a, double b, double epsilon);
bool double_approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon);