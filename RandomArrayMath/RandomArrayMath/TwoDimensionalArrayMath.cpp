#include "stdafx.h"
#include "TwoDimensionalArrayMath.h"

//
// Constructor takes two arguemnts. One for row count and one for column count. These are used 
// to initiallize the matrix size.
TwoDimensionalArrayMath::TwoDimensionalArrayMath(int rows, int cols) : rows_(rows), cols_(rows), matrix_(new int*[rows_])
{
	for (int row = 0; row < rows_; row++)
	{
		matrix_[row] = new int[cols_];
	}
	LoadRandomNumbers();
}


//
// Clean up the matrix_ varaible upon instance deletion.
TwoDimensionalArrayMath::~TwoDimensionalArrayMath()
{
	for (int row = 0; row < rows_; row++)
	{
		delete[] matrix_[row];
	}
	delete[] matrix_;
}


//
// Copy constructor to deep copy the matrix.
TwoDimensionalArrayMath::TwoDimensionalArrayMath(const TwoDimensionalArrayMath * obj)
{
}


void TwoDimensionalArrayMath::LoadRandomNumbers()
{
	for (int row = 0; row < rows_; row++)
	{
		for (int col = 0; col < cols_; col++)
		{
			matrix_[row][col] = row + col;
		}
	}
}
