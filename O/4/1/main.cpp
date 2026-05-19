#include <iostream>
int main() {
	std::cout << "Enter a number between 0 and 255: ";
	int num{};
	std::cin >> num;

	std::cout << (num >= 128 ? (num -= 128, 1) : 0);
	std::cout << (num >= 64 ? (num -= 64, 1) : 0);
	std::cout << (num >= 32 ? (num -= 32, 1) : 0);
	std::cout << (num >= 16 ? (num -= 16, 1) : 0) << ' ';
	std::cout << (num >= 8 ? (num -= 8, 1) : 0);
	std::cout << (num >= 4 ? (num -= 4, 1) : 0);
	std::cout << (num >= 2 ? (num -= 2, 1) : 0);
	std::cout << (num == 1) << '\n';

	return 0;
}
