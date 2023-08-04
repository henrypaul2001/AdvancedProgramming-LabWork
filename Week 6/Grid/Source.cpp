#include <iostream>
#include "Grid.h"
using namespace std;

int main (int, char**) {
	Grid<float> grid;
	grid.LoadGrid("Grid1.txt");
	grid.SaveGrid("OutGrid.txt");

	return 0;
}