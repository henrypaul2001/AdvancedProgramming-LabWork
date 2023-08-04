#include <iostream>
using namespace std;

int main() {
	cout << "Enter a temp in fahrenheit" << endl;

	float far;
	cin >> far;

	float celsius = 5.0f / 9.0f * (far - 32.0f);

	cout << celsius << endl;

	return 0;
}