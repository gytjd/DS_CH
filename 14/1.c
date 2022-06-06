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
    stackNode *removed=s->top;
    treeNode *data=removed->data;
    
    s->top=removed->link;
    
    free(removed);
    
    return data;
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

void preorder_my(treeNode *root)
{
    if(root)
    {
        printf("%c",root->data);
        preorder_my(root->leftChild);
        preorder_my(root->rightChild);
    }
}

void postorder_my(treeNode *root)
{
    if(root)
    {
        postorder_my(root->leftChild);
        postorder_my(root->rightChild);
        printf("%c",root->data);
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
    
    printf("\n\ninorder\n");
    inorder_my(root);
    
    printf("\n\npreorder\n");
    preorder_my(root);
    
    printf("\n\npostorder\n");
    postorder_my(root);
    printf("\n");
    
    return 0;
    
}
