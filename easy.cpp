#include "sudoku.h"
//for easy number of givens 36-49
//32 to 37 holes
void Easy()
{
	int i,j,k,v,max,count,c1,temp,a;
	max=rand()%6+32;
	for(k=0;k<max;++k)
	{
		i=rand()%9+1;
		j=rand()%9+1;
		if(puzzle[i][j]==0)
		{
			--k;
			continue;
		}
		temp=puzzle[i][j];
		count=0;
		for(a=1;a<=9;++a)
			if(isSafe(i,j,a))
				++count;
		if(count>1)
		{
			--k;
			continue;
		}
		else
		{
			count=0;
			c1=0;
			for(a=1;a<=9;++a)
			{
				if(puzzle[i][a])
					++count;
				if(puzzle[a][j])
					++c1;
			}
			if(c1<4 || count<4)
			{
				--k;
				continue;
			}
			puzzle[i][j]=0;
		}
	}
}