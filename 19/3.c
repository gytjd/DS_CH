#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int static count=0;


void display(int *pa,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%2d ",pa[i]);
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
    
    low=left;
    high=right+1;
    
    int pivot=pa[left];
    
    do {
        do {
            low++;
        }
        while(low<=right && pivot>pa[low]);
        
        do {
            high--;
        }
        while(high>=left && pivot<pa[high]);
        
        if(low<high)
        {
            SWAP(&pa[low], &pa[high]);
        }
    }while(low<high);
    
    SWAP(&pa[left], &pa[high]);
    
    return high;
}

void quick_sort(int *pa,int left,int right)
{
    int q;
    count++;
    display(pa, 11);
    
    if(left<right)
    {
        q=partition(pa, left, right);
        quick_sort(pa, left, q-1);
        quick_sort(pa, q+1,right);
    }
}

int main()
{
    int i,n;
    int list[MAX_SIZE];
    
    FILE *fa;
    fa=fopen("output.txt","r");
    
    fscanf(fa, "%d",&n);
    
    for(i=0;i<n;i++)
    {
        fscanf(fa, "%d",&list[i]);
    }
    
    printf("Input List\n");
    display(list, n);
    
    
    printf("\n\nexecution of quick sort\n");
    
    quick_sort(list, 0, n-1);
    
    printf("\ncalls of quick sort : %d\n",count);
}
