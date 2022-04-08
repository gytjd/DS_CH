//
//  6-2.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "6-2.h"
#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
    if (!((p) = malloc(s))) {\
        fprintf(stderr, "Insufficient memory.");\
        exit(EXIT_FAILURE);\
    }

int main()
{
    int *pi;
    float *pf;
    
    MALLOC(pi, sizeof(int));
    MALLOC(pf, sizeof(float));
    
    *pi=1024;
    *pf=3.14;
    
    printf("an integer =%d,a float = %f\n",*pi,*pf);
    free(pi);
    free(pf);
    
    return 0;
    
}
