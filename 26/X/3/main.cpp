#include <iostream>
#include <string_view>
#include <string>

template <typename T, typename U>
class Pair {
	T m_first {};
	U m_second {};

public:

	const T& first() const {return m_first;}
	const U& second() const {return m_second;}

	Pair(const T& v1, const U& v2) 
		: m_first {v1}
		, m_second {v2}
	{}

};

template <typename T>
class StringValuePair: public Pair<std::string, T> {

public:

	StringValuePair(std::string_view string, const T& v)
		: Pair<std::string, T> {static_cast<std::string>(string), v}
	{}

};

int main() {

	StringValuePair<int> svp {"Hello", 5};
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}
