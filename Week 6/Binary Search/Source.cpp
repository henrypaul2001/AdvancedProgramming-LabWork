#include <iostream>
#include <fstream>

using namespace std;

static int numbers[100];

void LoadNumbers(string filename)
{
	ifstream inputFile(filename);
	for (int x = 0; x < 100; x++)
	{
		inputFile >> numbers[x];
	}
	inputFile.close();
}

bool iterativeBinarySearch(int* start, int* endPoint, int value) {
	bool valueFound = false;
	while (valueFound == false) {
		if (endPoint == start) {
			return false;
		}

		int* middle = start + (endPoint - start) / 2;

		if (value < *middle) {
			// Value is smaller than middle
			endPoint = middle;
		}
		else if (value > *middle) {
			// Value is bigger than middle
			start = ++middle;
		}
		else if (value == *middle) {
			valueFound = true;
		}
	}
	return valueFound;
}

bool binarySearch(int *start, int *endPoint, int value) {
	bool valueFound = false;

	if (endPoint == start) {
		return false;
	}

	int* middle = start + (endPoint - start) / 2;

	if (value < *middle) {
		// Value is smaller than middle
		valueFound = binarySearch(start, middle, value);
	}
	else if (value > *middle) {
		// Value is bigger than middle
		valueFound = binarySearch(++middle, endPoint, value);
	}
	else if (value == *middle) {
		valueFound = true;
	}

	return valueFound;
}

int main(int, char**) {
	LoadNumbers("binarysearchIn.txt");

	int* start = numbers;
	bool valueFound = binarySearch(&numbers[0], &numbers[100], 2);
	valueFound = iterativeBinarySearch(&numbers[0], &numbers[100], 101);
	return 0;
}