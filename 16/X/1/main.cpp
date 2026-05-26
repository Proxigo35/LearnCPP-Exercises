#include <vector>
#include <string_view>

int main() {
	std::vector v1 {2, 4, 6, 8, 10, 12};
	const std::vector v2 {1.2, 3.4, 5.6, 7.8};
	const std::vector<std::string_view> v3 {"Alex", "Brad", "Charles", "Dave"};
	std::vector v4 {12};
	std::vector<int> v5 (12);
}
