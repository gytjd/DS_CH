//
//  2.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/09.
//

#include "2.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int row;
    int col;
    int num;
}term;

void display_matrix(term p[],int row,int col,int num)
{
    int i,j;
    
    int **ary=(int **)malloc(sizeof(int*)*row);
    for(i=0;i<row;i++)
    {
        ary[i]=(int *)malloc(sizeof(int)*col);
    }
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            ary[i][j]=0;
        }
    }
    
    for(i=1;i<=num;i++)
    {
        ary[p[i].row][p[i].col]=p[i].num;
    }
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf(" %2d ",ary[i][j]);
        }
        printf("\n");
    }
    
    for(i=0;i<row;i++)
    {
        free(*(ary+i));
    }
    free(ary);
}

void transpost(term a[],term b[])
{
    int n,i,j,currentb;
    
    n=a[0].num;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].num=n;
    
    if(n>0)
    {
        currentb=1;
        
        for(i=0;i<a[0].col;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[j].col==i)
                {
                    b[currentb].row=a[j].col;
                    b[currentb].col=a[j].row;
                    b[currentb].num=a[j].num;
                    currentb++;
                }
            }
        }
    }
}
int main()
{
    term A[MAX_SIZE];
    term B[MAX_SIZE];
    
    FILE *fa,*fb;
    fa=fopen("a.txt", "r");
    fb=fopen("b.txt","w");
    
    int i;
    
    fscanf(fa, "%d %d %d",&A[0].row,&A[0].col,&A[0].num);
    
    for(i=1;i<=A[0].num;i++)
    {
        fscanf(fa, "%d %d %d",&A[i].row,&A[i].col,&A[i].num);
    }
    
    printf("A\n");
    display_matrix(A,A[0].row,A[0].col,A[0].num);
    
    printf("B\n");
    transpost(A, B);

    display_matrix(B,B[0].row,B[0].col,B[0].num);
    
    for(i=0;i<=B[0].num;i++)
    {
        fprintf(fb,"%d %d %d\n",B[i].row,B[i].col,B[i].num);
    }
    
    return 0;
}
