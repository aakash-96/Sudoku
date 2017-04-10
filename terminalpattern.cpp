#include "sudoku.h"
//11 randomly selected given positions to be filled
void Generate()
{
	int i,j,k,v;
	for(i=1;i<=9;++i)
		for(j=1;j<=9;++j)
			puzzle[i][j]=0;
	srand(time(NULL));
	for(k=0;k<11;++k)
	{
		i=rand()%9+1;
		j=rand()%9+1;
		while(puzzle[i][j]!=0)
		{
			i=(i+1)%9+1;
			j=(j+1)%9+1;
		}
		while(1)
		{
			v=rand()%9+1;
			if(isSafe(i,j,v))
			{
				puzzle[i][j]=v;
				break;
			}
			else v=(v+1)%9+1;
		}
	}
	FillRandom();
}
bool FillRandom()
{
	int i,r,c,v;
	if(!FindNext(r,c))
		return true;
	//srand(time(NULL));
	v=rand()%9+1;
	i=9;
	while(--i)
	{
		if(isSafe(r,c,v))
		{
			puzzle[r][c]=v;
			if(FillRandom())
				return true;
			puzzle[r][c]=0;
		}
		v=(v+1)%9+1;
	}
	return false;
}
//Now Terminal pattern is formed
