#include <stdio.h>
#include <stdlib.h>
#include "binarySearchtree.h"

NODE* nodeCreate(int data){

    NODE* tree = (NODE*) malloc(sizeof(NODE));

    if(tree != NULL){
    
        tree->data = data;

        tree->left = NULL;

        tree->right = NULL;

        return tree;

    }
}

NODE* insert(NODE* root, int data){

    if(root == NULL){

        // se a árvore não tiver nada vai inserir um dado na raiz.    
        root = nodeCreate(data);
    // caso não for vazia e o dado inserido seja menor que o dado que esta na arvore insere a esqierda
    }else if(root->data == data){

        printf("ERR this number already exist\n");

        return root;

    }else if(data <= root->data){

        root->left = insert(root->left,data);

    }else {

        root->right = insert(root->right, data);

    }

        return root;

}

int search(NODE* root, int data){

    if(root != NULL){
    
        if(root->data ==  data){

            return 1;

        }else if(data <= root->data){

            return search(root->left, data);

        }else{

            return search(root->right, data);

        }   
    }

        return 0;     

}

NODE* freeTree(NODE* root){

    if(root != NULL){
        
        freeTree(root->right);
        freeTree(root->left);
        free(root);

        root = NULL;

        return root;

    }

}

int isfree(NODE* root){

    if(root == NULL){

        return 1;

    }

    return 0;

}

NODE* min_value(NODE* root){

    while(root->left != NULL){

        root = root->left;

    }

    return root;

}

NODE* remover(NODE* root, int data){

    if(root != NULL){

        if(data < root -> data){

            root ->left = remover(root->left, data);

        }else if(data > root->data){

            root ->right = remover(root->right, data);
        
        // caso for um nó folha que não possui filhos
        }else if(root->left == NULL && root->right == NULL){

            free(root);

            return NULL;
        //caso o nó esquerdo possua apenas um filho
        }else if(root->left == NULL){
            
            NODE* temp = root;

            root = root->right;

            free(temp);

        // caso o nó direito possua apenas um filho
        }else if(root->right == NULL){

            NODE* temp2 = root;

            root = root->left;

            free(temp2);
        
        // caso tenha 2 filhos
        }else{

            NODE* temp3 = min_value(root->right);

            root->data = temp3->data;

            root->right = remover(root->right, temp3->data);

        }

        return root;

    }

}

void printTree_in_pre_order(NODE* root){

    printf("<");
    if(root != NULL){

        printf("%i",root->data);

        printTree_in_pre_order(root->left);
        
        printTree_in_pre_order(root->right);

    }
    printf(">");

}
