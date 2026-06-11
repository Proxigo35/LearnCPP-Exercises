#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Shape.h"

class Triangle : public Shape {
	
	Point m_p1 {0, 0};
	Point m_p2 {0, 0};
	Point m_p3 {0, 0};

public:
	
	Triangle(Point p1, Point p2, Point p3)
		: m_p1 {p1}
		, m_p2 {p2}
		, m_p3 {p3}
	{}

	virtual std::ostream& print(std::ostream& out) const override {
		out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ')';
		return out;
	}
	
};

#endif
