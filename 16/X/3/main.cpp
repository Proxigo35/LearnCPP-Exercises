#include <iostream>
#include <vector>
#include <utility>

template <typename T>
std::pair<std::size_t, std::size_t> get_min_max(std::vector<T>& vector) {

	std::cout << "With array ( ";
	for (const auto& element : vector) std::cout << element << ' ';
	std::cout << "):\n";

	std::size_t min {0};
	std::size_t max {0};

	for (std::size_t i {0}; i < vector.size(); ++i) {
		if (vector[i] < vector[min]) min = i;
		if (vector[i] > vector[max]) max = i;
	}

	return std::pair<std::size_t, std::size_t> (min, max);
}

int main() {
	
	std::vector v1 {3, 8, 2, 5, 7, 8, 3};
	std::pair<std::size_t, std::size_t> min_max_v1 (get_min_max(v1));
	std::cout << "The min element has index " << min_max_v1.first << " and value " << v1[min_max_v1.first] << '\n';
	std::cout << "The max element has index " << min_max_v1.second << " and value " << v1[min_max_v1.second] << '\n';

	std::cout << '\n';

	std::vector v2 {5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6};
	std::pair<std::size_t, std::size_t> min_max_v2 (get_min_max(v2));
	std::cout << "The min element has index " << min_max_v2.first << " and value " << v2[min_max_v2.first] << '\n';
	std::cout << "The max element has index " << min_max_v2.second << " and value " << v2[min_max_v2.second] << '\n';

	return 0;
}
