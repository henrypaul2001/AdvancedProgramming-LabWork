#include <iostream>
using namespace std;

int main() {
	const double x = 0;
	const double a = 1.999999999999999999999999;

	double y = (x + a) / x;
	double z = x / y;

	cout << "x: " << x << " y: " << y << " z: " << z << endl;

	if (y == z) {
		cout << "y and z are identical" << endl;
	}
	else {
		cout << "y and z are NOT identical" << endl;
	}

	return 0;
}