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
	int x = size/2; //�w�qx�b�_�l
	int y = size-1; //�w�qy�b�_�l
	int number = 1; //�w�q�Ʀr�_�l
	setEntry( y, x, number); //�_�l1

	int start = 2; //�Ʀr�q2�}�l
	int counter = 1;
	while(start <= size*size)
	{		
		if(counter%size == 0) //�C�@���L�� �W���@��
		{
			y--;
			setEntry( y, x, start);
			start++;
			counter++;
		}
		if(y+1 == size) //�I�쩳����
			y=0;
		else
			y++;
		if(x+1 == size) //�I�쩳����
			x=0;
		else
			x++;
		setEntry( y, x, start);
		start++;
		counter++;
	}
}