//
//  4.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "4.h"
#include <stdio.h>

int sumAry2D_fl(int pa[][3],int ROW,int COL)
{
    int i,j;
    int sum=0;
    
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            sum+=pa[i][j];
        }
    }
    return sum;
}

int sumAry2D_f2(int (*pa)[3],int ROW,int COL)
{
    int i,j;
    int sum=0;
    
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            sum+=pa[i][j];
        }
    }
    return sum;
}

int sumAry2D_f3(int pa[2][3],int ROW,int COL)
{
    int i,j;
    int sum=0;
    
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            sum+=pa[i][j];
        }
    }
    return sum;
}

int main()
{
    int ary2D[][3]={{1,2,3},{4,5,6}};
    
    printf("sumAry2D_fl() %d\n",sumAry2D_fl(ary2D,2,3));
    printf("sumAry2D_f2( %d\n",sumAry2D_f2(ary2D,2,3));
    printf("sumAry2D_f3() %d\n",sumAry2D_f3(ary2D,2,3));
}
