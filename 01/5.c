//
//  5.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "5.h"
#include <stdio.h>

int sumAry3D_f1(int pa[][2][3],int SEC,int ROW,int COL)
{
    int i,j,k;
    int sum=0;
    
    for(i=0;i<SEC;i++)
    {
        for(j=0;j<ROW;j++)
        {
            for(k=0;k<COL;k++)
            {
                sum+=pa[i][j][k];
            }
        }
    }
    
    return sum;
}

int sumAry3D_f2(int (*pa)[2][3],int SEC,int ROW,int COL)
{
    int i,j,k;
    int sum=0;
    
    for(i=0;i<SEC;i++)
    {
        for(j=0;j<ROW;j++)
        {
            for(k=0;k<COL;k++)
            {
                sum+=pa[i][j][k];
            }
        }
    }
    
    return sum;
}

int sumAry3D_f3(int pa[2][2][3],int SEC,int ROW,int COL)
{
    int i,j,k;
    int sum=0;
    
    for(i=0;i<SEC;i++)
    {
        for(j=0;j<ROW;j++)
        {
            for(k=0;k<COL;k++)
            {
                sum+=pa[i][j][k];
            }
        }
    }
    
    return sum;
}

int main()
{
    int ary3D[][2][3]={{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
    
    printf("sumAry3D_f1() %d\n",sumAry3D_f1(ary3D,2,2,3));
    
    printf("sumAry3D_f2() %d\n",sumAry3D_f2(ary3D,2,2,3));
    
    printf("sumAry3D_f3() %d\n",sumAry3D_f3(ary3D,2,2,3));
    
    return 0;
}
