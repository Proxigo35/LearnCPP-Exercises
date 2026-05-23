#include <iostream>
#include <vector>
#include <cassert>

namespace Animals {
	enum Animals {
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		maxAnimals
	};
	const std::vector numLegs {2, 4, 4, 4, 3, 0};
}

int main() {
	assert(Animals::Animals == Animals::numLegs.size());
	std::cout << Animals::numLegs[Animals::elephant];

	return 0;
}
