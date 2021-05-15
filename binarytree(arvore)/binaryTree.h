#ifndef _BINARYTREE_
#define _binarytree_

typedef struct node NODE;

struct node {

    int data;

    struct node* right;

    struct node* left;
};


NODE* nodeCreate(int data);
NODE* insert(NODE* root, int data);
void printTree_in_pre_order(NODE* root);
NODE* freeTree(NODE* root);
int search(NODE* root, int data);

#endif