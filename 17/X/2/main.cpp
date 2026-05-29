#include <iostream>
#include <string_view>
#include <limits>
#include "Random.h"

namespace Potion {
	enum Type {
		healing,
		mana,
		speed,
		invisibility,
		max_potions
	};

	constexpr std::array types {healing, mana, speed, invisibility};
	constexpr std::array costs {20, 30, 12, 50};
	constexpr std::array<std::string_view, max_potions> names {"healing", "mana", "speed", "invisibility"};
	static_assert(costs.size() == max_potions && types.size() == max_potions && names.size() == max_potions);
}

class Player {
	std::string m_name {};
	std::array<int, Potion::max_potions> m_inventory {};
	int m_gold {};

public:
	explicit Player(std::string_view name)
		: m_name {name}
		, m_gold {Random::get(80, 120)}
	{}

	std::string_view getName() const {return m_name;}
	int getGold() const {return m_gold;}
	int getPotion(Potion::Type potion) const {return m_inventory[potion];}

	void buyPotion(Potion::Type potion) {
		if (m_gold >= Potion::costs[potion]) {
			m_gold -= Potion::costs[potion];
			++m_inventory[potion];
			std::cout << "You purchased a potion of " << Potion::names[potion] << ". You have " << m_gold << " gold left.\n\n";
		} else std::cout << "You can not afford that.\n\n";
	}
}; 

Potion::Type getPotion() {
	std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
	char option {};
	while (true) {
		std::cin >> option;
		if (!std::cin || (!std::cin.eof() && std::cin.peek() != '\n')) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "That was an invalid input. Try again: ";
			continue;
		}
		
		if (option == 'q') return Potion::max_potions;
		if ((option - '0') >= 0 && (option - '0') < Potion::max_potions) return static_cast<Potion::Type>(option - '0');

		std::cout << "That was an invalid input, Try again: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void shop(Player& player) {
	while (true) {
		std::cout << "Here is our selection for today:\n";

		for(const auto type : Potion::types) {
			std::cout << type <<  ") " << Potion::names[type] << " costs " << Potion::costs[type] << '\n';
		}

		Potion::Type potion {getPotion()};

		if (potion == Potion::max_potions) break;
		player.buyPotion(potion);
	}
}

void inventory(Player& player) {
	std::cout << "\nYour inventory contains: \n";
	for(const auto type : Potion::types) {
		if (player.getPotion(type) > 0) std::cout << player.getPotion(type) << "x potion of " << Potion::names[type] << '\n'; 
	}
	std::cout << "You escaped with " << player.getGold() << " gold remaining.\n";
}

int main() {
	std::cout << "Welcome to Roscoe's potion emporium!\nEnter your name: ";

	std::string name {};
	std::getline(std::cin >> std::ws, name);
	Player player {name};

	std::cout << "Hello " << player.getName() << ", you have " << player.getGold() << " gold.\n\n";
	shop(player);
	inventory(player);
	std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";

	return 0;
}
