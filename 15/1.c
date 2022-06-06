#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    char data;
    int value;
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
    new_node->value=0;
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
        s->top=new_node;
    }
}

treeNode *pop(stackType *s)
{
    stackNode *removed=s->top;
    treeNode *data=removed->data;
    
    s->top=removed->link;
    
    free(removed);
    
    return data;
}

void eval(treeNode *root,int a,int b,int c)
{
    if(root)
    {
        eval(root->leftChild, a, b, c);
        eval(root->rightChild,a,b,c);
        
        if(root->data=='&')
        {
            root->value=root->leftChild->value&root->rightChild->value;
        }
        else if(root->data=='|')
        {
            root->value=root->leftChild->value|root->rightChild->value;
        }
        else if(root->data=='~')
        {
            root->value=!root->rightChild->value;
        }
        else
        {
            if(root->data=='a')
            {
                root->value=a;
            }
            else if(root->data=='b')
            {
                root->value=b;
            }
            else if(root->data=='c')
            {
                root->value=c;
            }
        }
    }
}

void inorder_my(treeNode *root)
{
    if(root)
    {
        inorder_my(root->leftChild);
        printf("%c",root->data);
        inorder_my(root->rightChild);
    }
}
int main()
{
    FILE *fa;
    fa=fopen("input.txt","r");
    
    char data;
    stackType s;
    init_stack(&s);
    
    treeNode *op1,*op2;
    
    while(fscanf(fa, "%c",&data)!=EOF)
    {
        if(data=='&'||data=='|'||data=='~')
        {
            if(data=='~')
            {
                op1=pop(&s);
                
                push(&s, create_node(data, NULL, op1));
            }
            else
            {
                op2=pop(&s);
                op1=pop(&s);
                
                push(&s, create_node(data, op1, op2));
            }
        }
        else
        {
            push(&s, create_node(data, NULL, NULL));
        }
    }
    
    
    root=pop(&s);
    
    printf("\n\ninorder\n");
    inorder_my(root);
    printf("\n\n");
    
    int i,j,k;
    
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                eval(root, i, j, k);
                printf("%d %d %d : %d\n",i,j,k,root->value);
            }
        }
    }
    
    
    
    return 0;
}
