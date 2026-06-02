#include <iostream>

int factorial(int num) {
	if (num < 2) return 1;
	return num * factorial(num - 1);
}

int main() {
	for (int i {1}; i < 8; ++i) std::cout << i << "! = " << factorial(i) << '\n';
	return 0;
}
