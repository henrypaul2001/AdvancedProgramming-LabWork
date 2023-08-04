#include <iostream>
using namespace std;

void myswap(int &lhs, int &rhs) {
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}

int& clamp(int& value, int low, int high) {
	if (value < low)
		return low;
	if (value > high)
		return high;
	return value;
}

int main(int, char**) {
	int a = 10;
	int b = 20;
	
	cout << "a=" << a << ", b=" << b << endl;

	int value1 = 10;
	int value2 = 20;
	int result1 = clamp(value1, 0, 30) + clamp(value2, 0, 30);
	int result2 = clamp(value1, 0, 5) + clamp(value2, 0, 10);

	cout << "a=" << a << ", b=" << b << endl;
	
	return 0;
}
