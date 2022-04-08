//
//  1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "1.h"
#include <stdio.h>

#define MAX_ROWS 3
#define MAX_COLS 4

void add(int a[][MAX_COLS],int b[][MAX_COLS],int c[][MAX_COLS],int rows,int cols)
{
    int i,j;
    int stepCount=0;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            stepCount++;
        }
    }
    
    printf("step count : %d\n",stepCount);
}
int main()
{
    int i,j;
    
    FILE *fa;
    FILE *fb;
    
    fa=fopen("a.txt", "r");
    fb=fopen("b.txt","r");
    
    
    
    int a[MAX_ROWS][MAX_COLS];
    int b[MAX_ROWS][MAX_COLS];
    int c[MAX_ROWS][MAX_COLS];
    
    for(i=0;i<MAX_ROWS;i++)
    {
        for(j=0;j<MAX_COLS;j++)
        {
            fscanf(fa,"%d",&a[i][j]);
            fscanf(fb,"%d",&b[i][j]);
        }
    }
    
    
    
    add(a, b, c, MAX_ROWS, MAX_COLS);
    
    fclose(fa);
    fclose(fb);
    
    
    return 0;
}
