#ifndef _BINARYSEARCHTREE_
#define _binarysearchtree_

typedef struct node NODE;

struct node{

    int data;

    struct node* left;

    struct node* right;

};

NODE* nodeCreate(int data);
NODE* insert(NODE* root, int data);
int search(NODE* root, int data);
NODE* freeTree(NODE* root);
void printTree_in_pre_order(NODE* root);
NODE* remover(NODE* root, int data);
NODE* min_value(NODE* root);
int isfree(NODE* root);


#endif