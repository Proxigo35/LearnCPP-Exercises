#include <iostream>
#include "Random.h"
#include <algorithm>
#include <array>

class Board {
	std::array<int, 16> m_grid {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

public:
	std::array<int, 16> get_grid() const {return m_grid;}

	void print(const std::string_view message) const {
		std::cout << "\033[2J\033[H";
		for (std::size_t i {0}; i < m_grid.size(); ++i) {
			if (i % 4 == 0 && i != 0) std::cout << '\n';

			int current_value = m_grid[i];

			if (current_value == 16) {
				std::cout << "   ";
				continue;
			}
			std::cout << (current_value < 10 ? " " : "") << current_value << ' ';
		}
		std::cout << "\n\n" << message;
	}

	std::size_t get_index_free() const {
		return static_cast<std::size_t>((std::find(m_grid.begin(), m_grid.end(), 16)) - m_grid.begin());
	}	

	bool make_move(const char key) {
		std::size_t index_free {get_index_free()};
		switch (key) {
		case 'w':
			if (index_free < 12) std::swap(m_grid[index_free], m_grid[index_free + 4]);
			else return false;
			break;
		case 'a':
			if (index_free != 3 && index_free != 7 && index_free != 11 && index_free != 15) {
				std::swap(m_grid[index_free], m_grid[index_free + 1]);
			}
			else return false;
			break;
		case 's':
			if (index_free > 3) std::swap(m_grid[index_free], m_grid[index_free - 4]);
			else return false;
			break;
		case 'd':
			if (index_free % 4 != 0) {
				std::swap(m_grid[index_free], m_grid[index_free - 1]);
			}
			else return false;
			break;
		}
		return true;
	}

	char int_to_move(int num) {
		switch (num) {
			case 1: return 'w';
			case 2: return 'a';
			case 3: return 's';
			case 4: return 'd';
		}
		return 'q';
	}

	void shuffle() {
		int valid_moves_made {0};
		while (valid_moves_made < 200) {
			if(make_move(int_to_move(Random::get(1, 4)))) ++valid_moves_made;
		}
	}

};

int main() {
	Board board {};
	board.shuffle();
	std::string_view message {""};
	board.print(message);

	while (!std::ranges::is_sorted(board.get_grid())) {
		char in {};
		std::cin >> in;
		if (in == 'q') break;
		if (!board.make_move(in)) message = "Invalid move, try again: ";
		else message = "";
		board.print(message);
	}

	if (std::ranges::is_sorted(board.get_grid())) std::cout << "Congratulations, you won!";
	std::cout << "\nThanks for playing!\n";
	return 0;
}
