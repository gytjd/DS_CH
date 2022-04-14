//
//  1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/14.
//

#include "1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct StackNode {
    int data;
    struct StackNode *link;
}StackNode;

typedef struct StackType {
    StackNode *top;
}StackType;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_stack(StackType *s)
{
    s->top=NULL;
}

int is_stack_empty(StackType *s)
{
    return s->top==NULL;
}

void push(StackType *s,int data)
{
    StackNode *new_node=(StackNode *)malloc(sizeof(StackNode));
    new_node->data=data;
    new_node->link=s->top;
    s->top=new_node;
}

int pop(StackType *s)
{
    StackNode *removed=s->top;
    int data=removed->data;
    
    s->top=removed->link;
    
    free(removed);
    
    return data;
}

int peek(StackType *s)
{
    return s->top->data;
}

int calculate_postfix(char *pa)
{
    StackType s;
    init_stack(&s);
    
    int n=strlen(pa);
    int i,value;
    int op1,op2;
    char ch;
    
    for(i=0;i<n;i++)
    {
        ch=pa[i];
        
        if(ch=='+'|| ch=='-'||ch=='/'||ch=='%'||ch=='*')
        {
            op2=pop(&s);
            op1=pop(&s);
            
            switch(ch)
            {
                case '+':
                    push(&s, op1+op2);
                    break;
                case '-':
                    push(&s, op1-op2);
                    break;

                case '*':
                    push(&s, op1*op2);
                    break;

                case '/':
                    push(&s, op1/op2);
                    break;

                case '%':
                    push(&s, op1%op2);
                    break;
            }
        }
        else
        {
            value=ch-'0';
            push(&s, value);
        }
    }
    
    return pop(&s);
}
int main()
{
    FILE *fa;
    fa=fopen("input.txt", "r");
    
    char line[MAX_SIZE];
    fgets(line, MAX_SIZE, fa);
    
    printf("%d\n",calculate_postfix(line));
    
    return 0;
}
