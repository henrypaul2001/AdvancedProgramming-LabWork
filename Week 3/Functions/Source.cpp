#include <iostream>
using namespace std;

int mymax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int arguments(int number, char character, float floatingpoint)
{
	cout << "number= " << number << " character= " << character << " float= " << floatingpoint << endl;

	return 0;
}

int main(int, char**) {

	int a = 10;
	int b = 20;

	int max = mymax(a, b);

	cout << "a=" << a << ", b=" << b << endl;
	cout << "max=" << max << endl;

	char letter = 'a';
	float ft = 10;

	int number = arguments(a, letter, ft);

	return 0;
}

