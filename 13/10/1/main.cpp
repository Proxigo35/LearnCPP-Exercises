#include <iostream>

struct Revenue {
	int watched {};
	double clicked {};
	double earnings {};
};

void getRevenue(Revenue& revenue) {
	std::cout << "Enter the number of ads watched: ";
	int watched {};
	std::cin >> revenue.watched;

	std::cout << "Enter the percentage of users that clicked on an ad: ";
	double clicked {};
	std::cin >> revenue.clicked;

	std::cout << "Enter the average earnings per clicked ad: ";
	double earnings {};
	std::cin >> revenue.earnings;
}

void printRevenue(const Revenue& revenue) {
	std::cout << "\nNo. ads watched: " << revenue.watched << '\n';
	std::cout << "Percentage of users that clicked on an ad: " << revenue.clicked << '\n';
	std::cout << "Average earnings per clicked ad: " << revenue.earnings << '\n';
	std::cout << "Total revenue: " << revenue.watched * revenue.clicked/100 * revenue.earnings << "\n\n";
}

int main() {

	Revenue revenue {};
	getRevenue(revenue);
	printRevenue(revenue);

	return 0;
}
