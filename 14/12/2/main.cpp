#include <iostream>
#include <string>
#include <string_view>

class Ball {
	static constexpr std::string default_colour {"black"};
	static constexpr double default_radius {10.0};
	
	std::string m_colour {default_colour};
	double m_radius {default_radius};

public:

	Ball(double radius) 
		: Ball {"black", radius}
	{}

	Ball(std::string_view colour = "black", double radius = 10)
		: m_colour {colour}
		, m_radius {radius}
	{
		print();
	};

	void print() const {
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
