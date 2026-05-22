#include <iostream>
#include <vector>

int main() {
	std::vector vector {'h', 'e', 'l', 'l', 'o'};
	std::cout << "The array has " << std::size(vector) << " elements.\n";
	std::cout << vector[1] << vector.at(1);
}
