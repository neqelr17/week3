// RandomArrayMath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <exception>
#include <iostream>
#include <time.h>


#include "TwoDimensionalArrayMath.h"


int main()
{
	// Seed random
	srand((unsigned)time(NULL));
	
	// Set variables
	const int rows = 5;
	const int cols = 5;

	// Create instance of the TwoDimensionalArrayMath object
	TwoDimensionalArrayMath matrix = TwoDimensionalArrayMath(rows, cols);

	try
	{
		// Loop through row count and get print the total and average to the console for each row
		for (int row = 0; row < matrix.GetRowCount(); row++)
		{
			std::cout << "Row: " << row + 1 << std::endl;
			std::cout << "Total = " << matrix.GetRowTotal(row) << std::endl;
			std::cout << "Average = " << matrix.GetRowAverage(row) << std::endl << std::endl;
		}
	}
	catch (std::exception exc)
	{
		// TwoDimensionalArrayMath GetAverage and GetTotal methods throw execption if row is out of range.
		std::cout << "ERROR: " << exc.what() << std::endl;
	}

	// Display all the elements in the matrix object. Comma delimited.
	matrix.DisplayMatrix();
	
    return 0;
}
