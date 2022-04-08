//
//  2.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "2.h"
#include <stdio.h>

int main()
{
    int a=2;
    int b=3;
    int c=4;
    
    int *ary[3];
    ary[0]=&a;
    ary[1]=&b;
    ary[2]=&c;
    
    printf("포인터 배열의 배열요소를 이용한 a,b,c 출력\n");
    printf("a : %d, b : %d, c : %d\n",*ary[0],*ary[1],*ary[2]);
    
    return 0;
}
