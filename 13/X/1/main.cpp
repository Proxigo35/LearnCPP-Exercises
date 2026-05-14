#include <iostream>
#include <string>
#include <string_view>

struct Monster {
	enum Type {
		ogre,
		dragon,
		orc,
		giant_spider,
		slime,
	};

	Type type {};
	std::string name {};
	int health {};
};

constexpr std::string_view getMonsterNameString(Monster::Type type) {
	switch(type) {
	case Monster::ogre:
		return "Ogre";
	case Monster::dragon:
		return "Dragon";
	case Monster::orc:
		return "Orc";
	case Monster::giant_spider:
		return "Giant spider";
	case Monster::slime:
		return "Slime";
	}
}

void printMonster(const Monster& monster) {
	std::cout << "This " << getMonsterNameString(monster.type) << " is named " << monster.name << " and has " << monster.health << " health.\n";
}

int main() {
	
	Monster ogre {Monster::ogre, "Torg", 145};
	printMonster(ogre);

	Monster slime {Monster::slime, "Blurp", 23};
	printMonster(slime);
	
	return 0;
}
