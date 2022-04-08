//
//  2.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "2.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 2
#define MAX_COL 3
void input2Array(int ary[][MAX_COL],int rows,int cols)
{
    int i,j;
    
    for(i=0;i<MAX_ROW;i++)
    {
        for(j=0;j<MAX_COL;j++)
        {
            scanf("%d",&ary[i][j]);
        }
    }

}

void print2dArray(int ary[][MAX_COL],int rows,int cols)
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%2d",ary[i][j]);
        }
        printf("\n");
    }
}

void add(int a[][MAX_COL],int b[][MAX_COL],int c[][MAX_COL],int rows,int cols)
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
}


int main()
{
    int ary1[MAX_ROW][MAX_COL];
    int ary2[MAX_ROW][MAX_COL];
    int ary3[MAX_ROW][MAX_COL];
    
    printf("input data for 2 X 3 matrix A >> ");
    input2Array(ary1, MAX_ROW, MAX_COL);
    printf("input data for 2 X 3 matrix B >> ");
    input2Array(ary2, MAX_ROW, MAX_COL);
    
    printf("\nmatrix A\n");
    print2dArray(ary1, MAX_ROW, MAX_COL);
    printf("\n");
    
    printf("matrix B\n");
    print2dArray(ary2, MAX_ROW, MAX_COL);
    printf("\n");
    
    add(ary1, ary2, ary3, MAX_ROW, MAX_COL);
    printf("matrix C\n");
    print2dArray(ary3, MAX_ROW, MAX_COL);
    printf("\n");
    
    
    return 0;
}
