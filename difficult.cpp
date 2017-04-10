#include "sudoku.h"
//for difficult number of givens 28-31
//50 to 53 holes
void Difficult()
{
	int i,j,k,max,count,temp,c1,a;
	max=rand()%3+50;
	i=rand()%9+1;
	j=0;
	// Sequence of digging --------------- Left to Right then Top to Bottom
	//We can also use S-form
	for(k=0;k<=max;++k)
	{
		++j;
		if(j>=10)
		{
			i=(i+1)%9+1;
			j=0;
			--k;
			continue;
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
		//now check for lower bound
		//atleast 2 givens in each row and col
		else
		{
			count=0;
			c1=0;
			for(a=1;a<=10;++a)
			{
				if(puzzle[i][a])
					++count;
				if(puzzle[a][j])
					++c1;
			}
			if(count<2 || c1<2)
			{
				--k;
				continue;
			}
			else puzzle[i][j]=0;
		}
	}
}