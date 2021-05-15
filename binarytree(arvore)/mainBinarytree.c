#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

int main(){

    NODE* root =  NULL;

    root = nodeCreate(10);
    insert(root, 12);
    insert(root, 20);
    insert(root, 15);
    insert(root, 5);
    insert(root, 40);
    insert(root, 30);
    insert(root, 50);
    insert(root, 55);
    insert(root, 60);

    printTree_in_pre_order(root);
    printf("\n");

    printf("o numero %i esta na arvore? %s \n",55, search(root,55)?"true":"false");

    printf("o numero %i esta na arvore? %s \n",13, search(root,13)?"true":"false");

    printf("a arvore esta vazia? %s\n",(root == NULL)? "true":"false");

    printTree_in_pre_order(root);

    printf("\n");

    root = freeTree(root);

    printf("a arvore esta vazia? %s\n",(root == NULL)? "true":"false");

    printTree_in_pre_order(root);

    printf("\n");

    return 0;
    
}