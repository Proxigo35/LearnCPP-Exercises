#include <iostream>
#include <string>
#include <string_view>

class Ball {
	
	std::string m_colour {"black"};
	double m_radius {10};

public:
	Ball() {print();};

	Ball(std::string_view colour)
		: m_colour {colour}
	{print();}

	Ball(double radius)
		: m_radius {radius}
	{print();}

	Ball(std::string_view colour, double radius)
		: m_colour {colour}
		, m_radius {radius}
	{print();}

	void print() {
		std::cout << "Ball("<< m_colour << ", " << m_radius << ")\n";
	}
};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}
