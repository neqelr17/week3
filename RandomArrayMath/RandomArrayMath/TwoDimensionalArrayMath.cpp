#include "stdafx.h"

#include <exception>
#include <random>
#include <iostream>
#include <time.h>

#include "TwoDimensionalArrayMath.h"

//
// Constructor takes two arguemnts. One for row count and one for column count. These are used 
// to initiallize the matrix size.
TwoDimensionalArrayMath::TwoDimensionalArrayMath(int rows, int cols) : rows_(rows), cols_(rows), matrix_(new int*[rows])
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
// Assignment operator overload. This performs a deep copy of the matrix_ 2d array.
TwoDimensionalArrayMath & TwoDimensionalArrayMath::operator=(const TwoDimensionalArrayMath & obj)
{
	// Clean up memory of old seating_chart_ to prevent memory leaks
	for (int row = 0; row < rows_; row++)
	{
		delete[] matrix_[row];
	}
	delete[] matrix_;

	rows_ = obj.rows_;
	cols_ = obj.cols_;

	// Copy values of matrix_ into new seating_chart_
	matrix_ = new int*[obj.rows_];
	for (int row = 0; row < rows_; row++)
	{
		matrix_[row] = new int[cols_];
		for (int col = 0; col < cols_; col++)
		{
			matrix_[row][col] = obj.matrix_[row][col];
		}
	}
	return *this;
}


//
// Copy constructor to deep copy the matrix.
TwoDimensionalArrayMath::TwoDimensionalArrayMath(const TwoDimensionalArrayMath &obj) : rows_(obj.rows_), cols_(obj.cols_), matrix_(new int*[rows_])
{
	for (int row = 0; row < rows_; row++)
	{
		matrix_[row] = new int[cols_];
		for (int col = 0; col < cols_; col++)
		{
			matrix_[row][col] = obj.matrix_[row][col];
		}
	}
}


//
// Load matrix_ with random integers
void TwoDimensionalArrayMath::LoadRandomNumbers()
{
	for (int row = 0; row < rows_; row++)
	{
		for (int col = 0; col < cols_; col++)
		{
			matrix_[row][col] = rand();
		}
	}
}


//
// Display values in matrix.
void TwoDimensionalArrayMath::DisplayMatrix()
{
	for (int row = 0; row < rows_; row++)
	{
		std::cout << "row " << row << ": ";
		for (int col = 0; col < cols_; col++)
		{
			std::cout << matrix_[row][col] << ", ";
		}
		std::cout << std::endl;
	}
}


//
// Return the row count
int TwoDimensionalArrayMath::GetRowCount()
{
	return rows_;
}


//
// Return the column count
int TwoDimensionalArrayMath::GetColumnCount()
{
	return cols_;
}


//
// Calcualte the total of a row. Throws exception if passed in row is out of bounds
int TwoDimensionalArrayMath::GetRowTotal(const int & row)
{
	if (row < 0 || row >= rows_)
	{
		throw std::exception("Row out of Bounds!");
	}

	int total = 0;
	for (int col = 0; col < cols_; col++)
	{
		total += matrix_[row][col];
	}
	return total;
}


//
// Calcualte the average of a row. Throws exception if passed in row is out of bounds
int TwoDimensionalArrayMath::GetRowAverage(const int & row)
{
	if (row < 0 || row >= rows_)
	{
		throw std::exception("Row out of Bounds!");
	}

	int avg = 0;
	for (int col = 0; col < cols_; col++)
	{
		avg += matrix_[row][col];
	}
	return avg / cols_;
}
