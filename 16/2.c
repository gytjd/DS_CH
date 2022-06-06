#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
}treeNode;

treeNode *root=NULL;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

treeNode *create_node(int data)
{
    treeNode *new_node=(treeNode *)malloc(sizeof(treeNode));
    new_node->data=data;
    new_node->leftChild=NULL;
    new_node->rightChild=NULL;
    
    return new_node;
}

treeNode *insert_node(treeNode *root,int data)
{
    if(root==NULL)
    {
        return create_node(data);
    }
    
    if(root->data>data)
    {
        root->leftChild=insert_node(root->leftChild,data);
    }
    else if(root->data<data)
    {
        root->rightChild=insert_node(root->rightChild,data);
    }
    else
    {
        error("same key");
    }
    
    return root;
}

void inorder_my(treeNode *root)
{
    if(root)
    {
        inorder_my(root->leftChild);
        printf("%d ",root->data);
        inorder_my(root->rightChild);
    }
}
int main()
{
    int i;
    int n,seed;
    printf("the number of nodes in BST >> ");
    scanf("%d",&n);
    printf("seed >> ");
    scanf("%d",&seed);
    
    srand(seed);
    
    for(i=0;i<n;i++)
    {
        root=insert_node(root,rand()%500+1);
    }
    
    inorder_my(root);
    
}
