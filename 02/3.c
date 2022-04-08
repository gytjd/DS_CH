//
//  3.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "3.h"
#include <stdio.h>
#include <stdlib.h>

int *alloc(int n)
{
    int *pa=(int *)malloc(sizeof(int));
    
    return pa;
    
}

void input(int *p,int num,FILE *fa)
{
    int i;
    for(i=0;i<num;i++)
    {
        fscanf(fa,"%d",&p[i]);
    }
}

void increase(int *p,int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        p[i]++;
    }
}
void output(int *p,int num,FILE *fb)
{
    int i;
    fprintf(fb, "%d\n",num);
    for(i=0;i<num;i++)
    {
        fprintf(fb, "%d ",p[i]);
    }
}
int main()
{
    int num,*pNum;
    
    FILE *fa;
    FILE *fb;
    
    fa=fopen("input.txt","r");
    fb=fopen("output.txt","w");
    
    fscanf(fa,"%d",&num);
    pNum=alloc(num);
    input(pNum, num, fa);
    increase(pNum, num);
    output(pNum, num, fb);
    
    free(pNum);
    fclose(fa);
    fclose(fb);
    
    return 0;
}
