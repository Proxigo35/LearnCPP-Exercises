#include <iostream>
#include "Monster.h"
#include "Creature.h"
#include "Player.h"
#include "Potion.h"

void handlePotion(Player& player) {
	if (Random::get(1, 10) > 3) return;

	std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
	char option {};
	std::cin >> option;

	if (option == 'n' || option == 'N') return; 

	if (option == 'y' || option == 'Y') {
		Potion potion {Potion::getRandomPotion()};
		player.drinkPotion(potion);
	}
}

void fightMonster(Player& player, Monster& monster) {
	while(!player.isDead() && !monster.isDead()) {
		std::cout << "(R)un or (F)ight: ";
		char option {};
		std::cin >> option;

		if (option == 'r' || option == 'R') {
			if (Random::get(1, 2) < 2) {
				std::cout << "You successfully fled.\n";
				return;
			}
			std::cout << "You failed to flee.\n";
			monster.attackPlayer(player);
		} else if (option == 'f' || option == 'F') {
			player.attackMonster(monster);
			if (!monster.isDead()) monster.attackPlayer(player);
			else (handlePotion(player));
		}
	}
}

int main() {
	std::cout << "Enter your name: ";
	std::string name {};
	std::cin >> name;
	std::cout << "Welcome, " << name << ".\n";
	Player player {name};

	while (!player.isDead() && player.getLevel() < 20) {
		Monster monster {Monster::getRandomMonster()};
		std::cout << "You have encountered a(n) " << monster.getName() << ' ' << '(' << monster.getSymbol() << ").\n";
		fightMonster(player, monster);
	}

	return 0;
}
