#include "GridCell.h"
#include <iostream>

using namespace std;

GridCell::GridCell(const int pPosX, const int pPosY, const char pValue) : left(nullptr), right(nullptr) {
	SetPosX(pPosX);
	SetPosY(pPosY);
	SetValue(pValue);
}

void GridCell::WriteValue() const {
	cout << GetValue() << endl;
}