//
//  1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "1.h"
#include <stdio.h>
#include <stdlib.h>

int sumAry2D_f1(int ary[][3],int row,int col)
{
    int i,j;
    int sum=0;
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            sum+=ary[i][j];
        }
    }
    return sum;
}


int sumAry2D_f2(int (*ary)[3],int row,int col)
{
    int i,j;
    int sum=0;
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            sum+=ary[i][j];
        }
    }
    return sum;
}


int sumAry2D_f3(int ary[2][3],int row,int col)
{
    int i,j;
    int sum=0;
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            sum+=ary[i][j];
        }
    }
    return sum;
}

int sumAry2D_f4(int **ary,int row,int col)
{
    int i,j;
    int sum=0;
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            sum+=ary[i][j];
        }
    }
    
    return sum;
}

int sumAry2D_f5(int ***ary,int row,int col)
{
    int i,j;
    int sum=0;
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            sum+=*(*(*ary+i)+j);
        }
    }
    
    return sum;
}

void freeAry2D(int **pa,int n)
{
    int i;
    
    for(i=0;i<n;i++)
    {
        free(*(pa+i));
    }
    free(pa);
    
    printf("2d array - free!!!\n");
}
int main()
{
    int ary2D[2][3]={{1,2,3},{4,5,6}};
    
    int r,c;
    int **ary=(int **)malloc(sizeof(int *)*2);
    for(r=0;r<2;r++)
    {
        ary[r]=(int *)malloc(sizeof(int)*3);
    }
    
    for(r=0;r<2;r++)
    {
        for(c=0;c<3;c++)
        {
            ary[r][c]=r+c;
            
        }
    }
    
    printf("sumAry2D_f1() %d\n",sumAry2D_f1(ary2D, 2, 3));
    printf("sumAry2D_f2() %d\n",sumAry2D_f2(ary2D, 2, 3));
    printf("sumAry2D_f3() %d\n",sumAry2D_f3(ary2D, 2, 3));
    printf("sumAry2D_f4() %d\n",sumAry2D_f4(ary, 2, 3));
    printf("sumAry2D_f5() %d\n",sumAry2D_f5(&ary, 2, 3));
    
    freeAry2D(ary, 2);
    
    return 0;
}
