//
//  1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/16.
//

#include "1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct polyNode *polyPointer;
typedef struct polyNode {
    int coef;
    int expon;
    polyPointer link;
}polyNode;

polyPointer a=NULL;
polyPointer b=NULL;
polyPointer c=NULL;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void findLast(polyPointer first,polyPointer *last)
{
    polyPointer p=first;
    
    if(first==NULL)
    {
        *last=NULL;
    }
    else
    {
        while(p->link!=NULL)
        {
            p=p->link;
        }
        *last=p;
    }

}

void insert(polyPointer *first,polyPointer x,int coef,int expon)
{
    polyPointer new_node=(polyPointer)malloc(sizeof(polyNode));
    new_node->coef=coef;
    new_node->expon=expon;
    new_node->link=NULL;
    
    if(*first==NULL)
    {
        *first=new_node;
    }
    else if(x==NULL)
    {
        new_node->link=(*first);
        (*first)=new_node;
    }
    else
    {
        new_node->link=x->link;
        x->link=new_node;
    }
}

void insert_last(polyPointer *first,polyPointer x,int coef,int expon)
{
    polyPointer new_node=(polyPointer)malloc(sizeof(polyNode));
    new_node->coef=coef;
    new_node->expon=expon;
    new_node->link=NULL;
    
    if(x==NULL)
    {
        *first=new_node;
    }
    else
    {
        x->link=new_node;
    }
}

void inputPoly(char *filename,polyPointer *p)
{
    FILE *fa;
    fa=fopen(filename, "r");
    
    int coef,exp;
    char mode;
    fscanf(fa, "%c",&mode);
    
    polyPointer x=NULL;
    
    
    if(mode=='a')
    {
        while(fscanf(fa, "%d %d",&coef,&exp)!=EOF)
        {
            insert(p, NULL, coef, exp);
        }
    }
    else
    {
        while(fscanf(fa, "%d %d",&coef,&exp)!=EOF)
        {
            findLast(*p, &x);
            insert_last(p, x, coef, exp);
        }
    }
    
}

void printList(polyPointer first)
{
    polyPointer p=first;
    while(p!=NULL)
    {
        if(p->coef>0)
        {
            printf("  +%dx^%d ",p->coef,p->expon);
        }
        else
        {
            printf("  %dx^%d ",p->coef,p->expon);
        }
        p=p->link;
    }
    
    printf("\n");
    
}

polyPointer padd(polyPointer a,polyPointer b)
{
    polyPointer x=NULL;
    polyPointer c=NULL;
    
    polyPointer startA=a;
    polyPointer startB=b;
    
    while(startA!=NULL && startB!=NULL)
    {
        if(startA->expon>startB->expon)
        {
            
                findLast(c, &x);
                insert_last(&c, x, startA->coef, startA->expon);
                startA=startA->link;
        }
        else if(startA->expon<startB->expon)
        {
            findLast(c, &x);
            insert_last(&c, x, startB->coef, startB->expon);
            startB=startB->link;
        }
        else
        {
            findLast(c, &x);
            insert_last(&c, x, startA->coef+startB->coef, startA->expon);
            startA=startA->link;
            startB=startB->link;
        }
    }
    
    if(startA!=NULL)
    {
        while(startA!=NULL)
        {
            findLast(c, &x);
            insert_last(&c, x, startA->coef, startA->expon);
            startA=startA->link;
        }
    }
    if(startB!=NULL)
    {
        while(startB!=NULL)
        {
            findLast(c, &x);
            insert_last(&c, x, startB->coef, startB->expon);
            startB=startB->link;
        }
    }
    
    return c;
}

int main()
{
    inputPoly("input.txt", &a);
    printf("    a:");
    printList(a);
    inputPoly("output.txt", &b);
    printf("    b:");
    printList(b);
    printf("  a+b:");
    c=padd(a, b);
    printList(c);
    

    
    
    return 0;
}
