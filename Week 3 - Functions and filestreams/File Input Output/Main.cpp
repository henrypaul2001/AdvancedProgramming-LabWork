#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
* Partially completed program
* The program should copy a text file
*
*/

bool Copy(char filenamein[], char filenameout[])
{
	ifstream inputFile(filenamein);
	if (inputFile.is_open()) {
		// read data
		string line;
		string lines[10];
		int lineCount = 0;
		while (getline(inputFile, line)) {
			lines[lineCount] = line;
			lineCount++;
		}
		inputFile.close();

		// write data
		ofstream outputFile(filenameout);
		if (outputFile.is_open()) {
			for (int i = 0; i < lineCount; i++) {
				outputFile << lines[i] << endl;
			}
			outputFile.close();
		}
		else {
			return false;
		}

		return true;
	}
	else {
		return false;
	}
}

int main(int argn, char* argv[])
{
	if (argn != 3) {
		cerr << "Usage: " << argv[0] << " <input filename> <output filename>" << endl;
		int keypress; cin >> keypress;
		return -1;
	}

	if (Copy(argv[1], argv[2]))
	{
		cout << "Copy successful" << endl;
	}
	else
	{
		cout << "Copy error" << endl;
	}

	system("PAUSE");
}