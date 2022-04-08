//
//  1-3.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "1-3.h"
#include <stdio.h>


void display_matrix(int (*pa)[2][3])
{
    int i,j,k;
    
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<3;k++)
            {
                printf("%3d",pa[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
}
int main()
{
    int ary[2][2][3]={{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
    
    int i,j,k;
    
    printf("ary를 이용한 출력\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<3;k++)
            {
                printf("%3d",ary[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    
    printf("p를 이용한 출력\n");
    display_matrix(ary);
    
    return 0;
}
