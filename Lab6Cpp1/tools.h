#pragma once

// Функция approximatelyEqual сравнивает два числа с заданной точностью epsilon
bool approximatelyEqual(double a, double b, double epsilon);

// Функция approximatelyEqualAbsRel сравнивает два числа с заданными absEpsilon и relEpsilon
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon);