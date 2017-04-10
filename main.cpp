#include "sudoku.h"
#include "output.cpp"
#include "solver.cpp"
#include "terminalpattern.cpp"
#include "exteasy.cpp"
#include "easy.cpp"
#include "medium.cpp"
#include "difficult.cpp"
#include "evil.cpp"

using namespace std;

int puzzle[10][10];
int main()
{
    int i,j,c;
    while(1)
	{
	    B:;
	    system("cls");
	    printf("Enter the choice.\n");
        printf("    1. Generate puzzle\n    2. Enter your own puzzle\n    3. EXIT\n");
        scanf("%d",&c);
        if(c==3)
            return 0;
        if(c==1)
        {
            system("cls");
            A:;
            printf("1. Extremely Easy\n2. Easy\n3. Medium\n4. Difficult\n5. Evil\n6.BACK\n\nEnter the choice\n");
            scanf("%d",&c);
            Generate();
            FillRandom();
            switch(c)
            {
                case 1: ExtEasy(); break;
                case 2: Easy(); break;
                case 3: Medium(); break;
                case 4: Difficult(); break;
                case 5: Evil(); break;
                case 6: goto B;
                default: printf("Enter VALID choice.\n"); goto A;
            }
            system("cls");
            Print();
            printf("Press 1 to get solution.\n");
            while(1)
            {
                scanf("%d",&i);
                if(i==1)
                {
                    FillSudoku();
                    printf("\n\n");
                    Print();
                    break;
                }
                else
                    printf("Press 1 to get solution.\n");
            }
            printf("Press 1 to continue\n");
            scanf("%d",&i);
        }
        else
        {
            printf("Enter the puzzle.\n");
            for(i=1;i<=9;++i)
                for(j=1;j<=9;++j)
                    scanf("%d",&puzzle[i][j]);
            FillSudoku();
            Print();
        }
	}
    return 0;
}
