#include <iostream>

int sumDigits(int num) {
	if (num < 10) return num; 	
	return sumDigits(num / 10) + num % 10;
}

int main() {
	std::cout << sumDigits(93427) << '\n';
	return 0;
}
