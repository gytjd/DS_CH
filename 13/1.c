//
//  1.c
//  KNU C
//
//  Created by hwang hyosung on 2022/04/26.
//

#include "1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node *treePointer;
typedef struct node {
    char data;
    treePointer leftChild;
    treePointer rightChild;
}node;

treePointer root=NULL;

treePointer createNode(char data)
{
    treePointer new_node=(treePointer)malloc(sizeof(node));
    new_node->data=data;
    new_node->leftChild=NULL;
    new_node->rightChild=NULL;
    
    return new_node;
}

treePointer createBintree(treePointer root,char data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    
    if(root->leftChild==NULL)
    {
        root->leftChild=createBintree(root->leftChild, data);
    }
    else if(root->rightChild==NULL)
    {
        root->rightChild=createBintree(root->rightChild, data);
    }
    else
    {
        if(root->leftChild->leftChild==NULL || root->leftChild->rightChild==NULL)
        {
            root->leftChild=createBintree(root->leftChild, data);
        }
        else if(root->leftChild->leftChild!=NULL && root->leftChild->rightChild!=NULL && root->rightChild->leftChild!=NULL && root->rightChild->rightChild!=NULL)
        {
            root->leftChild=createBintree(root->leftChild, data);
        }
        else
        {
            root->rightChild=createBintree(root->rightChild, data);
        }
    }
    
    return root;
}

void inorder(treePointer root)
{
    if(root)
    {
        inorder(root->leftChild);
        printf("%c ",root->data);
        inorder(root->rightChild);
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
    int i;
    for(i=0;i<7;i++)
    {
        root=createBintree(root, 'A'+i);
    }
    
    printf("creating a binary tree\n");
    
    printf("\nthree binary tree traversals\n");
    printf("inorder traversal   : ");
    inorder(root);
    printf("\n");
    
    printf("preorder traversal  : ");
    preorder_my(root);
    printf("\n");
    
    printf("postorder traversal : ");
    postorder_my(root);
    printf("\n");
    return 0;
}
