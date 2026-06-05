#include <iostream>

class Average {
	std::int32_t sum {0};
	int count {0};

public:

	friend std::ostream& operator << (std::ostream& out, const Average& average);

	Average& operator += (int num) {
		sum += num;
		++count;
		return *this;
	}
};

std::ostream& operator << (std::ostream& out, const Average& average) {
	if (!average.count) {
		out << 0;
		return out;
	}

	out << static_cast<double>(average.sum)/average.count;
	return out;
};

int main() {
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}
