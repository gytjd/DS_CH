#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int key;
}element;

typedef struct heapType {
    element heap[MAX_SIZE];
    int heap_size;
}heapType;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_heap(heapType *h)
{
    h->heap_size=0;
}

int is_heap_empty(heapType *h)
{
    return h->heap_size==0;
}

void insert_max_heap(heapType *h,element data)
{
    int i=++h->heap_size;
    
    while(i!=1 && h->heap[i/2].key<data.key)
    {
        h->heap[i]=h->heap[i/2];
        i/=2;
    }
    h->heap[i]=data;
}

element delete_max_heap(heapType *h)
{
    element data=h->heap[1];
    element temp=h->heap[h->heap_size--];
    
    int parent=1;
    int child=2;
    
    while(child<=h->heap_size)
    {
        if(child<=h->heap_size && h->heap[child].key<h->heap[child+1].key)
        {
            child++;
        }
        
        if(temp.key>h->heap[child].key)
        {
            break;
        }
        
        h->heap[parent]=h->heap[child];
        parent=child;
        child*=2;
    }
    
    h->heap[parent]=temp;
    return data;
}

void display_heap(heapType *h)
{
    int i;
    for(i=1;i<=h->heap_size;i++)
    {
        printf("%d ",h->heap[i].key);
    }
    printf("\n");
}

int main()
{
    FILE *fa;
    fa=fopen("input.txt","r");
    
    heapType h;
    init_heap(&h);
    
    element data;
    printf("-------------------------\n");
    printf("insertion into a max heap\n");
    printf("-------------------------\n");
    while(fscanf(fa, "%d",&data.key)!=EOF)
    {
        insert_max_heap(&h, data);
        display_heap(&h);
    }
    
    printf("-------------------------\n");
    printf("deletion from a max heap\n");
    printf("-------------------------\n");
    while(!is_heap_empty(&h))
    {
        delete_max_heap(&h);
        display_heap(&h);
    }
    
    
    return 0;
}

