#include <iostream>
#include <fstream>
using namespace std;

//////////////////////////////////////////////////////////////////
// DO NOT EDIT THIS FILE										//
// This file will be replaced with a new version during marking //
//////////////////////////////////////////////////////////////////

#include "WordSearch.h"
#include "ACW_Wrapper.h"

int main(int, char **) {

	ACW_Wrapper wrapper("log.txt");
	
	// Test simple algorithm
	{
		WordSearch ws("output_simple.txt");
		wrapper.startTimer();
		ws.readSimplePuzzle();
		ws.readSimpleDictionary();
		const double loadTime = wrapper.stopTimer();

		wrapper.startTimer();
		ws.solvePuzzleSimple();
		const double solveTime = wrapper.stopTimer();

		ws.writeResults(loadTime, solveTime);
	}
	
	// Test advanced algorithm
	{
		WordSearch ws("output_advanced.txt");

		wrapper.startTimer();
		ws.readAdvancedPuzzle();
		ws.readAdvancedDictionary();
		const double loadTime = wrapper.stopTimer();

		wrapper.startTimer();
		ws.solvePuzzleAdvanced();
		const double solveTime = wrapper.stopTimer();

		ws.writeResults(loadTime, solveTime);
	}

	return 0;
}