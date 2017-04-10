#include "sudoku.h"
//for evil number of givens 20-25
//56 to 61 holes
void Evil()
{
	int i,j,k,max,count,temp,a;
	max=rand()%6+56;
	i=rand()%9+1;
	j=0;
	// Sequence of digging -------- Left to Right then Top to Bottom
	for(k=0;k<max;++k)
	{
		++j;
		if(j>=10)
		{
			i=(i+1)%9+1;
			j=0;
		}
		if(puzzle[i][j]==0)
		{
			--k;
			continue;
		}
		count=0;
		temp=puzzle[i][j];
		for(a=1;a<=9;++a)
			if(isSafe(i,j,a))
				++count;
		if(count>1)
		{
			puzzle[i][j]=temp;
			--k;
			continue;
		}
		else
			puzzle[i][j]=0;

	}
}