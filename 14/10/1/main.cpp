#include <iostream>
#include <string>
#include <string_view>

class Ball {

	std::string m_colour {};
	double m_radius {};
	
public:
	Ball(std::string_view colour, double radius)
		: m_colour {colour}
		, m_radius {radius}
	{}

	std::string_view colour() const {return m_colour;}
	double radius() const {return m_radius;}
};

void constexpr print(const Ball& ball) {
	std::cout << "Ball(" << ball.colour() << ", " << ball.radius() << ")\n";
}

int main()
{
	Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);

	return 0;
}
