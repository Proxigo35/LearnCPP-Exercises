#include <iostream>
#include <array>
#include <string_view>

struct Item {
	std::string_view name {};
	int gold {};
};

int main() {

	constexpr std::array items {
		Item{"sword" , 5},
		Item{"dagger", 3},
		Item{"club", 2},
		Item{"spear", 7}
	};

	for (const auto& item : items) {
		std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
	}

	return 0;
}
