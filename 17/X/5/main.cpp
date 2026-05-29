#include <iostream>
#include <algorithm>
#include <cassert>
#include "Random.h"

namespace Settings {
	constexpr const int bustValue {21};
	constexpr const int dealerStops {17};
}

struct Card {
	enum Rank {
		rank_ace,
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_jack,
		rank_queen,
		rank_king,
		rank_max_rank
	};

	enum Suit {
		suit_club,
		suit_diamond,
		suit_heart,
		suit_spade,
		suit_max_suit
	};

	Rank rank {};
	Suit suit {};

	static constexpr std::array allRanks {rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king};
	static constexpr std::array allSuits {suit_club, suit_diamond, suit_heart, suit_spade};

	friend std::ostream& operator<<(std::ostream& out, const Card& card) {
		static constexpr std::array ranks {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
        static constexpr std::array suits {'C', 'D', 'H', 'S'};
        out << ranks[card.rank] << suits[card.suit];
		return out;
	}

    int value() const {
        static constexpr std::array rankValues {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
        return rankValues[rank];
    }
};

class Deck {
	std::array<Card, 52> m_cards {};
	std::size_t m_nextCardIndex {0};

public:
	Deck() {
		std::size_t count {0};
		for (auto suit : Card::allSuits) 
			for (auto rank : Card::allRanks) 
				m_cards[count++] = Card{rank, suit};
	}

	Card dealCard() {
		assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");
        return m_cards[m_nextCardIndex++];;
	}

	void shuffle() {
		std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
		m_nextCardIndex = 0;
	}
};

struct Player {
	int score {};
	int acesDealt {};
};

enum class GameOutcomes {
	win,
	lose,
	draw
};

GameOutcomes playBlackjack() {

	Deck deck {};
	deck.shuffle();
	Card card1 {deck.dealCard()};
	Card card2 {deck.dealCard()};
	Card card3 {deck.dealCard()};

	Player dealer {card1.value()};
	if (card1.value() == 11) ++dealer.acesDealt;

	Player player {card2.value() + card3.value()};
	if (card2.value() == 11) ++player.acesDealt;
	if (card3.value() == 11) ++player.acesDealt;

	std::cout << "The dealer is showing " << dealer.score << '\n';
	std::cout << "You have score " << player.score << '\n';

	bool playerHitting {true};

	while(playerHitting) {
		std::cout << "(h) to hit, or (s) to stand: ";
		char option {};
		std::cin >> option;

		switch (option) {
		case 'h': {
			Card card {deck.dealCard()};
			if (card.value() == 11) ++player.acesDealt;
			player.score += card.value();
			std::cout << "You were dealt a " << card << ". You now have: " << player.score << '\n';
			if (player.score > Settings::bustValue) {
				std::cout << "You went bust!\n";
				return GameOutcomes::lose;
			}
			break;
		}
		case 's': {
			playerHitting = false;
			break;
		}
		default: std::cout << "Invalid input.\n";
		}
	}

	while (dealer.score < Settings::dealerStops) {
		Card card {deck.dealCard()};
		if (card.value() == 11) ++dealer.acesDealt;
		dealer.score += card.value();
		if (dealer.score > Settings::bustValue) {
			while (dealer.acesDealt > 0){
				dealer.score -= 10;
				--dealer.acesDealt;
			}
		}

		std::cout << "The dealer flips a " << card << ". They now have: " << dealer.score << '\n';
	}


	if (dealer.score > Settings::bustValue) {
		std::cout << "The dealer went bust!\n";
		return GameOutcomes::win;
	}

	return player.score > dealer.score ? GameOutcomes::win : player.score == dealer.score ? GameOutcomes::draw : GameOutcomes::lose;
}

int main() {

	switch(playBlackjack()){
	case GameOutcomes::win:
		std::cout << "Youn win!\n";
		break;
	case GameOutcomes::lose:
		std::cout << "You lose!\n";
		break;
	default: std::cout << "You draw!\n";
	}

    return 0;
}
