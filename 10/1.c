//
//  1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/15.
//

#include "1.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;
typedef struct listNode {
    int data;
    listPointer link;
}listNode;

listPointer first=NULL;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

int is_list_empty(listPointer head)
{
    return head==NULL;
}

void insert(listPointer *head,listPointer *x,int data)
{
    listPointer new_node=(listPointer)malloc(sizeof(listNode));
    new_node->data=data;
    new_node->link=NULL;
    
    if(*head==NULL)
    {
        *head=new_node;
    }
    else if(*x==NULL)
    {
        new_node->link=(*head);
        *head=new_node;
    }
    else
    {
        new_node->link=(*x)->link;
        (*x)->link=new_node;
    }
}



void find(listPointer *head,listPointer *x,int data)
{
    listPointer p=(*head);
    listPointer pre=NULL;
    
    if(*head==NULL)
    {
        *x=NULL;
    }
    else
    {
        if(p->data>data)
        {
            *x=NULL;
        }
        else
        {
            while(p!=NULL)
            {
                if(p->data<data)
                {
                    pre=p;
                    p=p->link;
                }
                else
                {
                    break;
                }
                *x=pre;
            }
        }
    }
}

void display(listPointer head)
{
    listPointer p=head;
    int i=0;
    
    while(p!=NULL)
    {
        if(i%10==0)
        {
            printf("\n");
        }
        printf("%d ",p->data);
        p=p->link;
        i++;
    }
}


void delete_less50(listPointer *head)
{
    listPointer p=*head;
    listPointer pre=NULL;
    listPointer removed;
    
    while(p!=NULL)
    {
        if(p->data<=50)
        {
            removed=p;
            p=p->link;
            (*head)=p;
            
            free(removed);
        }
        else
        {
            pre=p;
            p=p->link;
        }
    }
}
int main()
{
    int data;
    listPointer x,trail;
    
    FILE *fa;
    fa=fopen("input.txt", "r");
    
    while(fscanf(fa, "%d",&data)!=EOF)
    {
        find(&first,&x,data);
        insert(&first,&x,data);
    }
    printf("The ordered list contains: \n");
    display(first);
    printf("\n\n");
    
    printf("After deleting nodes with data less than and equal to 50\n");
    delete_less50(&first);
    printf("The ordered list contains: \n");
    display(first);
    printf("\n\n");
    
    return 0;
        
}


