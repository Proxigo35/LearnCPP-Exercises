#include <iostream>
#include <string_view>
#include <string>

class Fruit {
	std::string m_name {};
	std::string m_colour {};

public:

	Fruit(std::string_view name = "", std::string_view colour = "")
		: m_name {name}
		, m_colour {colour}
	{}

	const std::string& getName() const {return m_name;}
	const std::string& getColour() const {return m_colour;}

};

class Apple : public Fruit {

public:

	Apple(std::string_view colour = "red")
		: Fruit {"apple", colour}
	{}

};

class Banana : public Fruit {

public:
	
	Banana()
		: Fruit{"banana", "yellow"}
	{}

};

int main() {
	Apple a {"red"};
	Banana b {};

	std::cout << "My " << a.getName() << " is " << a.getColour() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColour() << ".\n";

	return 0;
}
