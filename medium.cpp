#include "sudoku.h"
//for medium number of givens 32-35
//46 to 49 holes
void Medium()
{
	int i,j,k,v,max,count,c1,temp,a;
	max=rand()%4+46;
	// Seqence of digging -------------------- Randomized Globally
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
			if(c1<3 || count<3)
			{
				--k;
				continue;
			}
			puzzle[i][j]=0;
		}
	}
	//Jumping One Cell
	/*i=rand()%9+1;
	j=rand()%9+1;
	for(k=0;k<max;++k)
	{
		//cout<<"Hello\n";
		printf("Hello\n");
		j+=2;
		if(j>9)
		{
			j=(j+1)%9;
			i=(i+1)%9+1;
		}
		if(puzzle[i][j]==0)
		{
			--k;
			continue;
		}
		printf("             Bye\n");
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
		//check for lower bound
		//atleast 3 givens
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
			if(count<3 || c1<3)
			{
				--k;
				continue;
			}
			else puzzle[i][j]=0;
		}
	}*/
}
