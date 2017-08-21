// Member-function definitions and data member initializations for the Matrix class.
#include <iostream>
#include <iomanip>
#include <vector>
#include "Matrix.h"
using namespace std;

// default constructor
Matrix::Matrix( int row, int col )
{
	if( row != 0 && col != 0 )
   {
      vector< int > zeroRow( col, 0 );
		matrix.insert( matrix.begin(), row, zeroRow );
   }
}

// randomly generate all entries in a matrix
void Matrix::random()
{
	for( unsigned int i = 0; i < matrix.size(); i++ )
		for( unsigned int j = 0; j < matrix[0].size(); j++ )
			matrix[i][j] = rand() % ( 2 * maxValue - 1 ) - maxValue + 1;
}

bool Matrix::isNotEmpty()
{
	if(matrix[0][0] == ' ')
		return false;
	else
		return true;
}

ostream &operator<<( ostream &output, const Matrix &x )
{
	for(int i=0; i< x.matrix.size(); i++)
	{
		for(int j=0; j< x.matrix[0].size(); j++)
		{
			output << setw(5) << x.matrix[i][j];
		}
		output << "\n\n";
	}


	return output;
}

Matrix Matrix::operator-()
{
	Matrix minus( matrix.size(),matrix[0].size() );
	for(int i=0; i< matrix.size(); i++)
	{
		for(int j=0; j< matrix[0].size(); j++)
		{
			minus.matrix[i][j] = -1 * matrix[i][j];
		}
	}
	return minus;
}

Matrix Matrix::operator ~()
{
	Matrix transpose( matrix[0].size(),matrix.size() );
	for(int i=0; i< matrix.size(); i++)
	{
		for(int j=0; j< matrix[0].size(); j++)
		{
			transpose.matrix[j][i] =  matrix[i][j];
		}
	}
	return transpose;
}

Matrix Matrix::operator+( Matrix &x )
{
	Matrix sum( matrix.size(),matrix[0].size() );
	for(int i=0; i< matrix.size(); i++)
	{
		for(int j=0; j< matrix[0].size(); j++)
		{
			sum.matrix[i][j] = x.matrix[i][j] + matrix[i][j];
		}
	}
	return sum;
}

Matrix Matrix::operator-( Matrix &x )
{
	Matrix sub( matrix.size(),matrix[0].size() );
	for(int i=0; i< matrix.size(); i++)
	{
		for(int j=0; j< matrix[0].size(); j++)
		{
			sub.matrix[i][j] = matrix[i][j] - x.matrix[i][j];
		}
	}
	return sub;
}

Matrix Matrix::operator*( Matrix &x )
{
	Matrix mul( matrix.size(), x.matrix[0].size() ); //先放入0
	for(int i=0; i< matrix.size(); i++)
		for(int j=0; j< x.matrix[0].size(); j++)
			mul.matrix[i][j] = 0;

	for(int i=0; i< matrix.size(); i++) //乘法
	{
		for(int j=0; j< x.matrix[0].size(); j++)
		{
			for(int b=0; b< matrix[0].size(); b++ )
			{
				mul.matrix[i][j] += matrix[i][b] * x.matrix[b][j];
			}
		}
	}
	return mul;
}