#include <iostream>
#include <vector>

int main() {
	std::vector<int> integers (3);
	int sum {0};
	int product {1};
	std::cout << "Enter 3 integers: ";
	
	for(unsigned long i {0}; i < integers.size(); ++i) {
		std::cin >> integers[i];
		sum += integers[i];
		product *= integers[i];
	}

	std::cout << "The sum is: " << sum << '\n';
	std::cout << "The product is: " << product << '\n';
}
