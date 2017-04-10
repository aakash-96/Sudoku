#include<bits/stdc++.h>
#include "sudoku.h"
void Print()
{
	int i,j,k;
	for(i=1;i<=9;++i)
	{
		if((i-1)%3==0 && i!=1)
			printf("\n");
		for(j=1;j<=9;++j)
		{
			if((j-1)%3==0 && j!=1)
				printf("  ");
			printf("%d ",puzzle[i][j]);
		}
		printf("\n");
	}
}
