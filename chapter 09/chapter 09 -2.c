//
//  chapter 09 -2.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/14.
//

#include "chapter 09 -2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 80

typedef struct StackNode {
    char data;
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

void push(StackType *s,char data)
{
    StackNode *new_node=(StackNode *)malloc(sizeof(StackNode));
    new_node->data=data;
    new_node->link=s->top;
    s->top=new_node;
}

char pop(StackType *s)
{
    StackNode *removed=s->top;
    char data=removed->data;
    
    s->top=removed->link;
    
    free(removed);
    
    return data;
}

char peek(StackType *s)
{
    return s->top->data;
}

void display(StackType *s)
{
    StackNode *p=s->top;
    while(p!=NULL)
    {
        printf("%3c",p->data);
        p=p->link;
    }
    printf("\n");
}
int prec(char a)
{
    switch(a)
    {
        case '(': case ')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/': case '%':
            return 2;
    }
    return -1;
}

void display_output(char *pa,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%c",pa[i]);
    }
    printf("\n");
}
void infix_to_postfix(char *pa)
{
    StackType s;
    init_stack(&s);
    int j=0;
    char output[MAX_SIZE];
    int i;
    int n=strlen(pa);
    char ch,open_ch;
    
    for(i=0;i<n;i++)
    {
        ch=pa[i];
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%')
        {
            if(!is_stack_empty(&s) && prec(ch)<=prec(peek(&s)))
            {
                output[j++]=pop(&s);
            }
            push(&s, ch);
        }
        else if(ch=='(')
        {
            push(&s, ch);
        }
        else if(ch==')')
        {
            open_ch=pop(&s);
            
            while(open_ch!='(')
            {
                output[j++]=open_ch;
                open_ch=pop(&s);
            }
        }
        else
        {
            output[j++]=ch;
        }
        
        printf("%c: ",ch);
        display(&s);
    }
    
    while(!is_stack_empty(&s))
    {
        output[j++]=pop(&s);
    }
    printf("\n");
    
}
int main()
{
    FILE *fa,*fb;
    fa=fopen("a.txt", "r");
    fb=fopen("b.txt","w");
    
    char line[MAX_SIZE];
    fgets(line, MAX_SIZE, fa);
    

    
    infix_to_postfix(line);
    
    return 0;
}

