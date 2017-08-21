// Matrix class test program.
#include <iostream>
#include <iomanip>
#include <ctime>
#include "SquareMatrix.h"
using namespace std;

int main()
{
   unsigned seed;
   cout << "Enter a seed: ";
   cin >> seed;
   cout << "\n";
   srand( seed );

	Matrix A( 4, 5 ); // 4-by-5 matrix
   A.random();
	Matrix B( 4, 5 ); // 4-by-5 matrix
   B.random();
	Matrix C( 5, 3 ); // 5-by-3 matrix
   C.random();

	if( A.isNotEmpty() )
      cout << "-\n" << A << "=\n" << -A;
   cout << "\n---------------------------\n\n";

	if( A.isNotEmpty() )
      cout << "The transpose of\n" << A << "is\n" << ~A;
   cout << "\n---------------------------\n\n";

	if( (A + B).isNotEmpty() )
      cout << A << "+\n" << B << "=\n" << A + B;
   cout << "\n---------------------------\n\n";

	if( (A - B).isNotEmpty() )
      cout << A << "-\n" << B << "=\n" << A - B;
   cout << "\n---------------------------\n\n";

	if( (B * C).isNotEmpty() )
      cout << B << "*\n" << C << "=\n" << B * C;
   cout << "\n-------------------------------------\n\n";

	SquareMatrix D( 7 ); // 7-by-7 square matrix
   D.random();

	if( D.isNotEmpty() )
      cout << "The square of\n" << D << "is\n" << D * D;
   cout << "\n-------------------------------------\n\n";

	if( D.isNotEmpty() )
		cout << "The transpose of\n" << D << "=\n" << ~D;
   cout << "\n-------------------------------------\n\n";
/*
	if( D.isNotEmpty() )
		cout << "The determinant of\n" << D << "is equal to " << D.determinant();
   cout << "\n\n-------------------------------------\n\n";
*/
   for( int i = 1; i < D.getRow(); i++ )
      for( int j = 0; j < i; j++ )
         D.setEntry( j, i, D.getEntry( i, j ) );

	if( D.symmetric() )
      cout << D << "is symmetric\n";
   else
      cout << D << "is not symmetric\n";
   cout << "\n-------------------------------------\n\n";

	SquareMatrix E( 5 ); // 5-by-5 square matrix
	if( E.isNotEmpty() )
      E.magicSquare();

   if( E.getRow() % 2 == 1 )
      cout << "A " << E.getRow() << "-dimensional magic square:\n\n" << E << endl;

	system("pause");
}
