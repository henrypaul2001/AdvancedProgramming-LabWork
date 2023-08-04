#include "WordSearch.h"
#include "GridCell.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
using namespace std;

const int dictionarySize = 50;
string words[dictionarySize];
string foundWords[dictionarySize * 2];
string missingWords[dictionarySize];

WordSearch::WordSearch(const char * const filename) : mHead(nullptr), outputName(filename), mDimension(9) {
}

WordSearch::~WordSearch() {
	try {
		if (mHead != nullptr) {
			while (mHead->GetRight() != nullptr) {
				GridCell* previous = mHead;
				GridCell* current = mHead;
				while (current->GetRight() != nullptr) {
					previous = current;
					current = current->GetRight();
				}
				delete current;
				previous->SetRight(nullptr);
			}
			delete mHead;
			mHead = nullptr;
		}
	}
	catch (exception& e) {
	}
}

void WordSearch::readSimplePuzzle() {
	ifstream inputFile(puzzleName);
	if (inputFile.is_open()) {
		string dimension;
		getline(inputFile, dimension);
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				char c;
				inputFile.get(c);
				if (c != ' ' && c != '\n') {
					letters[y][x] = c;
				}
				else {
					x--;
				}
			}
		}
	}
}

void WordSearch::readSimpleDictionary() const {
	ifstream inputFile(dictionaryName);
	if (inputFile.is_open()) {
		for (int i = 0; i < dictionarySize; i++) {
			string word;
			getline(inputFile, word);
			words[i] = word;
		}
	}
}

void WordSearch::readAdvancedPuzzle() {
	ifstream inputFile(puzzleName);
	GridCell* const head = new GridCell(-1, 0, ' ');
	mHead = head;
	GridCell* currentCell = head;
	int dimension;
	if (inputFile.is_open()) {
		inputFile >> dimension;
		for (int y = 0; y < dimension; y++) {
			for (int x = 0; x < dimension; x++) {
				char c;
				inputFile.get(c);
				if (c != ' ' && c != '\n') {
					GridCell* const newCell = new GridCell(x, y, c);
					currentCell->SetRight(newCell);
					newCell->SetLeft(currentCell);
					currentCell = newCell;
				}
				else {
					x--;
				}
			}
		}
	}
	mDimension = dimension;
}

void WordSearch::readAdvancedDictionary() const {
	// Add your code here
	std::cout << "Function not implemented" << std::endl;
}

void WordSearch::solvePuzzleSimple() {
	string currentWord;
	char currentLetter;
	bool wordFound = false;
	int wordLength;
	int foundWordsCounter = 0;
	int missingWordsCounter = 0;

	// Loop through each word in dictionary
	for (int wordCounter = 0; wordCounter < dictionarySize; wordCounter++) {
		wordFound = false;
		if (words[wordCounter] == "") {
			// No more words
			break;
		}
		currentWord = words[wordCounter];
		dictionaryEntriesVisited++;
		wordLength = currentWord.length();

		// Loop through letters array searching for first letter of word
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				currentLetter = letters[y][x];
				gridCellsVisited++;
				if (currentLetter == currentWord[0]) {
					// First letter found
					// Check surrounding letters

					// Check right
					if (x + wordLength <= 9) {
						for (int i = 1; i < wordLength; i++) {
							gridCellsVisited++;
							if (letters[y][x + i] == currentWord[i]) {
								// New letter found
								if (i == wordLength - 1) {
									wordFound = true;
									foundWords[foundWordsCounter] = currentWord;
									string column = to_string(x);
									string row = to_string(y);
									const string wordPos = column + " " + row;
									foundWords[foundWordsCounter + 1] = wordPos;
									foundWordsCounter += 2;
								}
							}
							else {
								// Letter not found - try new direction
								break;
							}
						}
					}

					// Check left
					if (x - wordLength >= -1) {
						for (int i = 1; i < wordLength; i++) {
							gridCellsVisited++;
							if (letters[y][x - i] == currentWord[i]) {
								// New letter found
								if (i == wordLength - 1) {
									wordFound = true;
									foundWords[foundWordsCounter] = currentWord;
									string column = to_string(x);
									string row = to_string(y);
									const string wordPos = column + " " + row;
									foundWords[foundWordsCounter + 1] = wordPos;
									foundWordsCounter += 2;
								}
							}
							else {
								// Letter not found - try new direction
								break;
							}
						}
					}

					// Check up
					if (y - wordLength >= -1) {
						for (int i = 1; i < wordLength; i++) {
							gridCellsVisited++;
							if (letters[y - i][x] == currentWord[i]) {
								// New letter found
								if (i == wordLength - 1) {
									wordFound = true;
									foundWords[foundWordsCounter] = currentWord;
									string column = to_string(x);
									string row = to_string(y);
									const string wordPos = column + " " + row;
									foundWords[foundWordsCounter + 1] = wordPos;
									foundWordsCounter += 2;
								}
							}
							else {
								// Letter not found - try new direction
								break;
							}
						}
					}

					// Check down
					if (y + wordLength <= 9) {
						for (int i = 1; i < wordLength; i++) {
							gridCellsVisited++;
							if (letters[y + i][x] == currentWord[i]) {
								// New letter found
								if (i == (wordLength - 1)) {
									wordFound = true;
									foundWords[foundWordsCounter] = currentWord;
									string column = to_string(x);
									string row = to_string(y);
									const string wordPos = column + " " + row;
									foundWords[foundWordsCounter + 1] = wordPos;
									foundWordsCounter += 2;
								}
							}
							else {
								// Letter not found - try new direction
								break;
							}
						}
					}

					// Check top left
					if (y - wordLength >= -1 && x - wordLength >= -1) {
						for (int i = 1; i < wordLength; i++) {
							gridCellsVisited++;
							if (letters[y - i][x - i] == currentWord[i]) {
								// New letter found
								if (i == wordLength - 1) {
									wordFound = true;
									foundWords[foundWordsCounter] = currentWord;
									string column = to_string(x);
									string row = to_string(y);
									const string wordPos = column + " " + row;
									foundWords[foundWordsCounter + 1] = wordPos;
									foundWordsCounter += 2;
								}
							}
							else {
								// Letter not found - try new direction
								break;
							}
						}
					}

					// Check top right
					if (y - wordLength >= -1 && x + wordLength <= 9) {
						for (int i = 1; i < wordLength; i++) {
							gridCellsVisited++;
							if (letters[y - i][x + i] == currentWord[i]) {
								// New letter found
								if (i == wordLength - 1) {
									wordFound = true;
									foundWords[foundWordsCounter] = currentWord;
									string column = to_string(x);
									string row = to_string(y);
									const string wordPos = column + " " + row;
									foundWords[foundWordsCounter + 1] = wordPos;
									foundWordsCounter += 2;
								}
							}
							else {
								// Letter not found - try new direction
								break;
							}
						}
					}

					// Check bottom left
					if (y + wordLength <= 9 && x - wordLength >= -1) {
						for (int i = 1; i < wordLength; i++) {
							gridCellsVisited++;
							if (letters[y + i][x - i] == currentWord[i]) {
								// New letter found
								if (i == wordLength - 1) {
									wordFound = true;
									foundWords[foundWordsCounter] = currentWord;
									string column = to_string(x);
									string row = to_string(y);
									const string wordPos = column + " " + row;
									foundWords[foundWordsCounter + 1] = wordPos;
									foundWordsCounter += 2;
								}
							}
							else {
								// Letter not found - try new direction
								break;
							}
						}
					}

					// Check bottom right
					if (y + wordLength <= 9 && x + wordLength <= 9) {
						for (int i = 1; i < wordLength; i++) {
							gridCellsVisited++;
							if (letters[y + i][x + i] == currentWord[i]) {
								// New letter found
								if (i == wordLength - 1) {
									wordFound = true;
									foundWords[foundWordsCounter] = currentWord;
									string column = to_string(x);
									string row = to_string(y);
									const string wordPos = column + " " + row;
									foundWords[foundWordsCounter + 1] = wordPos;
									foundWordsCounter += 2;
								}
							}
							else {
								// Letter not found - try new direction
								break;
							}
						}
					}
				}

				if (x == 8 && y == 8 && !wordFound) {
					missingWords[missingWordsCounter] = currentWord;
					missingWordsCounter++;
				}
			}

			if (wordFound) {
				break;
			}
		}
	}

	totalWordsFound = foundWordsCounter;
	totalMissingWords = missingWordsCounter;
}

void WordSearch::solvePuzzleAdvanced() {
	string currentWord;
	GridCell* currentCell;
	GridCell* nextCell;
	bool wordFound = false;
	int wordLength;
	int foundWordsCounter = 0;
	int missingWordsCounter = 0;

	// Loop through each word in dictionary
	for (int wordCounter = 0; wordCounter < dictionarySize; wordCounter++) {
		wordFound = false;
		if (words[wordCounter] == "") {
			// No more words
			break;
		}
		currentWord = words[wordCounter];
		dictionaryEntriesVisited++;
		wordLength = currentWord.length();

		int posX = 0;
		int posY = 0;
		currentCell = mHead->GetRight();
		gridCellsVisited++;
		// Loop through linked list searching for first letter of current word
		while (currentCell != nullptr) {
			posX = currentCell->GetPosX();
			posY = currentCell->GetPosY();
			const char value = currentCell->GetValue();
			if (value == currentWord[0]) {
				// First letter found
				// Check surrounding letters

				// Check right
				if (posX + wordLength <= mDimension) {
					for (int i = 1; i < wordLength; i++) {
						nextCell = getCellFromPos(posX + i, posY);
						gridCellsVisited++;
						if (nextCell->GetValue() == currentWord[i]) {
							// New letter found
							if (i == wordLength - 1) {
								wordFound = true;
								foundWords[foundWordsCounter] = currentWord;
								string column = to_string(posX);
								string row = to_string(posY);
								const string wordPos = column + " " + row;
								foundWords[foundWordsCounter + 1] = wordPos;
								foundWordsCounter += 2;
							}
						}
						else {
							// Letter not found - try new direction
							break;
						}
					}
				}

				// Check left
				if (posX - wordLength >= -1) {
					for (int i = 1; i < wordLength; i++) {
						nextCell = getCellFromPos(posX - i, posY);
						gridCellsVisited++;
						if (nextCell->GetValue() == currentWord[i]) {
							// New letter found
							if (i == wordLength - 1) {
								wordFound = true;
								foundWords[foundWordsCounter] = currentWord;
								string column = to_string(posX);
								string row = to_string(posY);
								const string wordPos = column + " " + row;
								foundWords[foundWordsCounter + 1] = wordPos;
								foundWordsCounter += 2;
							}
						}
						else {
							// Letter not found - try new direction
							break;
						}
					}
				}

				// Check up
				if (posY - wordLength >= -1) {
					for (int i = 1; i < wordLength; i++) {
						nextCell = getCellFromPos(posX, posY - i);
						gridCellsVisited++;
						if (nextCell->GetValue() == currentWord[i]) {
							// New letter found
							if (i == wordLength - 1) {
								wordFound = true;
								foundWords[foundWordsCounter] = currentWord;
								string column = to_string(posX);
								string row = to_string(posY);
								const string wordPos = column + " " + row;
								foundWords[foundWordsCounter + 1] = wordPos;
								foundWordsCounter += 2;
							}
						}
						else {
							// Letter not found - try new direction
							break;
						}
					}
				}

				// Check down
				if (posY + wordLength <= mDimension) {
					for (int i = 1; i < wordLength; i++) {
						nextCell = getCellFromPos(posX, posY + i);
						gridCellsVisited++;
						if (nextCell->GetValue() == currentWord[i]) {
							// New letter found
							if (i == (wordLength - 1)) {
								wordFound = true;
								foundWords[foundWordsCounter] = currentWord;
								string column = to_string(posX);
								string row = to_string(posY);
								const string wordPos = column + " " + row;
								foundWords[foundWordsCounter + 1] = wordPos;
								foundWordsCounter += 2;
							}
						}
						else {
							// Letter not found - try new direction
							break;
						}
					}
				}

				
				// Check top left
				if (posY - wordLength >= -1 && posX - wordLength >= -1) {
					for (int i = 1; i < wordLength; i++) {
						nextCell = getCellFromPos(posX - i, posY - i);
						gridCellsVisited++;
						if (nextCell->GetValue() == currentWord[i]) {
							// New letter found
							if (i == wordLength - 1) {
								wordFound = true;
								foundWords[foundWordsCounter] = currentWord;
								string column = to_string(posX);
								string row = to_string(posY);
								const string wordPos = column + " " + row;
								foundWords[foundWordsCounter + 1] = wordPos;
								foundWordsCounter += 2;
							}
						}
						else {
							// Letter not found - try new direction
							break;
						}
					}
				}

				// Check top right
				if (posY - wordLength >= -1 && posX + wordLength <= mDimension) {
					for (int i = 1; i < wordLength; i++) {
						nextCell = getCellFromPos(posX + i, posY - i);
						gridCellsVisited++;
						if (nextCell->GetValue() == currentWord[i]) {
							// New letter found
							if (i == wordLength - 1) {
								wordFound = true;
								foundWords[foundWordsCounter] = currentWord;
								string column = to_string(posX);
								string row = to_string(posY);
								const string wordPos = column + " " + row;
								foundWords[foundWordsCounter + 1] = wordPos;
								foundWordsCounter += 2;
							}
						}
						else {
							// Letter not found - try new direction
							break;
						}
					}
				}

				// Check bottom left
				if (posY + wordLength <= mDimension && posX - wordLength >= -1) {
					for (int i = 1; i < wordLength; i++) {
						nextCell = getCellFromPos(posX - i, posY + i);
						gridCellsVisited++;
						if (nextCell->GetValue() == currentWord[i]) {
							// New letter found
							if (i == wordLength - 1) {
								wordFound = true;
								foundWords[foundWordsCounter] = currentWord;
								string column = to_string(posX);
								string row = to_string(posY);
								const string wordPos = column + " " + row;
								foundWords[foundWordsCounter + 1] = wordPos;
								foundWordsCounter += 2;
							}
						}
						else {
							// Letter not found - try new direction
							break;
						}
					}
				}

				// Check bottom right
				if (posY + wordLength <= mDimension && posX + wordLength <= mDimension) {
					for (int i = 1; i < wordLength; i++) {
						nextCell = getCellFromPos(posX + i, posY + i);
						gridCellsVisited++;
						if (nextCell->GetValue() == currentWord[i]) {
							// New letter found
							if (i == wordLength - 1) {
								wordFound = true;
								foundWords[foundWordsCounter] = currentWord;
								string column = to_string(posX);
								string row = to_string(posY);
								const string wordPos = column + " " + row;
								foundWords[foundWordsCounter + 1] = wordPos;
								foundWordsCounter += 2;
							}
						}
						else {
							// Letter not found - try new direction
							break;
						}
					}
				}
			}

			if (posX == mDimension - 1 && posY == mDimension - 1 && !wordFound) {
				missingWords[missingWordsCounter] = currentWord;
				missingWordsCounter++;
			}

			currentCell = currentCell->GetRight();
			gridCellsVisited++;
		}
	}

	totalWordsFound = foundWordsCounter;
	totalMissingWords = missingWordsCounter;
}

void WordSearch::writeResults(const double loadTime, const double solveTime) const {
	// Add your code here
	ofstream outputFile(outputName);
	outputFile << "NUMBER_OF_WORDS_MATCHED " << totalWordsFound / 2 << endl;
	outputFile << endl;

	outputFile << "WORDS_MATCHED_IN_GRID" << endl;
	for (int i = 0; i < totalWordsFound; i += 2) {
		const string wordPos = foundWords[i + 1];
		outputFile << wordPos << " " << foundWords[i] << endl;
	}
	outputFile << endl;

	outputFile << "WORDS_UNMATCHED_IN_GRID" << endl;
	for (int i = 0; i < totalMissingWords; i++) {
		outputFile << missingWords[i] << endl;
	}
	outputFile << endl;

	outputFile << "NUMBER_OF_GRID_CELLS_VISITED " << gridCellsVisited << endl;
	outputFile << endl;

	outputFile << "NUMBER_OF_DICTIONARY_ENTRIES_VISITED " << dictionaryEntriesVisited << endl;
	outputFile << endl;

	outputFile << "TIME_TO_POPULATE_GRID_STRUCTURE " << loadTime << endl;
	outputFile << endl;

	outputFile << "TIME_TO_SOLVE_PUZZLE " << solveTime << endl;

	outputFile.close();
}

GridCell* WordSearch::getCellFromPos(const int posX, const int posY) const {
	GridCell* currentCell = mHead->GetRight();
	
	while (currentCell != nullptr) {
		if (currentCell->GetPosX() == posX && currentCell->GetPosY() == posY) {
			return currentCell;
		}
		else {
			currentCell = currentCell->GetRight();
		}
	}
}