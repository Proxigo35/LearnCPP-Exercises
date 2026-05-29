#include <iostream>
#include <utility>

int main() {
	int array[] {6, 3, 2, 9, 7, 1, 5, 4, 8};

	for (int iteration {0}; iteration < static_cast<int>(std::size(array)) - 1; ++iteration) {
		bool swapped {false};
		for (std::size_t i {0}; static_cast<int>(i) < (static_cast<int>(std::size(array)) - 1) - iteration; ++i) { 
			if (array[i] > array[i + 1]) {
				std::swap(array[i], array[i + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			std::cout << "Early termination on iteration " << iteration + 1 << '\n';
			break;
		}
	}

	for (const auto& element : array) std::cout << element << ' ';
	std::cout << '\n';

	return 0;
}
