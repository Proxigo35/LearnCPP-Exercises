#ifndef MONSTERGENERATOR_H
#define MONSTERGENERATOR_H

#include "Monster.h"
#include "Random.h"

namespace MonsterGenerator {

	Monster generate();
	std::string_view getName(int num);
	std::string_view getRoar(int num);
}

#endif
