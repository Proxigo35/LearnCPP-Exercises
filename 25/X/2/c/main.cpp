#include "Triangle.h"
#include <vector>
#include "Circle.h"

int getLargestRadius(const std::vector<Shape*>& v) {
	int largestRadius {0};

	for (const auto* element : v) {
		if (auto* circle {dynamic_cast<const Circle*>(element)})
			largestRadius = std::max(largestRadius, circle->getRadius());
	}

	return largestRadius;
}

int main() {
	std::vector<Shape*> v {
		new Circle {Point{1, 2}, 7},
		new Triangle {Point{1, 2}, Point{3, 4}, Point{5, 6}},
		new Circle {Point{7, 8}, 3}
	};

	// print each shape in vector v on its own line here
	for (const auto* element : v) {std::cout << *element << '\n';}

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
	for (auto* element : v) {delete element;}

	return 0;

}
