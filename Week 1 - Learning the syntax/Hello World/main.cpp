#include <iostream>
using namespace std;

int main (int argc, char **argv) {

	double n;
	float total = 0.0f;
	int numbersadded = 0;
	do {
		cout << "Please enter a value, then press Enter" << endl;
		if (cin >> n) {
			total += n;
			numbersadded++;
		}
		else {
			break;
		}
	} while (n >= 0);

	if (numbersadded > 0) {
		float average = total / numbersadded;
		cout << "Average: " << average << endl;
	}
	else {
		cout << "No numbers entered" << endl;
	}

	return 0;
}