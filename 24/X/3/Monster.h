#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"
#include "Player.h"
#include <cassert>
#include "Random.h"

class Monster : public Creature {

public:

	enum Type {
		dragon,
		orc,
		slime,
		max_types
	};

	static inline Creature monsterData[] {
		Creature {"dragon", 'D', 20, 4, 100},
		Creature {"orc", 'o', 4, 2, 25},
		Creature {"slime", 's', 1, 1, 10}
	};
	
	static_assert(std::size(monsterData) == max_types);

	Monster(Type type)
		: Creature(monsterData[type])
	{}

	static Monster getRandomMonster() {
		return Monster(static_cast<Type>(Random::get(0, max_types - 1)));
	}

	void attackPlayer(Player& player) {
		player.reduceHealth(m_damage);
		std::cout << "The " << m_name << " hit you for " << m_damage << " damage.\n";
		if (player.isDead()) std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
	}
};

#endif
