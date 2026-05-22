#include <iostream>
#include <vector>
#include <string>
#include <string_view>

template <typename T>
bool isValueInArray(const std::vector<T>& vector, const T& value_to_find) {
	for (const auto& value : vector) if (value == value_to_find) return true;
	return false;
}

int main() {
	std::vector<std::string_view> names {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
	std::cout << "Enter a name: ";
	std::string name_to_find {};
	std::cin >> name_to_find;
	std::cout << name_to_find << " was ";
	if (!(isValueInArray<std::string_view>(names, name_to_find))) std::cout << "not ";
	std::cout << "found.\n";
	return 0;
}
