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
    float num1 = atof(argv[2]);
    float num2 = atof(argv[3]);

    if (strcmp(func, "approximatelyEqual") == 0) {
        if (argc != 5) {
            cerr << "Использование: approximatelyEqual <число1> <число2> <эпсилон>" << endl;
            return 1;
        }
        float epsilon = atof(argv[4]);
        if (approximatelyEqual(num1, num2, epsilon)) {
            cout << "Числа приблизительно равны." << endl;
        } else {
            cout << "Числа не приблизительно равны." << endl;
        }
    } else if (strcmp(func, "approximatelyEqualAbsRel") == 0) {
        if (argc != 6) {
            cerr << "Использование: approximatelyEqualAbsRel <число1> <число2> <absEpsilon> <relEpsilon>" << endl;
            return 1;
        }
        float absEpsilon = atof(argv[4]);
        float relEpsilon = atof(argv[5]);
        if (approximatelyEqualAbsRel(num1, num2, absEpsilon, relEpsilon)) {
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