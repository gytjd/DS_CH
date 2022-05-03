//
//  1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/05/03.
//

#include "1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackNode {
    char data;
    struct stackNode *link;
}stackNode;

typedef struct stackType {
    stackNode *top;
}stackType;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_stack(stackType *s)
{
    s->top=NULL;
}

int is_stakc_empty(stackType *s)
{
    return s->top==NULL;
}

void push(stackType *s,char data)
{
    stackNode *new_node=(stackNode *)malloc(sizeof(stackNode));
    new_node->data=data;
    new_node->link=NULL;
    
    if(is_stakc_empty(s))
    {
        s->top=new_node;
    }
    else
    {
        new_node->link=s->top;
        s->top=new_node;
    }
}

char pop(stackType *s)
{
    stackNode *removed=s->top;
    char data=removed->data;
    
    s->top=removed->link;
    free(removed);
    
    return data;
}

char peek(stackType *s)
{
    return s->top->data;
}

int prec(char data)
{
    switch(data)
    {
        case '|':
            return 0;
        case '&':
            return 1;
        case '~':
            return 2;
    }
    return -1;
}

void eval(void)
{
    FILE *fa;
    fa=fopen("input.txt", "r");
    
    stackType s;
    init_stack(&s);
    
    char open_ch;
    char data;
    
    printf("postfix expressoin     : ");
    
    while(fscanf(fa, "%c",&data)!=EOF)
    {
        if(data=='&'||data=='|'||data=='~')
        {
            while(!is_stakc_empty(&s)&&prec(data)<=prec(peek(&s)))
            {
                printf("%c",pop(&s));
            }
            push(&s, data);
        }
        else if(data=='(')
        {
            push(&s, data);
        }
        else if(data==')')
        {
            open_ch=pop(&s);
            
            while(open_ch!='(')
            {
                printf("%c",open_ch);
                open_ch=pop(&s);
            }
        }
        else
        {
            printf("%c",data);
        }
    }
    
    while(!is_stakc_empty(&s))
    {
        printf("%c",pop(&s));
    }
    printf("\n");
}
int main()
{
    printf("<<<<<<<<<<<<infix to postfix>>>>>>>>>>>>\n");
    eval();
    
    return 0;
}



