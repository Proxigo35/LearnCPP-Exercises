#include "MonsterGenerator.h"

Monster MonsterGenerator::generate() {
	return Monster {
		static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes - 1)),
		MonsterGenerator::getName(Random::get(0, 5)),
		MonsterGenerator::getRoar(Random::get(0, 5)),
		Random::get(1, 100)
	};
}

std::string_view MonsterGenerator::getName(int num) {
	switch (num) {
	case 0: return "Blarg";
	case 1: return "Steven";
	case 2: return "Philip";
	case 3: return "Michael";
	case 4: return "Joe";
	case 5: return "Pete";
	default: return "???";
	}
}

std::string_view MonsterGenerator::getRoar(int num) {
	switch (num) {
	case 0: return "*ROAR*";
	case 1: return "*MEOW*";
	case 2: return "*BLYaAAK*";
	case 3: return "*huh*";
	case 4: return "*EEEEE*";
	case 5: return "*Maaaah*";
	default: return "*meep*";
	}
}
