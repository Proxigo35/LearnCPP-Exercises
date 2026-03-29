#include <iostream>
#include "Random.h"
#include <limits>

bool clearFailedExtraction() {
    if (!std::cin) {
        if (std::cin.eof()) std::exit(0);
        std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }

    return false;
}
int get_guess(int min, int max) {
	while (true) {
		int guess{};
		std::cin >> guess;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (guess < min || guess > max || clearFailedExtraction()) {
			std::cout << "Oops, that input is invalid.  Please try again: ";
			continue;
		}
		return guess;
	}
}

void play_game(int guesses, int min, int max) {
	const int random_int {Random::get(min, max)};
	std::cout << "Let's play a game. I'm thinking of a number between " << min << " and " << max << ". You have " << guesses <<  " tries to guess what it is.\n";

	for (int i {1}; i <= guesses; ++i) {
		std::cout << "Guess #" << i << ": ";
		int guess {get_guess(min, max)};

		if (guess == random_int) {
			std::cout << "Correct! You win!\n";
			break;
		} else if (guess < random_int) std::cout << "Your guess is too low.\n";
		else if (guess > random_int) std::cout << "Your guess is too high.\n";
		
		if (i == guesses) {
			std::cout << "Sorry you lose. The correct number was " << random_int << ".\n";
		}
	}
}

int main() {

	play_game(7, 1, 100);
	
	do {
		std::cout << "Would you like to play again (y/n)?";
		char again {};
		std::cin >> again;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (again == 'n') {
			std::cout << "Thank you for playing.\n";
			break;
		} else if (again == 'y') play_game(7, 1, 100);
	}
	while(true);	

	return 0;
}
