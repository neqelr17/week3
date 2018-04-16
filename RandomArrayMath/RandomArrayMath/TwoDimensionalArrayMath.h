#pragma once
class TwoDimensionalArrayMath
{
public:
	TwoDimensionalArrayMath(int rows, int cols);
	~TwoDimensionalArrayMath();
	TwoDimensionalArrayMath(const TwoDimensionalArrayMath &obj);
	TwoDimensionalArrayMath &operator=(const TwoDimensionalArrayMath &obj);

	// Public Methods
	void LoadRandomNumbers();
	void DisplayMatrix();
	int GetRowCount();
	int GetColumnCount();
	int GetRowTotal(const int &row);
	int GetRowAverage(const int &row);

private:
	int rows_;
	int cols_;
	int ** matrix_;

};

