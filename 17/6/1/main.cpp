#include <iostream>
#include <array>
#include <string>
#include <string_view>

namespace Animal {

	enum Type {
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		max_animals
	};

	struct Data {
		std::string_view name {};
		int numLegs {};
		std::string_view sound {};
	};
}

void printAnimal(const std::array<Animal::Data, 6>& animals) {
	std::cout << "Enter an animal: ";
	std::string animal_entered {};
	std::cin >> animal_entered;

	std::string animalFound {""};

	for (const auto& animal : animals) {
		if (animal_entered == animal.name) {
			animalFound = animal.name;
			std::cout << "A " << animal.name << " has " << animal.numLegs << " legs and says " << animal.sound << ".\n";
		}
	}

	if (animalFound == "") std::cout << "That animal couldn't be found.\n";
	std::cout << "\nHere is the data for the rest of the animals:\n";

	for (const auto& animal : animals) {
		if (animal.name == animalFound) continue;
		std::cout << "A " << animal.name << " has " << animal.numLegs << " legs and says " << animal.sound << ".\n";
	}
}

int main() {

	std::array<Animal::Data, 6> animals {{
		{"chicken", 2, "bac"},
		{"dog", 4, "woof"},
		{"cat", 2, "meow"},
		{"elephant", 4, "rrrrr"},
		{"duck", 2, "wak"},
		{"snake", 0, "hiss"},
	}};

	static_assert(animals.size() == Animal::max_animals);
	printAnimal(animals);

	return 0;
}
