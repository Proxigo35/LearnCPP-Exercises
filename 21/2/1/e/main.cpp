#include <iostream>
#include <numeric>

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

	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f, int num);
	friend Fraction operator*(int num, const Fraction& f);
};

Fraction operator*(const Fraction& f1, const Fraction& f2) {
	int numerator {f1.m_numerator * f2.m_numerator};
	int denominator {f1.m_denominator * f2.m_denominator};
	int gcd {std::gcd(numerator, denominator)};
	return Fraction {numerator / gcd, denominator / gcd};
}

Fraction operator*(const Fraction& f, int num) {
	int numerator {f.m_numerator * num};
	int gcd {std::gcd(numerator, f.m_denominator)};
	return Fraction {numerator / gcd, f.m_denominator / gcd};
}

Fraction operator*(int num, const Fraction& f) {
	return Fraction {f * num};
}

int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}
