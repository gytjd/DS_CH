//
//  1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "1.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREMS 100

typedef struct {
    float coef;
    int exp;
}term;

term terms[MAX_TREMS];

int avail=0;


void inputPoly(int *startA,int *finishA,int *startB,int *finishB)
{
    FILE *fa;
    fa=fopen("input.txt","r");
    
    int i;
    int EndA,EndB;
    fscanf(fa, "%d %d",&EndA,&EndB);
    
    *startA=0;
    for(i=0;i<EndA;i++)
    {
        fscanf(fa, "%f %d",&terms[i].coef,&terms[i].exp);
    }
    *finishA=EndA;
    *startB=EndA;
    for(i=EndA;i<EndA+EndB;i++)
    {
        fscanf(fa, "%f %d",&terms[i].coef,&terms[i].exp);
    }
    *finishB=EndA+EndB;
    avail=*finishB;
}

void printPoly(char name,int start,int end)
{
    int i;
    printf("%c(x) = ",name);
    
    for(i=start;i<end;i++)
    {
        if(i==end-1)
        {
            printf("%.1fx^%d ",terms[i].coef,terms[i].exp);
        }
        else
        {
            printf("%.1fx^%d + ",terms[i].coef,terms[i].exp);
        }
    }
    printf("\n");
}
void attach(float coefficient,int exponent)
{
    if(avail>=MAX_TREMS)
    {
        fprintf(stderr, "Too many terms in the polynomial\n");
        exit(EXIT_FAILURE);
    }
    
    terms[avail].coef=coefficient;
    terms[avail++].exp=exponent;
}

void padd(int startA,int finishA,int startB,int finishB,int *startD,int *finishD)
{
    float coefficient;
    *startD=avail;
    
    while(startA<=finishA && startB<=finishB)
    {
        if(terms[startA].exp<terms[startB].exp)
        {
            attach(terms[startB].coef,terms[startB].exp);
            startB++;
        }
        else if(terms[startA].exp>terms[startB].exp)
        {
            attach(terms[startA].coef,terms[startA].exp);
            startA++;
        }
        else
        {
            coefficient=terms[startA].coef+terms[startB].coef;
            if(coefficient)
                attach(coefficient, terms[startA].exp);
            
            startA++;
            startB++;
            
        }
    }
    
    for(;startA<finishA;startA++)
        attach(terms[startA].coef, terms[startA].exp);
    
    for(;startB<finishB;startB++)
        attach(terms[startB].coef, terms[startB].exp);
    
    *finishD=avail-1;
}


int main()
{
    int startA,finishA;
    int startB,finishB;
    int startD=0,finishD=0;
    
    inputPoly(&startA,&finishA,&startB,&finishB);
    printPoly('A',startA, finishA);
    printPoly('B',startB, finishB);
    
    padd(startA, finishA, startB, finishB, &startD, &finishD);
    printf("%d %d\n",startD,finishD);
    
    printPoly('C', startD, finishD);
    
    
    return 0;
}
