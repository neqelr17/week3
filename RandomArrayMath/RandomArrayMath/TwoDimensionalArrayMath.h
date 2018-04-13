#pragma once
class TwoDimensionalArrayMath
{
public:
	TwoDimensionalArrayMath(int rows, int cols);
	~TwoDimensionalArrayMath();
	TwoDimensionalArrayMath(const TwoDimensionalArrayMath *obj);
	TwoDimensionalArrayMath &operator=(const TwoDimensionalArrayMath &obj);

	// Public Methods
	void LoadRandomNumbers();

private:
	int ** matrix_;
	int rows_;
	int cols_;

};

