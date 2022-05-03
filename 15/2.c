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


