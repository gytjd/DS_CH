//
//  2.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/28.
//

#include "2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node* nodePointer;
typedef struct node {
    char data;
    nodePointer leftChild;
    nodePointer rightChild;
    int visited;
}node;

typedef struct queueType {
    nodePointer queue[MAX_SIZE];
    int front;
    int rear;
}queueType;

typedef struct stackType {
    nodePointer stack[MAX_SIZE];
    int top;
}stackType;

nodePointer root=NULL;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_stack(stackType *s)
{
    s->top=-1;
}

int is_stack_empty(stackType *s)
{
    return s->top==-1;
}

int is_stack_full(stackType *s)
{
    return s->top==MAX_SIZE-1;
}

void push(stackType *s,nodePointer pNode)
{
    if(is_stack_full(s))
    {
        error("stack is full, cannot push element");
    }
    s->stack[++(s->top)]=pNode;
}

nodePointer pop(stackType *s)
{
    if(is_stack_empty(s))
    {
        return NULL;
    }
    
    return s->stack[(s->top)--];
}

void init_queue(queueType *q)
{
    q->front=-1;
    q->rear=-1;
}

int is_queue_empty(queueType *q)
{
    return q->front==q->rear;
}

int is_queue_full(queueType *q)
{
    return q->rear==MAX_SIZE-1;
}

void enqueue(queueType *q,nodePointer pNode)
{
    if(is_queue_full(q))
    {
        error("queue is full, cannot add element");
    }
    q->queue[++(q->rear)]=pNode;
}


nodePointer dequeue(queueType *q)
{
    if(is_queue_empty(q))
    {
        error("queue is empty, cannot delete element");
    }
    return q->queue[++(q->front)];
}

nodePointer create_node(char data,nodePointer left,nodePointer right)
{
    nodePointer new_node=(nodePointer)malloc(sizeof(node));
    new_node->data=data;
    new_node->leftChild=left;
    new_node->rightChild=right;
    new_node->visited=0;
    
    return new_node;
}

nodePointer createBinTree(void)
{
    stackType s;
    init_stack(&s);
    
    char data;
    nodePointer op1,op2;
    
    FILE *fa;
    fa=fopen("input.txt", "r");
    
    while(fscanf(fa, "%c",&data)!=EOF)
    {
        printf("%c",data);
        if(data=='+'||data=='-'||data=='*'||data=='/'||data=='%')
        {
            op2=pop(&s);
            op1=pop(&s);
            push(&s, create_node(data, op1, op2));
        }
        else
        {
            push(&s, create_node(data, NULL, NULL));
        }
    }
    
    return pop(&s);
}

void inorder_iteration(nodePointer root)
{
    stackType s;
    init_stack(&s);
    
    while(1)
    {
        while(root!=NULL)
        {
            push(&s, root);
            root=root->leftChild;
        }
        
        root=pop(&s);
        
        if(root==NULL)
        {
            break;
        }
        
        printf("%c",root->data);
        root=root->rightChild;
    }
}

void preorder_iteration(nodePointer root)
{
    stackType s;
    init_stack(&s);
    
    while(1)
    {
        while(root!=NULL)
        {
            printf("%c",root->data);
            push(&s, root);
            root=root->leftChild;
        }
        
        root=pop(&s);
        
        if(root==NULL)
        {
            break;
        }
        
        
        root=root->rightChild;
    }
}

void levelorder_iteration(nodePointer root)
{
    queueType q;
    nodePointer temp;
    
    init_queue(&q);
    enqueue(&q, root);
    
    while(!is_queue_empty(&q))
    {
        temp=dequeue(&q);
        printf("%c",temp->data);
        
        if(temp->leftChild)
        {
            enqueue(&q, temp->leftChild);
        }
        if(temp->rightChild)
        {
            enqueue(&q, temp->rightChild);
        }
    }
}

void postorder_iterative(nodePointer root)
{
    stackType s;
    init_stack(&s);
    
    while(1)
    {
        while(root!=NULL)
        {
            push(&s, root);
            root=root->leftChild;
        }
        root=pop(&s);
        
        if(root==NULL)
        {
            break;
        }
        
        if(root->rightChild!=NULL)
        {
            if(root->rightChild->visited==0)
            {
                push(&s, root);
                root=root->rightChild;
            }
            else
            {
                root->visited=1;
                printf("%c",root->data);
                root=NULL;
            }
        }
        else
        {
            root->visited=1;
            printf("%c",root->data);
            root=root->rightChild;
        }
    }
    
    
}
int main()
{
    printf("the length of input string should be less than 80\n");
    printf("input string <postfix expression> : ");
    root=createBinTree();
    
    printf("\ncreating its binary tree\n\n");
    
    printf("iterative inorder traversal   : ");
    inorder_iteration(root);
    printf("\n");
    
    printf("iterative preorder traversal  : ");
    preorder_iteration(root);
    printf("\n");
    
    printf("level order traversal         : ");
    levelorder_iteration(root);
    printf("\n");
    
    printf("iterative postorder traversal : ");
    postorder_iterative(root);
    printf("\n");
    
    
    
    return 0;
}
