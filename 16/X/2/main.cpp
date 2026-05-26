#include <iostream>
#include <vector>
#include <cassert>

namespace Items {
	enum Type {
		health_potions,
		torches,
		arrows,
		max_items
	};
};

int get_element_count(const std::vector<int>& vector) {
	int num_elements {0};
	for (const auto& element : vector) num_elements += element;
	return num_elements;
}

std::string_view get_item_string(Items::Type item) {
	switch (item) {
	case Items::health_potions: return "health potion";
	case Items::torches: return "torch";
	case Items::arrows: return "arrow";
	default: return "???";
	}
}

int main() {
	std::vector<int> items {1, 5, 10};
	assert(items.size() == Items::max_items);

	for (std::size_t i {0}; i < items.size(); ++i) {
		std::cout << "You have " << items[i] << ' ' << get_item_string(static_cast<Items::Type>(i));
		if (items[i] > 1) std::cout << 's';
		std::cout << '\n';
	}

	std::cout << "You have " <<  get_element_count(items) << " total items";
	
	return 0;
}
