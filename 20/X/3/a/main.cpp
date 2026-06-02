#include <iostream>
#include <numeric>
#include <iterator>

int binarySearch(const int* array, int target, int min, int max) {
	while (min <= max) {
		int mid {std::midpoint(min, max)};
		if (array[mid] > target) max = mid - 1;
		else if (array[mid] < target) min = mid + 1;
		else return mid;
	}
	return -1;
}

int main() {
    constexpr int array[] {3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48};
    constexpr int testValues[] {0, 3, 12, 13, 22, 26, 43, 44, 48, 49};
    int expectedResult[] {-1, 0, 3, -1, -1, 8, -1, 13, 14, -1};
    static_assert(std::size(testValues) == std::size(expectedResult));
    int numTestValues {std::size(testValues)};

    for (int count{0}; count < numTestValues; ++count) {
        int index{binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1)};
        if (index == expectedResult[count]) std::cout << "Test value " << testValues[count] << " passed!\n";
        else std::cout << "Test value " << testValues[count] << " failed. There's something wrong with your code!\n";
    }

    return 0;
}
