//
//  1-1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "1-1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void display(int *pa,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d   ",pa[i]);
    }
    printf("\n");
}

void SWAP(int *pa,int *pb)
{
    int temp;
    
    temp=*pa;
    *pa=*pb;
    *pb=temp;
    
}
void selection_sort(int *pa,int n)
{
    int i,j,minpos;
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
        
        SWAP(&pa[i], &pa[minpos]);
    }
}

int binary_search(int *pa,int start,int end,int num)
{
   
    while(start<=end)
    {
        int mid=(start+end)/2;
        
        if(pa[mid]>num)
        {
            end=mid-1;
        }
        else if(pa[mid]<num)
        {
            start=mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    int ary[MAX_SIZE];
    int a,i;
    int searchNum;
    int searchResult;
    
    
    srand((unsigned)time(NULL));
    
    printf("Enter the number of numbers to generate :  ");
    scanf("%d",&a);
    
    for(i=0;i<a;i++)
    {
        ary[i]=rand()%1000;
    }
    display(ary, a);
    
    selection_sort(ary, a);
    printf("\n\nSorted array : \n");
    display(ary, a);
    
    printf("\n");
    printf("Enter the number to search : ");
    scanf("%d",&searchNum);
    
    searchResult=binary_search(ary, 0, a-1, searchNum);
    
    if(searchResult!=-1)
    {
        printf("The search number is present in list[%2d]\n",searchResult);
    }
    else
    {
        printf("The search number is not present\n");
    }
    
    return 0;
}

