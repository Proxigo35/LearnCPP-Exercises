#include <iostream>
#include <vector>
#include <string>
#include <string_view>

int main() {

	std::vector<std::string_view> names {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
	std::cout << "Enter a name: ";
	std::string name_to_find {};
	std::cin >> name_to_find;
	std::cout << name_to_find << " was ";
	bool found {false};

	for (const auto name : names) {
		if (name == name_to_find) {
			found = true;
			break;
		}
	}

	if (!found) std::cout << "not ";
	std::cout << "found.\n";
	return 0;
}
