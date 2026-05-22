#include <iostream>
#include <vector>

template <typename T>
void printArray(std::vector<T>& vector) {

	for (std::size_t i {0}; i < vector.size(); ++i) {
		std::cout << vector[i] << ' ';
	}
}

int main() {
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
	printArray(arr);
    return 0;
}
