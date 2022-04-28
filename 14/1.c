//
//  1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/28.
//

#include "1.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct node *treePointer;
typedef struct node {
    char data;
    treePointer leftChild;
    treePointer rightChild;
}node;

treePointer root;
treePointer stack[MAX_STACK_SIZE];
int top=-1;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_stack(void)
{
    top=-1;
}

int is_stack_empty(void)
{
    return top==-1;
}

int is_stack_full(void)
{
    return top==MAX_STACK_SIZE-1;
}

void push(treePointer pNode)
{
    if(is_stack_full())
    {
        error("스택이 꽉차있습니다.");
    }
    else
    {
        stack[++top]=pNode;
    }
}

treePointer pop(void)
{
    if(is_stack_empty())
    {
        error("스택이 비어있습니다.");
    }
    
    return stack[top--];
}

treePointer create_node(char data,treePointer left,treePointer right)
{
    treePointer new_node=(treePointer)malloc(sizeof(node));
    new_node->data=data;
    new_node->leftChild=left;
    new_node->rightChild=right;
    
    return new_node;
}

treePointer createBinTree(void)
{
    init_stack();
    
    char data;
    
    FILE *fa;
    fa=fopen("input.txt", "r");
    
    treePointer op1,op2;
    
    while(fscanf(fa, "%c",&data)!=EOF)
    {
        printf("%c",data);
        if(data=='+' || data=='-' || data=='*' || data=='/' || data=='%')
        {
            op2=pop();
            op1=pop();
            
            push(create_node(data, op1, op2));
        }
        else
        {
            push(create_node(data,NULL,NULL));
        }
    }
    
    return pop();
    
}

void inorder_r(treePointer root)
{
    if(root)
    {
        inorder_r(root->leftChild);
        printf("%c",root->data);
        inorder_r(root->rightChild);
        
    }
}

void preorder_r(treePointer root)
{
    if(root)
    {
        printf("%c",root->data);
        preorder_r(root->leftChild);
        preorder_r(root->rightChild);
    }
}

void postorder_r(treePointer root)
{
    if(root)
    {
        postorder_r(root->leftChild);
        postorder_r(root->rightChild);
        printf("%c",root->data);
    }
}
int main()
{
    printf("the length of input string should be less than 80\n");
    printf("input string <postfix expression> : ");
    root=createBinTree();
    
    printf("\ncreating its binary tree\n\n");
    
    printf("inorder traversal   : ");
    inorder_r(root);
    printf("\n");
    
    printf("preorder traversal  : ");
    preorder_r(root);
    printf("\n");
    
    printf("postorder traversal : ");
    postorder_r(root);
    printf("\n");
    
    return 0;
}
