#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int static count=0;

void display(int *pa,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",pa[i]);
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

int partition(int *pa,int left,int right)
{
    int low,high;
    int pivot=pa[left];
    
    low=left;
    high=right+1;
    
    do {
        
        do {
            low++;
        }
        while(low<=right && pa[low]<pivot);
        
        do {
            high--;
        }
        while(high>=left && pa[high]>pivot);
        
        if(low<high)
        {
            SWAP(&pa[low],&pa[high]);
        }
    }
    while(low<high);
    
    SWAP(&pa[left], &pa[high]);
    
    return high;
}

void quick_sort(int *pa,int left,int right)
{
    int q;
    count++;
    
    if(left<right)
    {
        q=partition(pa, left, right);
        quick_sort(pa, left, q-1);
        quick_sort(pa, q+1, right);
    }
}
int main()
{
    int list[MAX_SIZE]={12,2,16,30,8,28,4,10,20,6,18};
    
    display(list, 11);
    
    quick_sort(list, 0, 10);
    
    display(list, 11);
    printf("%d \n",count);
    
    return 0;

}
