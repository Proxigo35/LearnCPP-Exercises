#include <iostream>
#include <vector>

void print_vector(const std::vector<int>& vector) {
	std::cout << "\t(Stack: ";
	if (vector.size() == 0) {
		std::cout << "empty)\n";
		return;
	}

	for (const auto& element : vector) std::cout << element << ' ';
	std::cout << ")\n";
}

void push_print(std::vector<int>& vector, int element) {
	vector.push_back(element);
	std::cout << "Push " << element << ' ';
	print_vector(vector);
}

void pop_print(std::vector<int>& vector) {
	vector.pop_back();
	std::cout << "Pop ";
	print_vector(vector);
}

int main() {

	std::vector<int> vector {};
	print_vector(vector);

	push_print(vector, 1);
	push_print(vector, 2);
	push_print(vector, 3);
	pop_print(vector);
	push_print(vector, 4);
	pop_print(vector);
	pop_print(vector);
	pop_print(vector);

	return 0;
}
