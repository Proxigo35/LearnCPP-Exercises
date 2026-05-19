#include <iostream>
#include <string>

template <typename T, typename U, typename V>
class Triad {
private:
	T m_first {};
	U m_second {};
	V m_third {};

public:
	Triad(const T& first, const U& second, const V& third)
		: m_first {first}
		, m_second {second}
		, m_third {third}
	{}

	const T& first() const {return m_first;}
	void set_first(T first) {m_first = first;}
	
	const U& second() const {return m_second;}
	void set_second(U second) {m_second = second;}

	const V& third() const {return m_third;}
	void set_third(U third) {m_third = third;}

	void print() const;
};

template <typename T, typename U, typename V>
void Triad<T, U, V>::print() const{
	std::cout << '[' <<  m_first << ", " << m_second << ", " << m_third << ']';
}

int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print(); // [1, 2, 3]
	std::cout << '\n';
	std::cout << t1.first() << '\n'; // 1

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print(); // [1, 2.3, Hello]
	std::cout << '\n';

	return 0;
}
