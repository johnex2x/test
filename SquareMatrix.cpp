#include <iostream>
#include <cmath>
#include "SquareMatrix.h"
using namespace std;

SquareMatrix::SquareMatrix( int dimension ) : Matrix( dimension, dimension )
{
}

bool SquareMatrix::symmetric()
{
	int row = getRow();
	int col = getCol();
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(getEntry(i,j) != getEntry(j,i))
				return false;
		}
	}
	return true;
}

void SquareMatrix::magicSquare()
{
	int size = getRow();
	int x = size/2; //﹚竡x禸癬﹍
	int y = size-1; //﹚竡y禸癬﹍
	int number = 1; //﹚竡计癬﹍
	setEntry( y, x, number); //癬﹍1

	int start = 2; //计眖2秨﹍
	int counter = 1;
	while(start <= size*size)
	{		
		if(counter%size == 0) //–近筁 簿
		{
			y--;
			setEntry( y, x, start);
			start++;
			counter++;
		}
		if(y+1 == size) //窱┏传︽
			y=0;
		else
			y++;
		if(x+1 == size) //窱┏传︽
			x=0;
		else
			x++;
		setEntry( y, x, start);
		start++;
		counter++;
	}
}