#ifndef _TREE_
#define _tree_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node NODE;

NODE* cria_arvore(int data);
NODE* inserir_na_arvore(NODE* root, int data);
int search(NODE* root, int data);
void imprime_arvore_preOrdem(NODE* root);
NODE* min_value(NODE* root);
NODE* delete(NODE* root, int data);
NODE* rightRotate(NODE* A);
NODE* leftRotate(NODE* A);
int max(int num1, int num2);
int heightTree(NODE* root);
int getBalance(NODE* tree);
NODE* freeTree(NODE* root);
int isfree(NODE* root);

#endif