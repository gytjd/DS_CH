//
//  1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/17.
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

polyPointer lastA,lastB;
polyPointer lastC;

polyPointer avail=NULL;

void insertFrontCL(polyPointer *head,polyPointer *last,polyPointer node)
{
    if((*head)->link==(*head))
    {
        (*head)->link=node;
        node->link=(*head);
        *last=node;
    }
    else
    {
        node->link=(*head)->link;
        (*head)->link=node;
    }
}
void insertLastCL(polyPointer *head,polyPointer *last,polyPointer node)
{
    if((*head)->link==(*head))
    {
        (*head)->link=node;
        node->link=(*head);
        *last=node;
    }
    else
    {
        node->link=(*last)->link;
        (*last)->link=node;
        (*last)=node;
    }
}

void printCList(polyPointer header)
{
    polyPointer p=header->link;
    
    do {
        if(p->coef>0)
        {
            printf("   +%dx^%d",p->coef,p->expon);
        }
        else
        {
            printf("   %dx^%d",p->coef,p->expon);
        }
        p=p->link;
    }while(p!=header);
    printf("\n");
}

void my_erase(polyPointer *ptr)
{
    
}

polyPointer getNode()
{
    polyPointer new_node=(polyPointer)malloc(sizeof(polyNode));
    new_node->expon=-1;
    new_node->link=new_node;
    
    return new_node;
}

void inputPolyCL(char *filename,polyPointer *header,polyPointer *last)
{
    FILE *fa;
    fa=fopen(filename, "r");
    
    char mode;
    int coef,expon;
    polyPointer new_node;
    
    
    fscanf(fa,"%c",&mode);
    *header=getNode();
    
    if(mode=='a')
    {
        while(fscanf(fa, "%d %d",&coef,&expon)!=EOF)
        {
            new_node=(polyPointer)malloc(sizeof(polyNode));
            new_node->coef=coef;
            new_node->expon=expon;
            new_node->link=NULL;
            insertFrontCL(header,last,new_node);
        }
    }
    else
    {
        while(fscanf(fa, "%d %d",&coef,&expon)!=EOF)
        {
            new_node=(polyPointer)malloc(sizeof(polyNode));
            new_node->coef=coef;
            new_node->expon=expon;
            new_node->link=NULL;
            insertLastCL(header,last,new_node);
        }
    }
}



void cerase(polyPointer *ptr)
{
    polyPointer temp;
    
    if(*ptr)
    {
        temp=(*ptr)->link;
        (*ptr)->link=avail;
        avail=temp;
        *ptr=NULL;
    }
}

void cpadd(polyPointer a,polyPointer b)
{
    c=getNode();
    
    polyPointer startA=a->link;
    polyPointer startB=b->link;
    
    
    polyPointer new_node;
    
    while(startA!=lastA->link && startB!=lastB->link)
    {
        new_node=(polyPointer)malloc(sizeof(polyNode));
        
        if(startA->expon>startB->expon)
        {
            new_node->coef=startA->coef;;
            new_node->expon=startA->expon;
            insertLastCL(&c, &lastC, new_node);
            startA=startA->link;
        }
        else if(startA->expon<startB->expon)
        {
            new_node->coef=startB->coef;
            new_node->expon=startB->expon;
            insertLastCL(&c, &lastC, new_node);
            startB=startB->link;
        }
        else
        {
            new_node->coef=startA->coef+startB->coef;
            new_node->expon=startA->expon;
            insertLastCL(&c, &lastC, new_node);
            startA=startA->link;
            startB=startB->link;
        }
    }
    
    if(startA!=lastA->link)
    {
        while(startA!=lastA->link)
        {
            new_node=(polyPointer)malloc(sizeof(polyNode));
            new_node->coef=startA->coef;;
            new_node->expon=startA->expon;
            insertLastCL(&c, &lastC, new_node);
            startA=startA->link;
        }
    }
    if(startB!=startB->link)
    {
        while(startB!=lastB->link)
        {
            new_node=(polyPointer)malloc(sizeof(polyNode));
            new_node->coef=startB->coef;;
            new_node->expon=startB->expon;
            insertLastCL(&c, &lastC, new_node);
            startB=startB->link;
        }
    }
}
 

int main()
{
    inputPolyCL("input.txt", &a, &lastA);
    printf("     a: ");
    printCList(a);
    
    inputPolyCL("output.txt", &b, &lastB);
    printf("     b: ");
    printCList(b);
    
    cpadd(a, b);
    printf("   a+b: ");
    printCList(c);
    
    return 0;
}

