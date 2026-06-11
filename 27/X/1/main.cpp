#include <iostream>
#include <exception>
#include <stdexcept>

class Fraction {
	int m_n {};
	int m_d {};

public:

	Fraction(int n, int d)
		: m_n {n}
		, m_d {d}
	{
		if (d == 0) throw std::runtime_error("Invalid denominator");
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f) {
		out << f.m_n << '/' << f.m_d;
		return out;
	}
};

int main() {
	std::cout << "Enter the numerator: ";
	int n {};
	std::cin >> n;

	std::cout << "Enter the denominator: ";
	int d {};
	std::cin >> d;

	try {
		Fraction f {n, d};
		std::cout << "The fraction is: " << f << '\n';
	} catch (const std::exception& e) {
		std::cout << e.what() << '\n'; 
	}

	return 0;
}
