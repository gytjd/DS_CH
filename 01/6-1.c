//
//  6-1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "6-1.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *pi;
    float *pf;
    
    
    
    if(((pi=((int *)malloc(sizeof(int))))==NULL||((pf=(float *)malloc(sizeof(float))))==NULL))
    {
        fprintf(stderr,"Insufficient memory");
        exit(EXIT_FAILURE);
    }
    
    *pi=1024;
    *pf=3.14;
    
    printf("an integer =%d,a float = %f\n",*pi,*pf);
    free(pi);
    free(pf);
    
    return 0;
}
