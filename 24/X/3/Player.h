#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Potion.h"

class Player : public Creature {

	int m_level {1};

public:
	
	Player(std::string_view name)
		: Creature(name, '@', 10, 1, 0)
	{}

	void levelUp() {
		++m_level;
		++m_damage;
	}

	int getLevel() const {return m_level;}
	bool hasWon() const {return m_level >= 20;}

	void attackMonster(Creature& monster) {
		monster.reduceHealth(m_damage);
		std::cout << "You hit the " << monster.getName() << " for " << m_damage << " damage.\n";
		if (monster.isDead()) {
			std::cout << "You killed the " << monster.getName() << ".\n";
			m_gold += monster.getGold();
			std::cout << "You found " << monster.getGold() << " gold.\n";
			++m_damage;
			if (++m_level > 19) {
				std::cout << "You won! You finished with " << m_gold << " gold.\n";
				return;
			}
			std::cout << "You are now level " << m_level << ".\n";
		}
	}

	void drinkPotion(const Potion& potion) {
		std::cout << "You drank a " << potion.getSizeName(potion.getSize()) << " potion of " << potion.getTypeName(potion.getType()) << ".\n";
	}
};

#endif
