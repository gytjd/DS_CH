//
//  4.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/08.
//

#include "4.h"
#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef struct {
    char name[20];
    int age;
    int salary;
}humanBeing;

int humansEqual(humanBeing *person1,humanBeing *person2)
{
    if(strcmp(person1->name, person2->name))
    {
        return FALSE;
    }
    if(person1->age!=person2->age)
    {
        return FALSE;
    }
    if(person1->salary!=person2->salary)
    {
        return FALSE;
    }
    
    return TRUE;
}

int main()
{
    humanBeing A,B;
    
    printf("Input person1's name,age,salary : \n");
    gets(A.name);
    scanf("%d",&A.age);
    scanf("%d",&A.salary);
    
    getchar();
    printf("Input person2's name,age,salary : \n");
    gets(B.name);
    scanf("%d",&B.age);
    scanf("%d",&B.salary);
    
    
    if(humansEqual(&A, &B)==TRUE)
    {
        printf("The two human beings are the same\n");
    }
    else
    {
        printf("The two human beings are not the same\n");
    }
    
}
