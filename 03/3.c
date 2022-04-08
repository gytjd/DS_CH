//
//  3.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "3.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void selection_sort(int *pa,int n)
{
    int i,j,minpos;
    int temp;
    for(i=0;i<n-1;i++)
    {
        minpos=i;
        for(j=i+1;j<n;j++)
        {
            if(pa[minpos]>pa[j])
            {
                minpos=j;
            }
        }
        SWAP(pa[i], pa[minpos], temp);
    }
}

void display(int *pa,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",pa[i]);
    }
    printf("\n");
}


int main()
{
    int i,j;
    int step=10;
    int ary[MAX_SIZE];
    
    double duration;
    
    srand((unsigned)time(NULL));
    
    printf("     n    repetitions    time\n");
    for(i=0;i<=2000;i+=step)
    {
        long repetitions=0;
        clock_t start=clock();
        
        do
        {
            repetitions++;
            
            for(j=0;j<i;j++)
            {
                ary[j]=rand()%1000;
            }
            selection_sort(ary, i);
        }while(clock()-start<1000);
        
        duration=((double)(clock()-start))/CLOCKS_PER_SEC;
        duration/=repetitions;
        printf("%6d   %9d   %f\n",i,repetitions,duration);
        if(i==100)
        {
            step=100;
        }
        
    }
    
    return 0;
}
