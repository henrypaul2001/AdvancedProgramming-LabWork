#include <iostream>
using namespace std;

void functionA() {
	int a = 10;
	int b = 20;
	int *p = &a;

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;

	*p = 100;

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}

void functionB() {
	int a = 10;
	int b = 20;
	int c = 30;
	int *p = &b;

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;

	*p = 100;
	p++;
	*p = 200;

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
} 

void functionC() {
	unsigned int a = 0x00ff00ff;
	unsigned int *p = (unsigned int *)a;

	*p = 999;
}

void functionD() {
	double x = 3.14;

	cout << "x= " << x << endl;

	double *q = &x;
	double **p = &q;

	**p = 25.25;

	cout << "x= " << x << endl;
}

int main(int, char**) {

	//functionA();
	//functionB();
	//functionC();
	functionD();

	return 0;
}
