#include <iostream>
#include <vector>
#include <limits>

template<typename T>
int getIndexAtElement(std::vector<T>& vector, T element) {

	for (std::size_t i {0}; i < vector.size(); ++i) {
		if (vector[i] == element) return static_cast<int>(i);
	}
	
	return -1;
}

template <typename T>
void printArray(std::vector<T>& vector) {

	for (std::size_t i {0}; i < vector.size(); ++i) {
		std::cout << vector[i] << ' ';
	}
	
	std::cout << '\n';
}

int getInt() {
	int num {};

	do {
		std::cout << "Enter a number between 1 and 9: ";
		std::cin >> num;

		if (!std::cin) std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while (num < 1 || num > 9);
	return num;
}

int main() {
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
	int num {getInt()};
	printArray(arr);
	int index {getIndexAtElement(arr, num)};

	std::cout << "The number " << num;
	if (index < 0) std::cout << " was not found\n";
	else std::cout << " has index " << index << '\n';
    return 0;
}
