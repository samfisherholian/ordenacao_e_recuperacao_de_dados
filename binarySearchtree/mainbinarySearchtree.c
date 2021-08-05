#include <stdio.h>
#include <stdlib.h>
#include "binarySearchtree.h"

int main(){

    NODE* root = NULL;

    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 22);
    root = insert(root, 28);
    root = insert(root, 15);
    root = insert(root, 18);
    root = insert(root, 10);

    printTree_in_pre_order(root);
    printf("\n");

    printf("o numero %i esta na arvore? %s\n",18, search(root, 18)? "true":"false");

    printf("removendo o valor 15 da arvore\n");

    remover(root, 15);
    
    printTree_in_pre_order(root);
    printf("\n");

    root = freeTree(root);

    printf("a arvore esta vazia? %s\n",isfree(root)? "true":"false");

    printTree_in_pre_order(root);

    return 0;
    
}
