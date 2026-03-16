#include <iostream>

float calculate_meters(int seconds) {
	return 9.8 * (seconds * seconds) / 2;
}

int main() {

	std::cout << "Enter the height of the tower in meters: ";
	float meters{};
	std::cin >> meters;

	for (int i = 0; i < 6; i++) {
		if (meters - calculate_meters(i) >= 0) {
			std::cout << "At " << i << " seconds, the ball is at height: " <<meters - calculate_meters(i) << " meters\n";
		} else {
			std::cout << "At " << i << " seconds, the ball is on the ground\n";
		}
	}

}
