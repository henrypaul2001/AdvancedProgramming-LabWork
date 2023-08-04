#pragma once
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

template<class T>
class Grid
{
	public:
		Grid() : m_grid()
		{
		}

		~Grid()
		{
		}

		void LoadGrid(const char filename[])
		{
			ifstream inputFile(filename);
			for (int y = 0; y < 9; y++)
			{
				for (int x = 0; x < 9; x++)
				{
					inputFile >> m_grid[x][y];
				}
			}
			inputFile.close();
		}

		void SaveGrid(const char filename[])
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

	private:
		T m_grid[9][9];
};
