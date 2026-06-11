#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Point.h"

class Circle : public Shape {

	Point m_center {0, 0};
	int m_radius {};

public:

	Circle(Point center, int radius)
		: m_center {center}
		, m_radius {radius}
	{}

	virtual std::ostream& print(std::ostream& out) const override {
		out << "Circle(" << m_center << ", radius " << m_radius << ')';
		return out;
	}

};

#endif
