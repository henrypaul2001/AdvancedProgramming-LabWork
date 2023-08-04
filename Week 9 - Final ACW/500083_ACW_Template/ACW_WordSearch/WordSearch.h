#pragma once
#include "GridCell.h"
class WordSearch {
	char letters[9][9] = { 0 };
	GridCell* mHead;

	const char* puzzleName = "../../Example puzzles/puzzle 2/wordsearch_grid.txt";
	const char* dictionaryName = "../../Example puzzles/puzzle 2/dictionary.txt";
	
	// Add your code here
	const char* outputName;

	int totalWordsFound = 0;
	int totalMissingWords = 0;
	int gridCellsVisited = 0;
	int dictionaryEntriesVisited = 0;

	int mDimension;
public:
	explicit WordSearch(const char * const filename);
	~WordSearch();

	void readSimplePuzzle();
	void readSimpleDictionary() const;
	void readAdvancedPuzzle();
	void readAdvancedDictionary() const;
	void solvePuzzleSimple();
	void solvePuzzleAdvanced();
	void writeResults(const	double loadTime, const double solveTime) const;

	GridCell* getCellFromPos(int posX, int posY) const;

	WordSearch(const WordSearch&);
	WordSearch& operator=(const WordSearch&);
};