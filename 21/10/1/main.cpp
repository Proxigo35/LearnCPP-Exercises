#include <string>
#include <string_view>
#include <iostream>

class MyString {
	std::string m_string {};

public:
	MyString(std::string_view s = {})
		: m_string {s}
	{}

	friend std::ostream& operator<<(std::ostream& out, const MyString& s);

	std::string operator()(std::size_t start, std::size_t end) {
		return m_string.substr(start, end);
	}
};

std::ostream& operator<<(std::ostream& out, const MyString& s) {
	out << s.m_string;
	return out;
}

int main() {
    MyString s {"Hello, world!"};
    std::cout << s(7, 5) << '\n';

    return 0;
}
