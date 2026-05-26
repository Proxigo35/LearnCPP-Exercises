#include <iostream>
#include <vector>
#include "Random.h"

namespace Settings {
	short guessesLeft {6};
}

namespace WordList {
	std::vector<std::string_view> words {"mystery", "broccoli" , "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};
	std::string_view getRandomWord() {return words[Random::get<std::size_t>(0, words.size() - 1)];}
}

class Session {
	const std::string_view m_word {WordList::getRandomWord()};
	std::vector<bool> m_guessedLetters {std::vector<bool>(26)};

public:
	std::string_view getWord() const {return m_word;}
	std::vector<bool> getGuessedLetters() const {return m_guessedLetters;}
	std::size_t letterToIndex(char letter) const {return static_cast<std::size_t>((letter % 32) - 1);}
	void setLetterAsGuessed(char letter) {m_guessedLetters[letterToIndex(letter)] = true;}

};

bool isGameWon(const Session& session) {
	bool gameIsWon {true};
	for (const auto letter : session.getWord()) {
		if (!session.getGuessedLetters()[session.letterToIndex(letter)]) {
			gameIsWon = false;
			break;
		}
	}
	return gameIsWon;
}

std::string getIncorrectlyGuessedLetters(const Session& session) {
	std::string incorrectLetters {};

	for (std::size_t i {0}; i < session.getGuessedLetters().size(); ++i) {
		if (session.getGuessedLetters()[i] && !session.getWord().contains(static_cast<char>('a' + i))) {
			incorrectLetters += static_cast<char>('a' + i);
		}
	}
	return incorrectLetters;
}

void printGame(const Session& session) {
	std::cout << "\nThe word: ";

	for (const auto letter : session.getWord()) {
		 if (session.getGuessedLetters()[session.letterToIndex(letter)]) std::cout << letter;
		 else std::cout << '_';
	}
	
	std::cout << " Wrong guesses: ";
	for (short _ {0}; _ < Settings::guessesLeft; ++_) std::cout << '+';
	std::cout << getIncorrectlyGuessedLetters(session) << '\n'; 

	if (Settings::guessesLeft < 1 || isGameWon(session)) {
		if (!isGameWon(session)) std::cout << "You lost, the word was: " << session.getWord() << '\n';
		else std::cout << "Yon won, the word was: " << session.getWord() << '\n';
	}
}

void addGuessedLetter(Session& session, char letter) {
	session.setLetterAsGuessed(letter); 
	if (!session.getWord().contains(letter)) {
		--Settings::guessesLeft;
		std::cout << "No, '" << letter << "' is not in the word!\n";
	} else std::cout << "Yes, '" << letter << "' is in the word!\n";
}

void getLetter(Session& session) {
	while (true) {
		std::cout << "Enter your next letter: ";
		char letter {};
		std::cin >> letter;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (!std::cin || letter < 'a' || letter > 'z') {
			std::cin.clear();
			std::cout << "That wasn't a valid input. Try again.\n\n";
			continue;
		}

		if (session.getGuessedLetters()[session.letterToIndex(letter)]) {
			std::cout << "\nYou already guessed that. Try again.\n";
			continue;
		}

		addGuessedLetter(session, letter);
		break;
	}
}

bool letterIsInGuessedLetters(const Session& session, char letter) {
	return session.getGuessedLetters()[session.letterToIndex(letter)];
}

int main() {
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word. To lose: run out of pluses.\n";
	Session session {};

	while (Settings::guessesLeft > 0 && !isGameWon(session)) {
		printGame(session);
		getLetter(session);
	}

	printGame(session);

    return 0;
}
