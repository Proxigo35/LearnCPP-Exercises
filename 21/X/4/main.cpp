#include <cassert>
#include <cmath>
#include <iostream>

class FixedPoint2 {
	std::int16_t m_whole {};
	std::int8_t m_fractional {};
	bool m_negative {};

public:

	FixedPoint2(int whole, int fractional)
		: m_whole {static_cast<std::int16_t>(whole)}
		, m_fractional {static_cast<std::int8_t>(fractional)}
		, m_negative {m_whole < 0 || m_fractional < 0}
	{
		m_whole = static_cast<std::int16_t>(std::abs(m_whole));
		m_fractional = static_cast<std::int8_t>(std::abs(m_fractional));
		
		m_whole += m_fractional/100;
		m_fractional = m_fractional % 100;
	}

	friend std::ostream& operator << (std::ostream& out, const FixedPoint2& fp);

	explicit operator double() const {
		return (
			(m_negative ? -1 : 1) * (
				static_cast<double>(m_whole) +
				static_cast<double>(m_fractional) / 100
			)
		);
	}

	friend bool testDecimal(const FixedPoint2 &fp);

	FixedPoint2(double d) 
		: m_whole {static_cast<std::int16_t>(std::abs(static_cast<int>(d)))}
		, m_fractional {static_cast<std::int8_t>(std::round((std::abs(d) - m_whole) * 100))}
		, m_negative {d < 0}
	{}

	friend bool operator == (const FixedPoint2& fp1, const FixedPoint2& fp);
	friend FixedPoint2 operator + (const FixedPoint2& fp1, const FixedPoint2& fp2);

	FixedPoint2 operator - () {
		return {-m_whole, m_fractional};
	}

	friend std::istream& operator >> (std::istream& in, const FixedPoint2& fp);
};

std::ostream& operator << (std::ostream& out, const FixedPoint2& fp) {
	out << static_cast<double>(fp);
	return out;
}

bool testDecimal(const FixedPoint2 &fp) {
    if (fp.m_whole >= 0) return fp.m_fractional >= 0 && fp.m_fractional < 100;
    else return fp.m_fractional <= 0 && fp.m_fractional > -100;
}

bool operator == (const FixedPoint2& fp1, const FixedPoint2& fp2) {
	return fp1.m_whole == fp2.m_whole && fp1.m_fractional == fp2.m_fractional && fp1.m_negative == fp2.m_negative;
}
	
FixedPoint2 operator + (const FixedPoint2& fp1, const FixedPoint2& fp2) {
	return {static_cast<double>(fp1) + static_cast<double>(fp2)};
}

std::istream& operator >> (std::istream& in, FixedPoint2& fp) {
	double temp {};
	in >> temp;
	fp = FixedPoint2 {temp};
	return in;
}

int main() {
	assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
	assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

	// Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });    // both positive, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });    // both positive, with decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }); // both negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }); // both negative, with decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });  // second negative, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });  // second negative, possible decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });   // first negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });   // first negative, possible decimal overflow

	FixedPoint2 a{ -0.48 };
	assert(static_cast<double>(a) == -0.48);
	assert(static_cast<double>(-a) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	assert(static_cast<double>(a) == 5.68);

	return 0;
}
