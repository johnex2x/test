// Class SquareMatrix represents a square matrix of integers.
#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include "Matrix.h"

class SquareMatrix : public Matrix
{
public:
	SquareMatrix( int dimension = 0 ); // default constructor
   bool symmetric(); // test if the matrix is symmetric
   void magicSquare(); // generate a magic square
   int determinant(); // return the determinant
	SquareMatrix cofactorMatrix(); // return the cofactor matrix
	int cofactor( int row, int col ); // return the ( row, col ) cofactor
private:
	int minor( int row, int col ); // return the ( row, col ) minor
};

#endif