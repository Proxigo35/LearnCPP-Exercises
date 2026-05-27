#include <iostream>
#include <array>

int main() {
	constexpr std::array array {'h', 'e', 'l', 'l', 'o'};
	std::cout << "The length is " << array.size() << '\n';
	std::cout << array[1];
	std::cout << array.at(1);
	std::cout << std::get<1>(array);
	std::cout << '\n';

	return 0;
}
