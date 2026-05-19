#include <cmath>
#include <iostream>

class Point2d {
	double m_x {0.0};
	double m_y {0.0};

public:
	Point2d(double x = 0.0, double y = 0.0)
		: m_x {x}
		, m_y {y}
	{}

	void print() const {
		std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
	}

	double distanceTo(const Point2d& p2) const {
		return std::sqrt((m_x - p2.m_x) * (m_x - p2.m_x) + (m_y - p2.m_y) * (m_y - p2.m_y));
	}
};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}
