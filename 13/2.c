#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 20
typedef struct treeNode {
    char data;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
}treeNode;

treeNode *root=NULL;
treeNode *queue[MAX_QUEUE_SIZE];
int front=-1;
int rear=-1;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_queue(void)
{
    int i;
    for(i=0;i<MAX_QUEUE_SIZE;i++)
    {
        queue[i]=NULL;
    }
}

treeNode *create_node(char data)
{
    treeNode *new_node=(treeNode *)malloc(sizeof(treeNode));
    new_node->data=data;
    new_node->leftChild=NULL;
    new_node->rightChild=NULL;
    
    return new_node;
}

void enqueue(treeNode *data)
{
    queue[++rear]=data;
}

treeNode *dequeue(void)
{
    return queue[++front];
}

treeNode *insert(treeNode *root)
{
    int i;
    for(i=0;i<9;i++)
    {
        if(root==NULL)
        {
            root=dequeue();
        }
        else
        {
            if(queue[front]->leftChild==NULL)
            {
                queue[front]->leftChild=queue[i];
            }
            else if(queue[front]->rightChild==NULL)
            {
                queue[front]->rightChild=queue[i];
                dequeue();
            }
        }
    }
    
    return root;
}

void inorder_my(treeNode *root)
{
    if(root)
    {
        inorder_my(root->leftChild);
        printf("%c ",root->data);
        inorder_my(root->rightChild);
    }
}

int main()
{
    char data;
    
    FILE *fa;
    fa=fopen("input.txt","r");
    
    init_queue();
    
    while(fscanf(fa,"%c",&data)!=EOF)
    {
        enqueue(create_node(data));
    }
    
    root=insert(root);
    inorder_my(root);
    
    
    return 0;
}
