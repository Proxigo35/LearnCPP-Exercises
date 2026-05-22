#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>

int main() {
	const std::vector<int> divisors {3, 5, 7, 11, 13, 17, 19};
	const std::vector<std::string_view> words {"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
	assert(divisors.size() == words.size());
	bool divisor_found = false;

	for (int i {1}; i <= 150; ++i) {
		divisor_found = false;
		for (std::size_t j {0}; j < divisors.size(); ++j) {
			if (i % divisors[j] == 0) {
				divisor_found = true;
				std::cout << words[j];
			}
		}
		if (!divisor_found) std::cout << i;
		std::cout << '\n';
	}

	return 0;
}
