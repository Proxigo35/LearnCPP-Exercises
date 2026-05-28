#include <iostream>

void print(const char string[]) {
	const char* ptr {string};
	while (*ptr != '\0') ++ptr;
	while (ptr-- != string) std::cout << *ptr;
}

int main() {
	print("Hello, world!");
	std::cout << '\n';
	return 0;
}
