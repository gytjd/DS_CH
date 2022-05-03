//
//  2.c
//  KNU C
//
//  Created by hwang hyosung on 2022/05/03.
//

#include "2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef enum { NOT,AND,OR,true,false } logical;

typedef struct node* treePointer;
typedef struct node {
    treePointer leftChild;
    char var;
    logical data;
    short int value;
    treePointer rightChild;
}tNode;

typedef struct stackNode {
    treePointer data;
    struct stackNode *link;
}stackNode;

typedef struct stackType {
    stackNode *top;
}stackType;

treePointer root=NULL;
logical aData,bData,cData;

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

treePointer create_node(char var,logical data,int value,treePointer left,treePointer right)
{
    treePointer new_node=(treePointer)malloc(sizeof(tNode));
    
    new_node->var=var;
    new_node->data=data;
    new_node->value=value;
    new_node->leftChild=left;
    new_node->rightChild=right;
    
    return new_node;
}

void push(stackType *s,treePointer data)
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

treePointer pop(stackType *s)
{
    stackNode *removed=s->top;
    treePointer data=removed->data;
    
    s->top=removed->link;
    free(removed);
    
    return data;
}

void inorder_my(treePointer root)
{
    if(root)
    {
        inorder_my(root->leftChild);
        printf("%c",root->var);
        inorder_my(root->rightChild);
    }
}

void postOrderEval(treePointer node,int i,int j,int k)
{
    if(node)
    {
        postOrderEval(node->leftChild, i, j, k);
        postOrderEval(node->rightChild, i, j, k);
        
        switch (node->var) {
            case '~':
                node->value=!node->rightChild->value;
                break;
            case '&':
                node->value=node->rightChild->value && node->leftChild->value;
                break;
            case '|':
                node->value=node->rightChild->value || node->leftChild->value;
                break;
            default:
                
                if(node->var=='a')
                {
                    node->value=i;
                }
                else if(node->var=='b')
                {
                    node->value=j;
                }
                else
                {
                    node->value=k;
                }
                break;
        }
    }
}

int main()
{
    FILE *fa;
    fa=fopen("input.txt", "r");
    
    char data;
    stackType s;
    init_stack(&s);
    
    treePointer op1,op2;
    
    int i,j,k;
    char q,w,e;
    
    
    
    printf("************satisfiability problem*************\n");
    printf("Not: For efficiency,&, |, ~ are used instead of\n");
    printf("logical and(&&),logical or(||), logical not(!)\n");
    printf("************************************************\n");
    printf("input string(postfix)    : ");
    
    
    while(fscanf(fa, "%c",&data)!=EOF)
    {
        printf("%c",data);
        if(data=='&')
        {
            op2=pop(&s);
            op1=pop(&s);
            
            push(&s, create_node(data, AND, 0, op1, op2));
        }
        else if(data=='|')
        {
            op2=pop(&s);
            op1=pop(&s);
            
            push(&s, create_node(data, OR, 0, op1, op2));
        }
        else if(data=='~')
        {
            op1=pop(&s);
            
            push(&s, create_node(data, NOT, 0, NULL, op1));
        }
        else
        {
            push(&s, create_node(data, true, 1, NULL, NULL));
        }
    }
    
    root=pop(&s);
    
    printf("\ncreating binary tree for satisfiability algorithm...\n");
    
    printf("\n\ninorder traversal     : ");
    inorder_my(root);
    
    printf("\n\nfor all combinations of (a, b, c)...\n");
    
    for(i=1;i>=0;i--)
    {
        for(j=1;j>=0;j--)
        {
            for(k=1;k>=0;k--)
            {
                postOrderEval(root, i, j, k);
                
                if(i==1)
                {
                    q='t';
                }
                else
                {
                    q='f';
                }
                
                if(j==1)
                {
                    w='t';
                }
                else
                {
                    w='f';
                }
                
                if(k==1)
                {
                    e='t';
                }
                else
                {
                    e='f';
                }
                
                if(root->value)
                {
                    printf("(%c, %c, %c) is TRUE\n",q,w,e);
                }
                else
                {
                    printf("(%c, %c, %c) is FALSE\n",q,w,e);
                }
                
                
            }
        }
    }
    
    return 0;
    
}
