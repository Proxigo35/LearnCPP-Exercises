#include <iostream>
#include <functional>

int getInteger() {
	std::cout << "Enter an integer: ";
	int num {};
	std::cin >> num;
	return num;
}

char getOperator() {
	char op {};
	do {
		std::cout << "Enter an operator (+, -, *, /): ";
		std::cin >> op;
	}
	while (op != '+' && op != '-' && op != '*' && op != '/');
	return op;
}

int add(int num1, int num2) {
	return num1 + num2;
}

int subtract(int num1, int num2) {
	return num1 - num2;
}

int multiply(int num1, int num2) {
	return num1 * num2;
}

int divide(int num1, int num2) {
	return num1 / num2;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op) {
	switch(op) { 
	case '+': return &add;
	case '-': return &subtract;
	case '*': return &multiply;
	case '/': return &divide;
	default: return nullptr;
	}
}

int main() {
	int num1 {getInteger()};
	char op {getOperator()};
	int num2 {getInteger()};
	ArithmeticFunction function {getArithmeticFunction(op)};

	if (function) std::cout << num1 << ' ' << op << ' ' << num2 << " = " << function(num1, num2) << '\n';

	return 0;
}
