#include "Triangle.h"
#include <memory>
#include <vector>
#include "Circle.h"

int getLargestRadius(const std::vector<std::unique_ptr<Shape>>& v) {
	int largestRadius {0};

	for (const auto& element : v) {
		if (auto* circle {dynamic_cast<const Circle*>(element.get())})
			largestRadius = std::max(largestRadius, circle->getRadius());
	}

	return largestRadius;
}

int main() {

	std::vector<std::unique_ptr<Shape>> v;
	v.reserve(3);
	v.push_back(std::make_unique<Circle>(Point{1, 2}, 7));
	v.push_back(std::make_unique<Triangle>(Point{1, 2}, Point{3, 4}, Point{5, 6}));
	v.push_back(std::make_unique<Circle>(Point{7, 8}, 3));

	// print each shape in vector v on its own line here
	for (const auto& element : v) {std::cout << *element << '\n';}

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	return 0;

}
