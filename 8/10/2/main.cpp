#include <iostream>

int sumTo(int value) {
	int copy {0};
	for (int i {1}; i <= value; i++) copy += i;
	return copy;
}

int main() {

	std::cout << sumTo(10) << '\n';	

	return 1;
}
