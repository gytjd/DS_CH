//
//  2.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/26.
//

#include "2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node* treePointer;
typedef struct node {
    char data;
    treePointer leftChild;
    treePointer rightChild;
}node;

treePointer root=NULL;
treePointer queue[MAX_SIZE];
int front;
int rear;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_queue(void)
{
    front=-1;
    rear=-1;
}

treePointer is_queue_empty(void)
{
    if(front==rear)
    {
        return NULL;
    }
    return NULL;
}

int is_queue_full(void)
{
    return rear==MAX_SIZE-1;
}

void enqueue(treePointer data)
{
    if(is_queue_full())
    {
        error("큐가 가득차있습니다.");
    }
    else
    {
        queue[++rear]=data;
    }
}

treePointer dequeue(void)
{
    if(is_queue_empty())
    {
        error("큐가 비어있습니다.");
    }
    
    return queue[++front];
}

treePointer get_front(void)
{
    int temp=front+1;
    return queue[temp];
}

treePointer createNode(char data)
{
    treePointer new_node=(treePointer)malloc(sizeof(node));
    new_node->data=data;
    new_node->leftChild=NULL;
    new_node->rightChild=NULL;
    
    return new_node;
}

void insert(treePointer *pRoot,treePointer pNode)
{
    treePointer temp;
    if((*pRoot)==NULL)
    {
        (*pRoot)=pNode;
    }
    else
    {
        temp=get_front();
        
        
        if(temp->leftChild==NULL)
        {
            temp->leftChild=pNode;
        }
        else if(temp->rightChild==NULL)
        {
            temp->rightChild=pNode;
            dequeue();
        }
    }
    enqueue(pNode);
    
}

treePointer createCompBinTree(FILE *fp)
{
    fp=fopen("input.txt", "r");
    char data;
    
    init_queue();
    
    while(fscanf(fp, "%c",&data)!=EOF)
    {
        insert(&root, createNode(data));
    }
    
    
    
    return root;
}

void inorder_my(treePointer root)
{
    if(root)
    {
        inorder_my(root->leftChild);
        printf("%c ",root->data);
        inorder_my(root->rightChild);
    }
}

void preorder_my(treePointer root)
{
    if(root)
    {
        printf("%c ",root->data);
        preorder_my(root->leftChild);
        preorder_my(root->rightChild);
    }
}

void postorder_my(treePointer root)
{
    if(root)
    {
        postorder_my(root->leftChild);
        postorder_my(root->rightChild);
        printf("%c ",root->data);
    }
}
int main()
{
    FILE *fp;
    root=createCompBinTree(fp);
    
    printf("creating a complete binary tree\n");
    
    printf("\nthree binary tree traversals\n");
    printf("inorder traversal   : ");
    inorder_my(root);
    printf("\n");
    printf("preorder traversal  : ");
    preorder_my(root);
    printf("\n");
    printf("postorder traversal : ");
    postorder_my(root);
    printf("\n");
    
    return 0;
}

