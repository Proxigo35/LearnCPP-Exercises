#include <iostream>
#include <string_view>
#include <algorithm>

struct Student {
	std::string_view name {};
	int points {};
};

int main() {

	constexpr std::array<Student, 8> arr {
	  { { "Albert", 3 },
		{ "Ben", 5 },
		{ "Christine", 2 },
		{ "Dan", 8 }, // Dan has the most points (8).
		{ "Enchilada", 4 },
		{ "Francis", 1 },
		{ "Greg", 3 },
		{ "Hagrid", 5 } }
	};

	const auto student {
		std::max_element(
			arr.begin(),
			arr.end(),
			[] (const auto& x, const auto& y) {
				return x.points < y.points;
			}
		)
	};

	std::cout << student->name << '\n';

	return 0;
}
