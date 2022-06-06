#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    char data;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
}treeNode;

treeNode *root=NULL;

treeNode *createNode(char data,treeNode *left,treeNode *right)
{
    treeNode *new_node=(treeNode *)malloc(sizeof(treeNode));
    new_node->data=data;
    new_node->leftChild=left;
    new_node->rightChild=right;
    
    return new_node;
}

void inorder_my(treeNode *root)
{
    if(root)
    {
        inorder_my(root->leftChild);
        printf("%c ",root->data);
        inorder_my(root->rightChild);
    }
}
int main()
{
    treeNode *D=createNode('D',NULL,NULL);
    treeNode *E=createNode('E',NULL,NULL);
    treeNode *B=createNode('B',D,E);
    treeNode *C=createNode('C',NULL,NULL);
    treeNode *A=createNode('A',B,C);
    
    root=A;
    
    inorder_my(root);
    
    return 0;
}
