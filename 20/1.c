#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int sorted[MAX_SIZE];

void display(int *pa,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%2d ",pa[i]);
    }
    printf("\n");
}

void merge(int *pa,int left,int right,int mid)
{
    int i,j,k,l;
    
    i=left;
    j=mid+1;
    k=left;
    
    while(i<=mid && j<=right)
    {
        if(pa[i]<pa[j])
        {
            sorted[k++]=pa[i++];
        }
        else
        {
            sorted[k++]=pa[j++];
        }
    }
    
    if(i>mid)
    {
        for(;j<=right;j++)
        {
            sorted[k++]=pa[j];
        }
    }
    else
    {
        for(;i<=mid;i++)
        {
            sorted[k++]=pa[i];
        }
    }
    
    for(l=left;l<=right;l++)
    {
        pa[l]=sorted[l];
    }
    
}
void merge_sort(int *pa,int left,int right)
{
    int mid=(left+right)/2;
    
    if(left<right)
    {
        merge_sort(pa, left, mid);
        merge_sort(pa, mid+1, right);
        merge(pa, left, right, mid);
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
    
    display(list, n);
    
    merge_sort(list, 0, n-1);
    
    display(list, n);
    
    return 0;
}
