#include <iostream>

int readNumber() {
	int num{};
	std::cin >> num;
	return num;
}

void writeAnswer(int num) {
	std::cout << num << '\n';
}

int main() {
	writeAnswer(readNumber() + readNumber());
	return 0;
}
