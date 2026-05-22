#include <iostream>
#include <vector>
#include <limits>
#include <string_view>

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

template <typename T>
T getValue(std::string_view message, T min, T max) {
	T num {};

	do {
		std::cout << message;
		std::cin >> num;

		if (!std::cin) std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	while (num < min || num > max);
	return num;
}

int main() {
    std::vector arr{4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9};
	auto num {getValue("Enter a value between 1.0 and 10.0: ", 1.0, 10.0)};
	printArray(arr);
	int index {getIndexAtElement(arr, num)};

	std::cout << "The number " << num;
	if (index < 0) std::cout << " was not found\n";
	else std::cout << " has index " << index << '\n';
    return 0;
}
