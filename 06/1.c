//
//  1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/10.
//

#include "1.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_COL 100
#define MAX_ROW 100

#define MAX_TERMS 101
#define MAX_SIZE 100

typedef struct {
    int row;
    int col;
    int value;
}term;

term a[MAX_TERMS];
term b[MAX_TERMS];

void display(int (*ary)[MAX_SIZE],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf(" %2d",ary[i][j]);
        }
        printf("\n");
    }
}

void fastTranspose(term a[],term b[])
{
    FILE *fb;
    fb=fopen("b.txt","w");
    
    int rowTerms[MAX_COL],startingPos[MAX_COL];
    
    int i,j,numCols=a[0].col,numTerms=a[0].value;
    b[0].row=numCols;
    b[0].col=a[0].row;
    b[0].value=numTerms;
    
    if(numTerms>0)
    {
        for(i=0;i<numCols;i++)
        {
            rowTerms[i]=0;
        }
        for(i=1;i<=numTerms;i++)
        {
            rowTerms[a[i].col]++;
        }
        startingPos[0]=1;
        
        for(i=1;i<numCols;i++)
        {
            startingPos[i]=startingPos[i-1]+rowTerms[i-1];
        }
        for(i=1;i<=numTerms;i++)
        {
            j=startingPos[a[i].col]++;
            b[j].row=a[i].col;
            b[j].col=a[i].row;
            b[j].value=a[i].value;

        }
    }
    
    for(i=0;i<=b[0].value;i++)
    {
        fprintf(fb, "%d %d %d\n",b[i].row,b[i].col,b[i].value);
    }
}
int main()
{
    int i,j;
    int ary[MAX_SIZE][MAX_SIZE]={0};
    int bry[MAX_SIZE][MAX_SIZE]={0};
    FILE *fa;
    fa=fopen("a.txt", "r");
    
    fscanf(fa, "%d %d %d",&a[0].row,&a[0].col,&a[0].value);
    
    for(i=1;i<=a[0].value;i++)
    {
        fscanf(fa, "%d %d %d",&a[i].row,&a[i].col,&a[i].value);
        
        ary[a[i].row][a[i].col]=a[i].value;
    }

    
    printf("A\n");
    display(ary, a[0].row, a[0].col);
    
    
    fastTranspose(a, b);
    
    for(i=1;i<=b[0].value;i++)
    {
        bry[b[i].row][b[i].col]=b[i].value;
    }
    
    printf("B\n");
    display(bry, b[0].row, b[0].col);
    
    return 0;
}
