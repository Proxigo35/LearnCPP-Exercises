#include <iostream>
#include <string>

class Fruit {
	std::string m_name {};
	std::string m_colour {};

public:

	Fruit(std::string name = "", std::string colour = "")
		: m_name {name}
		, m_colour {colour}
	{}

	const std::string& getName() const {return m_name;}
	const std::string& getColour() const {return m_colour;}

};

class Apple : public Fruit {
	double m_fiber {};

public:

	Apple(std::string name, std::string colour, double fiber)
		: Fruit {name, colour}
		, m_fiber {fiber}
	{}

	friend std::ostream& operator << (std::ostream& out, const Apple& apple);
};

std::ostream& operator << (std::ostream& out, const Apple& apple) {
	out << "Apple(" << apple.getName() << ", " << apple.getColour() << ", " <<  apple.m_fiber << ')';
	return out;
}

class Banana : public Fruit {

public:

	Banana(std::string name, std::string colour)
		: Fruit {name, colour}
	{}

	friend std::ostream& operator << (std::ostream& out, const Apple& apple);
};

std::ostream& operator << (std::ostream& out, const Banana& banana) {
	out << "Banana(" << banana.getName() << ", " << banana.getColour() << ')';
	return out;
}

int main() {
	const Apple a {"Red delicious", "red", 4.2};
	std::cout << a << '\n';

	const Banana b {"Cavendish", "yellow"};
	std::cout << b << '\n';

	return 0;
}
