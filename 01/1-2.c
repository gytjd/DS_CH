//
//  1-2.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "1-2.h"
#include <stdio.h>


void display_matrix(int (*pa)[3])
{
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%2d",pa[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int ary[2][3]={{4,2,3},{5,2,3}};
    int i,j;
    
    printf("ary를 이용한 출력\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%2d",ary[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("p를 이용한 출력\n");
    display_matrix(ary);
    
    return 0;
}
