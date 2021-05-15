#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Avltree.h"

int main(){

    NODE* root = NULL;

    root = inserir_na_arvore(root,10);
    root = inserir_na_arvore(root,15);
    root = inserir_na_arvore(root,20);
    root = inserir_na_arvore(root,25);
    root = inserir_na_arvore(root,30);
    root = inserir_na_arvore(root,35);
    root = inserir_na_arvore(root,40);

    printf("o numero %i esta na arvore? (%s)\n",25,search(root, 25)? "TRUE": "FALSE");

    printf("o numero %i esta na arvore? (%s)\n",14,search(root, 14)? "TRUE": "FALSE");

    printf("imprimindo em pre-ordem...\n");
    imprime_arvore_preOrdem(root);
    printf("\n");

    delete(root, 25);

    imprime_arvore_preOrdem(root);

    printf("\n");

    printf("a arvore esta vazia %s\n",isfree(root)? "true" : "false");

    imprime_arvore_preOrdem(root);

    printf("\n");

    root = freeTree(root);

    imprime_arvore_preOrdem(root);

    printf("\n");

    printf("a arvore esta vazia %s\n",isfree(root)? "true" : "false");

    return 0;

}