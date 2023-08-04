#include "Grid.h"
#include <fstream>
#include <string>
using namespace std;
Grid::Grid() : m_grid()
{
}

Grid::~Grid()
{
}

void Grid::LoadGrid(const char filename[])
{
	ifstream inputFile(filename);
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			char c;
			inputFile.get(c);
			if (c != ' ') {
				int ic = c - '0';
				m_grid[x][y] = ic;
			}
			else {
				x--;
			}
			inputFile.get();
		}
	}
	inputFile.close();
}

void Grid::SaveGrid(const char filename[])
{
	ofstream outputFile(filename);
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (x != 8)
			{
				outputFile << m_grid[x][y] << " ";
			}
			else {
				outputFile << m_grid[x][y];
			}
		}
		if (y != 8)
		{
			outputFile << endl;
		}
	}
	outputFile.close();
}