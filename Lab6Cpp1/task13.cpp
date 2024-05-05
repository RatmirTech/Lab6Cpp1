#include "task13.h"
#include <iostream>
#include <bitset>

using namespace std;

uint64_t rotateOddBitsRight(uint64_t num, unsigned int shift) {
	uint64_t oddMask = 0xAAAAAAAAAAAAAAAA; // Маска для нечётных битов (0b10101010...)
	uint64_t oddBits = num & oddMask; // Извлечение нечётных битов
	shift %= 32; // Циклический сдвиг каждого бита на максимум 32 позиции

	// Циклический сдвиг вправо
	oddBits = (oddBits >> shift) | (oddBits << (64 - shift));
	oddBits &= oddMask; // Сохраняем только нечётные биты

	return (num & ~oddMask) | oddBits; // Возвращаем число с изменёнными нечётными битами
}

int main() {
	uint64_t number;
	unsigned int shift;
	std::cout << "Введите число и количество битов для сдвига: ";
	std::cin >> number >> shift;

	uint64_t result = rotateOddBitsRight(number, shift);
	std::cout << "Результат после сдвига нечётных битов: " << result << std::endl;

	return 0;
}

int init13(int argc, char* argv[]) {
	// Проверка количества аргументов
	if (argc < 5) {
		std::cout << "Недостаточно параметров. Использование:\n";
		std::cout << argv[0] << " <function_name> <number1> <number2> <epsilon> [<relEpsilon>]\n";
		return 1;
	}

	std::string function_name = argv[1];
	char* end;
	double number1 = std::strtod(argv[2], &end);
	if (*end) {
		std::cout << "Второй параметр должен быть числом. Введено: " << argv[2] << "\n";
		return 1;
	}

	double number2 = std::strtod(argv[3], &end);
	if (*end) {
		std::cout << "Третий параметр должен быть числом. Введено: " << argv[3] << "\n";
		return 1;
	}

	double epsilon = std::strtod(argv[4], &end);
	if (*end) {
		std::cout << "Четвертый параметр должен быть числом. Введено: " << argv[4] << "\n";
		return 1;
	}

	// Проверяем, какую функцию использовать и выполняем сравнение
	if (function_name == "approximatelyEqual") {
		if (argc != 5) {
			std::cout << "Для функции approximatelyEqual требуется ровно 4 параметра.\n";
			return 1;
		}
		bool result = approximatelyEqual(number1, number2, epsilon);
		std::cout << "Числа " << number1 << " и " << number2 << (result ? " равны.\n" : " неравны.\n");
	}
	else if (function_name == "approximatelyEqualAbsRel") {
		if (argc != 6) {
			std::cout << "Для функции approximatelyEqualAbsRel требуется ровно 5 параметров.\n";
			return 1;
		}
		double relEpsilon = std::strtod(argv[5], &end);
		if (*end) {
			std::cout << "Пятый параметр должен быть числом. Введено: " << argv[5] << "\n";
			return 1;
		}
		bool result = approximatelyEqualAbsRel(number1, number2, epsilon, relEpsilon);
		std::cout << "Числа " << number1 << " и " << number2 << (result ? " равны.\n" : " неравны.\n");
	}
	else {
		std::cout << "Неизвестное имя функции: " << function_name << ". Используйте 'approximatelyEqual' или 'approximatelyEqualAbsRel'.\n";
		return 1;
	}

	return 0;
}