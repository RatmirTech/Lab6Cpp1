// #include "tools.h"
// #include <iostream>

// // ������� approximatelyEqual ���������� ��� ����� � �������� ��������� epsilon
// bool approximatelyEqual(double a, double b, double epsilon) {
// 	return std::fabs(a - b) <= epsilon;
// }

// // ������� approximatelyEqualAbsRel ���������� ��� ����� � ��������� absEpsilon � relEpsilon
// bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) {
// 	double diff = std::fabs(a - b);
// 	if (diff <= absEpsilon) return true;
// 	return diff <= (std::max(std::fabs(a), std::fabs(b)) * relEpsilon);
// }
