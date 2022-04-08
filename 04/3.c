//
//  3.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "3.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 100
#define MAX_COL 100

int **make2Array(int rows,int cols)
{
    int i;
    
    int **pa=(int **)malloc(sizeof(int*)*rows);
    for(i=0;i<rows;i++)
    {
        pa[i]=(int *)malloc(sizeof(int)*cols);
    }
    
    return pa;
}

void inputMatrix(int **pa,int rows,int cols)
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            scanf("%d",&pa[i][j]);
        }
    }
}

void printMatrix(int **ary,int rows,int cols)
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

void addMatrix(int **a,int **b,int **c,int rows,int cols)
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

void free2dArray(int **ary,int rows)
{
    int i;
    for(i=0;i<rows;i++)
    {
        free(*(ary+i));
    }
    free(ary);
    
    printf("2d array - free!!\n");
}
int main()
{
    int a,b;
    int **pa,**pb,**pc;
    printf("Enter row size and column size >> ");
    scanf("%d %d",&a,&b);
    
    pa=make2Array(a, b);
    pb=make2Array(a, b);
    pc=make2Array(a, b);
    
    printf("input data for %d X %d matrix A >> ",a,b);
    inputMatrix(pa, a, b);
    printf("input data for %d X %d matrix B >> ",a,b);
    inputMatrix(pb, a, b);
    
    printf("matrix A\n");
    printMatrix(pa, a, b);
    printf("\n");
    
    printf("matrix B\n");
    printMatrix(pb, a, b);
    printf("\n");
    
    addMatrix(pa, pb, pc, a, b);
    printf("matrix C\n");
    printMatrix(pc, a, b);
    printf("\n\n");
    free2dArray(pa, 2);
    free2dArray(pb, 2);
    free2dArray(pc, 2);
    
    return 0;
}
