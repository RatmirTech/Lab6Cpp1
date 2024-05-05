#include "task13.h"
#include <iostream>
#include <bitset>

using namespace std;

uint64_t rotateOddBitsRight(uint64_t num, unsigned int shift) {
	uint64_t oddMask = 0xAAAAAAAAAAAAAAAA; // ����� ��� �������� ����� (0b10101010...)
	uint64_t oddBits = num & oddMask; // ���������� �������� �����
	shift %= 32; // ����������� ����� ������� ���� �� �������� 32 �������

	// ����������� ����� ������
	oddBits = (oddBits >> shift) | (oddBits << (64 - shift));
	oddBits &= oddMask; // ��������� ������ �������� ����

	return (num & ~oddMask) | oddBits; // ���������� ����� � ���������� ��������� ������
}

int main() {
	uint64_t number;
	unsigned int shift;
	std::cout << "������� ����� � ���������� ����� ��� ������: ";
	std::cin >> number >> shift;

	uint64_t result = rotateOddBitsRight(number, shift);
	std::cout << "��������� ����� ������ �������� �����: " << result << std::endl;

	return 0;
}

int init13(int argc, char* argv[]) {
	// �������� ���������� ����������
	if (argc < 5) {
		std::cout << "������������ ����������. �������������:\n";
		std::cout << argv[0] << " <function_name> <number1> <number2> <epsilon> [<relEpsilon>]\n";
		return 1;
	}

	std::string function_name = argv[1];
	char* end;
	double number1 = std::strtod(argv[2], &end);
	if (*end) {
		std::cout << "������ �������� ������ ���� ������. �������: " << argv[2] << "\n";
		return 1;
	}

	double number2 = std::strtod(argv[3], &end);
	if (*end) {
		std::cout << "������ �������� ������ ���� ������. �������: " << argv[3] << "\n";
		return 1;
	}

	double epsilon = std::strtod(argv[4], &end);
	if (*end) {
		std::cout << "��������� �������� ������ ���� ������. �������: " << argv[4] << "\n";
		return 1;
	}

	// ���������, ����� ������� ������������ � ��������� ���������
	if (function_name == "approximatelyEqual") {
		if (argc != 5) {
			std::cout << "��� ������� approximatelyEqual ��������� ����� 4 ���������.\n";
			return 1;
		}
		bool result = approximatelyEqual(number1, number2, epsilon);
		std::cout << "����� " << number1 << " � " << number2 << (result ? " �����.\n" : " �������.\n");
	}
	else if (function_name == "approximatelyEqualAbsRel") {
		if (argc != 6) {
			std::cout << "��� ������� approximatelyEqualAbsRel ��������� ����� 5 ����������.\n";
			return 1;
		}
		double relEpsilon = std::strtod(argv[5], &end);
		if (*end) {
			std::cout << "����� �������� ������ ���� ������. �������: " << argv[5] << "\n";
			return 1;
		}
		bool result = approximatelyEqualAbsRel(number1, number2, epsilon, relEpsilon);
		std::cout << "����� " << number1 << " � " << number2 << (result ? " �����.\n" : " �������.\n");
	}
	else {
		std::cout << "����������� ��� �������: " << function_name << ". ����������� 'approximatelyEqual' ��� 'approximatelyEqualAbsRel'.\n";
		return 1;
	}

	return 0;
}