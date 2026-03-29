#include <iostream>

int calculate(int int1, char c, int int2) {
	switch(c) {
	case '+':
		return int1 + int2;
	case '-':
		return int1 - int2;
	case '*':
		return int1 * int2;
	case '/':
		return int1 / int2;
	case '%':
		return int1 % int2;
	default:
		std::cout << "Invalid operator entered";
		return 0;
	}
}

int main() {
	std::cout << calculate(5, '+', 6) << '\n'; 
	std::cout << calculate(5, '-', 6) << '\n'; 
	std::cout << calculate(5, '*', 6) << '\n'; 
	std::cout << calculate(5, '/', 6) << '\n'; 
	std::cout << calculate(5, '%', 6) << '\n'; 
	return 0;
}
