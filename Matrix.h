// Class Matrix represents a matrix of integers.
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

class Matrix
{
	friend ostream &operator<<( ostream &, const Matrix & ); // output operator
public:
	static const int maxValue = 5;
	Matrix( int row = 0, int col = 0 ); // default constructor

   void random(); // randomly generate all entries in a matrix

   const Matrix &operator=( const Matrix &right ); // assignment operator

   bool operator==( const Matrix &right ) const; // equality operator

   // inequality operator; returns opposite of == operator
   bool operator!=( const Matrix &right ) const  
   { 
      return ! ( *this == right ); // invokes Array::operator==
   } // end function operator!=

   // return the number of rows
   int getRow()
   {
      return matrix.size();
   }
   int getCol()
   {
      return matrix[0].size();
   }
   // set matrix[row][col] to value
   void setEntry( int row, int col, int value )
   {
      matrix[row][col] = value;
   }

   // get the value of matrix[row][col]
   int getEntry( int row, int col )
   {
      return matrix[row][col];
   }

   Matrix operator-(); // unary minus operator
	Matrix operator~(); // transpose operator
	Matrix operator+( Matrix & ); // addition operator
	Matrix operator-( Matrix & ); // subtraction operator
	Matrix operator*( Matrix & ); // multiplication operator
	bool isNotEmpty(); // test if the matrix has at least one row and one column
private:
	vector< vector< int > > matrix; // use a vector of vectors to represent a matrix
};

#endif