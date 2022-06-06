#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct graphNode {
    int data;
    struct graphNode *link;
}graphNode;

typedef struct graphType {
    graphNode *adj_list[MAX_SIZE];
    int n;
}graphType;

int visited[MAX_SIZE];

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_graph(graphType *g)
{
    g->n=0;
    
    int i;
    for(i=0;i<MAX_SIZE;i++)
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
        printf("graph[%d] : ",i);
        temp=g->adj_list[i];
        
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

void init_visited(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
}


typedef struct queueNode {
    int data;
    struct queueNode *link;
}queueNode;

typedef struct queueType {
    queueNode *front;
    queueNode *rear;
}queueType;

void init_queue(queueType *q)
{
    q->front=NULL;
    q->rear=NULL;
}

int is_queue_empty(queueType *q)
{
    return q->front==NULL && q->rear==NULL;
}

void enqueue(queueType *q,int data)
{
    queueNode *new_node=(queueNode *)malloc(sizeof(queueNode));
    new_node->data=data;
    new_node->link=NULL;
    
    if(is_queue_empty(q))
    {
        q->front=new_node;
        q->rear=new_node;
    }
    else
    {
        q->rear->link=new_node;
        q->rear=new_node;
    }
}

int dequeue(queueType *q)
{
    queueNode *removed=q->front;
    int data=removed->data;
    
    q->front=removed->link;
    
    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    
    free(removed);
    
    return data;
}

void BFS(graphType *g,int start)
{
    queueType q;
    init_queue(&q);
    
    enqueue(&q, start);
    visited[start]=1;
    
    graphNode *w;
    
    int temp;
    
    while(!is_queue_empty(&q))
    {
        temp=dequeue(&q);
        printf("%d ",temp);
        w=g->adj_list[temp];
        
        while(w!=NULL)
        {
            if(!visited[w->data])
            {
                enqueue(&q, w->data);
                visited[w->data]=1;
            }
            
            w=w->link;
        }
        
    }
}

int main()
{
    FILE *fa;
    fa=fopen("input.txt","r");
    
    int i;
    int verNum,edgeNum;
    int start,end;
    
    graphType g;
    init_graph(&g);
    
    fscanf(fa, "%d %d",&verNum,&edgeNum);
    
    g.n=verNum;
    
    for(i=0;i<edgeNum;i++)
    {
        fscanf(fa, "%d %d",&start,&end);
        insert_edge(&g, start, end);
    }
    
    display_graph(&g);
    
    printf("Depth First Search\n");
    for(i=0;i<verNum;i++)
    {
        init_visited(verNum);
        printf("Bfs [%d]  : ",i);
        BFS(&g, i);
        printf("\n");
    }
    return 0;
}
