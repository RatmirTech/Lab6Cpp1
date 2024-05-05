#include "tools.h"
#include <iostream>

// Функция approximatelyEqual сравнивает два числа с заданной точностью epsilon
bool approximatelyEqual(double a, double b, double epsilon) {
	return std::fabs(a - b) <= epsilon;
}

// Функция approximatelyEqualAbsRel сравнивает два числа с заданными absEpsilon и relEpsilon
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) {
	double diff = std::fabs(a - b);
	if (diff <= absEpsilon) return true;
	return diff <= (std::max(std::fabs(a), std::fabs(b)) * relEpsilon);
}
