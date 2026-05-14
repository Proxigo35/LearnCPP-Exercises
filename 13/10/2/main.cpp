#include <iostream>

struct Fraction {
	int numerator {0};
	int denominator {1};
};

Fraction getFraction() {

	std::cout << "Enter a value for the numerator: ";
	int numerator {};
	std::cin >> numerator;

	std::cout << "Enter a value for the denominator: ";
	int denominator {};
	std::cin >> denominator;
	std::cout << '\n';

	return {numerator, denominator};
}

constexpr Fraction multiplyFractions(const Fraction& fraction1, const Fraction& fraction2) {
	return {fraction1.numerator * fraction2.numerator, fraction1.denominator * fraction2.denominator};
}

void printFraction(const Fraction& fraction) {
	std::cout << "\nYour fractions multiplied together: " << fraction.numerator << '/' << fraction.denominator << "\n\n"; 
}

int main() {

	Fraction fraction1 {getFraction()};
	Fraction fraction2 {getFraction()};
	printFraction({multiplyFractions(fraction1, fraction2)});
	
	return 0;
}
