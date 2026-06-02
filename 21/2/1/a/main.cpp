#include <iostream>

class Fraction {
	int m_numerator {};
	int m_denominator {};

public:

	explicit Fraction(int x, int y)
		: m_numerator {x}
		, m_denominator {y}
	{}

	void print() const {
		std::cout << m_numerator << '/' << m_denominator << '\n';
	}
};

int main()
{
    Fraction f1{ 1, 4 };
    f1.print();

    Fraction f2{ 1, 2 };
    f2.print();

    return 0;
}
