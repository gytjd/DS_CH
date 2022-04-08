//
//  1-1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "1-1.h"
#include <stdio.h>

void display(int *pa)
{
    int i;
    for(i=0;i<3;i++)
    {
        printf("%2d",pa[i]);
    }
    printf("\n");
}

int main()
{
    int i;
    int ary[3]={8,2,8};
    
    printf("ary를 이용한 출력\n");
    for(i=0;i<3;i++)
    {
        printf("%2d",ary[i]);
    }
    printf("\n\n");
    
    printf("p를 이용한 출력 \n");
    display(ary);
    
    return 0;
}
