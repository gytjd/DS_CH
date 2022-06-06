#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICS 20

typedef struct graphNode {
    int data;
    struct graphNode *link;
}graphNode;

typedef struct graphType {
    graphNode *adj_list[MAX_VERTICS];
    int n;
}graphType;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_graph(graphType *g)
{
    g->n=0;
    
    int i;
    for(i=0;i<MAX_VERTICS;i++)
    {
        g->adj_list[i]=NULL;
    }
}

void make_edge(graphType *g,int start,int end)
{
    graphNode *new_node=(graphNode *)malloc(sizeof(graphNode));
    new_node->data=end;
    new_node->link=NULL;
    
    if(g->adj_list[start]==NULL)
    {
        g->adj_list[start]=new_node;
    }
    else
    {
        new_node->link=g->adj_list[start];
        g->adj_list[start]=new_node;
    }
}

void insert_edge(graphType *g,int start,int end)
{
    make_edge(g, start, end);
    make_edge(g, end, start);
}

void display_graph(graphType *g)
{
    int i;
    graphNode *temp;
    
    for(i=0;i<g->n;i++)
    {
        temp=g->adj_list[i];
        printf("adjList[%d] : ",i);
        
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

int main()
{
    FILE *fa;
    fa=fopen("input.txt","r");
    
    int i;
    char mode;
    int verNum,edgeNum;
    
    int start,end;
    
    graphType g;
    init_graph(&g);
    
    fscanf(fa, "%c %d %d",&mode,&verNum,&edgeNum);
    
    g.n=verNum;
    
    for(i=0;i<edgeNum;i++)
    {
        fscanf(fa,"%d %d",&start,&end);
        insert_edge(&g,start,end);
    }
    
    display_graph(&g);
    
    return 0;
    
}
