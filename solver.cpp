#include "sudoku.h"
bool FindNext(int &r,int &c)
{
	for(r=1;r<=9;++r)
		for(c=1;c<=9;++c)
			if(puzzle[r][c]==0)
				return true;
	return false;
}
bool isSafe(int r,int c,int value)
{
	//row and col
	int i,j;
	for(i=1;i<=9;++i)
	{
		if(puzzle[r][i]==value)
			return false;
		if(puzzle[i][c]==value)
			return false;
	}
	//block
	int x=r-(r-1)%3;
	int y=c-(c-1)%3;
	for(i=0;i<3;++i)
	    for(j=0;j<3;++j)
			if(puzzle[i+x][j+y]==value)
				return false;
	return true;
}
bool FillSudoku()
{
	int r,c,i;
	if(!FindNext(r,c))
		return true;
	for(i=1;i<=9;++i)
	{
		if(isSafe(r,c,i))
		{
			puzzle[r][c]=i;
			if(FillSudoku())
				return true;
			puzzle[r][c]=0;
		}
	}
	return false;
}
