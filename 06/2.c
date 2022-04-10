//
//  2.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/11.
//

#include "2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 5
#define MAX_NAME_SIZE 20
#define MAX_LEN_SIZE 20

typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
}element;

element stack[MAX_STACK_SIZE];
int top=-1;

void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d %s\n",stack[i].id,stack[i].name);
    }
    printf("\n");
}
void stackFull()
{
    fprintf(stderr,"Stack is full, cannot add element\n");
    display();
    exit(EXIT_FAILURE);
}

void stackEmpty()
{
    fprintf(stderr,"Stack is empty, cannot delete element");
    display();
    exit(EXIT_FAILURE);
}

int is_stack_empty(void)
{
    return top==-1;
}

int is_stack_full(void)
{
    return top==MAX_STACK_SIZE-1;
}

void push(element data)
{
    if(is_stack_full())
    {
        stackFull();
    }
    stack[++top]=data;
}

element pop()
{
    if(is_stack_empty())
    {
        stackEmpty();
    }
    
    return stack[top--];
}

int main()
{
    char input[80];
    char *delimiter=" \n";
    char *op=NULL;
    element student;
    
    while(1)
    {
        gets(input);
        op=strtok(input, delimiter);
        
        if(!strcmp(op, "push"))
        {
            sscanf(input+strlen(op)+1, "%d%s",&student.id,&student.name);
            push(student);
        }
        else if(!strcmp(op, "pop"))
        {
            element item;
            item=pop();
            
            if(item.id==-1)
            {
                exit(EXIT_FAILURE);
            }
        }
        else if(!strcmp(op, "quit"))
            break;
        else
            
        {
            printf("Wrong command! try again!\n");
        }
    }
    
    return 0;
}

