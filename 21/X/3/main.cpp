#include <iostream>
#include <cassert>

class IntArray {
	int* m_array {nullptr};
	std::size_t m_size {};

public:

	IntArray(std::size_t size)
		: m_size {size}
	{
		assert(size > 0 && "IntArray length should be a positive integer");
		m_array = new int[m_size] {};
	}

	IntArray(const IntArray& array)
		: m_size {array.m_size}
	{
		m_array = new int[m_size];

		for (std::size_t i {0}; i < array.m_size; ++i) {
			*(m_array + i) = *(array.m_array + i);
		} 
	}

	~IntArray() {delete[] m_array;}

	friend std::ostream& operator << (std::ostream& out, const IntArray& array);

	int& operator [] (const int index) {
		assert(index >= 0 && index < static_cast<int>(m_size)); 
		return *(m_array + index);
	}

	IntArray& operator = (const IntArray& array) {
		if (this == &array) return *this;

		delete[] m_array;

		m_size = array.m_size;
		m_array = new int[m_size] {};

		for (std::size_t i {0}; i < array.m_size; ++i) {
			*(m_array + i) = *(array.m_array + i);
		} 

		return *this;
	}
};

std::ostream& operator << (std::ostream& out, const IntArray& array) {
	for (std::size_t i {0}; i < array.m_size; ++i) out << *(array.m_array + i) << ' ';
	return out;
}

IntArray fillArray() {
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main() {
	IntArray a {fillArray()};

	std::cout << a << '\n';

	auto& ref {a};
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}
