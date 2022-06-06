#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    char data;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
}treeNode;

typedef struct stackNode {
    treeNode *data;
    struct stackNode *link;
}stackNode;

typedef struct stackType {
    stackNode *top;
}stackType;

treeNode *root=NULL;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_stack(stackType *s)
{
    s->top=NULL;
}

int is_stack_empty(stackType *s)
{
    return s->top==NULL;
}

treeNode *create_node(char data,treeNode *left,treeNode *right)
{
    treeNode *new_node=(treeNode *)malloc(sizeof(treeNode));
    new_node->data=data;
    new_node->leftChild=left;
    new_node->rightChild=right;

    
    return new_node;
}

void push(stackType *s,treeNode *data)
{
    stackNode *new_node=(stackNode *)malloc(sizeof(stackNode));
    new_node->data=data;
    new_node->link=NULL;
    
    if(is_stack_empty(s))
    {
        s->top=new_node;
    }
    else
    {
        new_node->link=s->top;
        s->top=new_node;;
    }
}

treeNode *pop(stackType *s)
{
    if(is_stack_empty(s))
    {
        return NULL;
    }
    
    stackNode *removed=s->top;
    treeNode *data=removed->data;
    
    s->top=removed->link;
    
    free(removed);
    
    return data;
}

typedef struct queueNode {
    treeNode *data;
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
    return (q->front==NULL && q->rear==NULL);
}

void enqueue(queueType *q,treeNode *data)
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

treeNode *dequeue(queueType *q)
{
    queueNode *removed=q->front;
    treeNode *data=removed->data;
    
    q->front=removed->link;
    
    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    
    free(removed);
    
    return data;
}

void preorder_iter(treeNode *root)
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


void inorder_iter(treeNode *root)
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
void level_order(treeNode *root)
{
    queueType q;
    init_queue(&q);
    
    enqueue(&q, root);
    treeNode *temp;
    
    while(!is_queue_empty(&q))
    {
        temp=dequeue(&q);
        
        printf("%c",temp->data);
        
        if(temp->leftChild!=NULL)
        {
            enqueue(&q, temp->leftChild);
            
        }
        
        if(temp->rightChild!=NULL)
        {
            enqueue(&q, temp->rightChild);
        }
    }
}

int main()
{
    FILE *fa;
    fa=fopen("input.txt","r");
    
    char data;
    stackType s;
    treeNode *op1,*op2;
    init_stack(&s);
    
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
    
    root=pop(&s);
    
    printf("\n\niterative inorder traversal \n");
    inorder_iter(root);
    
    printf("\n\niterative preorder traversal \n");
    preorder_iter(root);
    
    printf("\n\nlevel order\n");
    level_order(root);
    printf("\n");
    
    return 0;
    
}
