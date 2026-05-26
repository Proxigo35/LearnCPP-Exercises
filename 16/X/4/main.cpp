#include <iostream>
#include <vector>
#include <utility>

template <typename T>
std::pair<std::size_t, std::size_t> get_min_max(std::vector<T>& vector) {

	std::size_t min {0};
	std::size_t max {0};

	for (std::size_t i {0}; i < vector.size(); ++i) {
		if (vector[i] < vector[min]) min = i;
		if (vector[i] > vector[max]) max = i;
	}

	return std::pair<std::size_t, std::size_t> (min, max);
}

int main() {
	
	std::cout << "Enter numbers to add (use -1 to stop): ";
	std::vector<int> v {};

	while (true) {
		int num {};
		std::cin >> num;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (num == -1) break;
		v.push_back(num);
	}

	std::pair<std::size_t, std::size_t> min_max_v1 (get_min_max(v));
	std::cout << "With array ( ";

	for (std::size_t i {0}; i < v.size(); ++i) {
		std::cout << v[i];
		if (i < v.size() - 1) std::cout << ", ";
	}

	std::cout << " ):\nThe min element has index " << min_max_v1.first << " and value " << v[min_max_v1.first] << '\n';
	std::cout << "The max element has index " << min_max_v1.second << " and value " << v[min_max_v1.second] << '\n';

	return 0;
}
