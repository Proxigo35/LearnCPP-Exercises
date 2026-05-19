#include <iostream>

int main() {
	int num{};

	std::cout << "Enter a digit form 0 to 9 inclusive: ";
	std::cin >> num;

	if (num == 2) {
		std::cout << "The digit is prime.\n";
	}
	else if (num == 3) {
		std::cout << "The digit is prime.\n";
	}
	else if (num == 5) {
		std::cout << "The digit is prime.\n";
	}
	else if (num == 7) {
		std::cout << "The digit is prime.\n";
	} else {
		std::cout << "The digit is not prime.\n";
	}

}
