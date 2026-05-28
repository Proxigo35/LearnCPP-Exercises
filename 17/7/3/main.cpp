#include <iostream>

int main() {

	constexpr int perfectSquares[] {0, 1, 4, 9};

	while (true) {
		std::cout << "Enter a single digit integer, or -1 to quit: ";
		int num {};
		std::cin >> num;

		if (num == -1) {
			std::cout << "Bye\n";
			break;
		}
		bool squareFound {false};

		std::cout << num << " is";
		for (int perfectSquare : perfectSquares) {
			if (num == perfectSquare) {
				squareFound = true;
				break;
			}
		}
		std::cout << (squareFound ? "" : " not") << " a perfect square\n\n";
	}

	return 0;
}
