#pragma once
class GridCell
{
	GridCell* left;
	GridCell* right;
	int posX;
	int posY;
	char value;
public:
	GridCell(int pPosX, int pPosY, char pValue);

	inline GridCell* GridCell::GetLeft() const {
		return left;
	}

	inline GridCell* GridCell::GetRight() const {
		return right;
	}

	inline char GetValue() const {
		return value;
	}

	inline int GetPosX() const {
		return posX;
	}

	inline int GetPosY() const {
		return posY;
	}

	inline void SetLeft(GridCell* const cell) {
		left = cell;
	}

	inline void SetRight(GridCell* const cell) {
		right = cell;
	}

	inline void SetValue(const char pValue) {
		value = pValue;
	}

	inline void SetPosX(const int pos) {
		posX = pos;
	}

	inline void SetPosY(const int pos) {
		posY = pos;
	}

	void WriteValue() const;

	GridCell(const GridCell&);
	GridCell& operator=(const GridCell&);
};