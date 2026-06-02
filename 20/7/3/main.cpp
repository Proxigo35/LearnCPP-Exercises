#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Random.h"

int main() {
	std::cout << "Start where? ";
	int start {};
	std::cin >> start;

	std::cout << "How many? ";
	std::size_t many {};
	std::cin >> many;

	int multiplier {Random::get(2, 4)};
	std::vector<int> squares {};

	for (std::size_t i {0}; i < many; ++i)
		squares.push_back(((start + static_cast<int>(i)) * (start + static_cast<int>(i))) * multiplier);

	std::cout << "I generated " << many << " square numbers. Do you know what each number is after multiplying it by " << multiplier << "?\n";

	while(squares.size() > 0) {
		int guess {};
		std::cin >> guess;
		auto found {std::find(squares.begin(), squares.end(), guess)};

		if (found == squares.end()) {
			int closestNumber {
				*std::min_element(
					squares.begin(),
					squares.end(),
					[=] (int x, int y) {return std::abs(x - guess) < std::abs(y - guess);}
				)
			};
			std::cout << guess << " is wrong! Try " << closestNumber << " next time.\n";
			break;
		}

		squares.erase(found);
		if(squares.size() == 0) break;
		std::cout << "Nice! " << squares.size() << " number(s) left.\n";
	}

	if(squares.size() == 0) std::cout << "Nice! You found all the numbers, good job!\n";
	
	return 0;
}
