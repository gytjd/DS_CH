#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct {
    int key;
    char name[20];
    int grade;
}element;

void display(element *pa,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("( %d, %s, %d)\n",pa[i].key,pa[i].name,pa[i].grade);
    }
    printf("\n");
}

void insertion_sort(element *pa,int n)
{
    int i,j;
    element key;
    
    for(i=1;i<n;i++)
    {
        key=pa[i];
        
        for(j=i-1;j>=0 && pa[j].key>key.key;j--)
        {
            pa[j+1]=pa[j];
        }
        pa[j+1]=key;
    }
}

int main()
{
    int i,n;
    FILE *fa;
    element data[MAX_SIZE];
    
    fa=fopen("input.txt","r");
    
    fscanf(fa, "%d",&n);
    
    for(i=0;i<n;i++)
    {
        fscanf(fa, "%d %s %d",&data[i].key,data[i].name,&data[i].grade);
    }
    display(data, n);
    
    insertion_sort(data, n);
    
    display(data, n);
    
    return 0;
}
