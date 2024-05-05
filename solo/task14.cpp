#include <iostream>
#include <cstdlib>
#include <cstring>
#include <regex>
#include "compare.h"

using namespace std;
bool isValidUnsignedInt(const char* str) {
    regex unsignedIntRegex(R"(^\d+$)");  // Regular expression for a valid unsigned integer
    return regex_match(str, unsignedIntRegex);
}

bool isValidIndex(const char* str) {
    regex indexRegex(R"(^[1-9]\d*|0$)");
    return regex_match(str, indexRegex);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Использование: <программа> <функция> <число1> <число2> [эпсилон] [absEpsilon relEpsilon]" << endl;
        return 1;
    }

    const char* func = argv[1];
    double num1 = atof(argv[2]);
    double num2 = atof(argv[3]);

    if (strcmp(func, "approximatelyEqual") == 0) {
        if (argc != 5) {
            cerr << "Использование: approximatelyEqual <число1> <число2> <эпсилон>" << endl;
            return 1;
        }
        double epsilon = atof(argv[4]);
        if (double_approximatelyEqual(num1, num2, epsilon)) {
            cout << "Числа приблизительно равны." << endl;
        } else {
            cout << "Числа не приблизительно равны." << endl;
        }
    } else if (strcmp(func, "approximatelyEqualAbsRel") == 0) {
        if (argc != 6) {
            cerr << "Использование: approximatelyEqualAbsRel <число1> <число2> <absEpsilon> <relEpsilon>" << endl;
            return 1;
        }
        double absEpsilon = atof(argv[4]);
        double relEpsilon = atof(argv[5]);
        if (double_approximatelyEqualAbsRel(num1, num2, absEpsilon, relEpsilon)) {
            cout << "Числа приблизительно равны." << endl;
        } else {
            cout << "Числа не приблизительно равны." << endl;
        }
    } else {
        cerr << "Неизвестная функция." << endl;
        return 1;
    }

    return 0;
}

// g++ -o Task14 task14.cpp compare.cpp
// ./Task13 approximatelyEqual 10.5 10.6 0.1
// ./Task13 approximatelyEqualAbsRel 100 99.5 0.5 0.01

// # Сравниваем два числа, которые равны с точки зрения эпсилона
// ./MyProgram approximatelyEqual 0.0000001 0.0000002 0.0001

// # Сравниваем два числа, которые не равны, когда эпсилон слишком мал
// ./MyProgram approximatelyEqual 0.0001 0.0002 0.00001

// # Сравниваем два числа, которые равны с точки зрения как абсолютного, так и относительного эпсилонов
// ./MyProgram approximatelyEqualAbsRel 1000 999 1 0.01

// # Сравниваем два числа, которые не равны, когда относительный эпсилон слишком мал
// ./MyProgram approximatelyEqualAbsRel 1000 999 0.5 0.0001

// # Сравниваем очень маленькие числа, где абсолютный эпсилон важнее
// ./MyProgram approximatelyEqualAbsRel 1e-50 1.1e-50 1e-49 1e-3

// # Числа 1.2e-50 и 1.1e-50 считаются равными при достаточно больших эпсилонах
// > C:\>MyProgram approximatelyEqualAbsRel 1.2e-50 1.1e-50 1e-6 1e-3
// > Числа 1.2e-50 и 1.1e-50 равны.

// # Числа 1.2e-50 и 1.1e-50 считаются неравными при слишком малых эпсилонах
// > C:\>MyProgram approximatelyEqualAbsRel 1.2e-50 1.1e-50 1e-66 1e-63
// > Числа 1.2e-50 и 1.1e-50 неравны.