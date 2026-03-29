#include <iostream>

void fizzbuzz(int start, int end) {
	for (int i {start}; i <= end; i++) {
		if (i % 3 == 0) std::cout << "fizz";
		if (i % 5 == 0) std::cout << "buzz";
		if (i % 7 == 0) std::cout << "pop";
		if (i % 3 != 0 && i % 5 != 0 && i % 7 != 0) std::cout << i;
		std::cout << '\n';
	}
}

int main () {
	fizzbuzz(104, 106);
	return 0;
}
