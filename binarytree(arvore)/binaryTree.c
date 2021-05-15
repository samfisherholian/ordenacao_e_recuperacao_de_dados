#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

NODE* nodeCreate(int data){

    NODE* tree = (NODE*) malloc(sizeof(NODE));

    if(tree != NULL)
    {
        tree->data =  data;
    
        tree->right = NULL;
    
        tree->left = NULL;

        return tree;

    }
    
}

NODE* insert(NODE* root, int data){

    if (root ==  NULL){

        root = nodeCreate(data);

    }else if(root->left == NULL){

         root->left = insert(root->left,data);

    }else {

         root->right = insert(root->right,data);
    }
   

    return root;

}

int search(NODE* root, int data){
    
    if(root != NULL){

        if(root->data == data){

            return 1;

        }
        if(search(root->right,data) == 1){

            return 1;

        }

        return search(root->left,data);
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

NODE* freeTree(NODE* root){

    if(root != NULL){

        freeTree(root->left);

        freeTree(root->right);

        free(root);

        root = NULL;

        return root;
    }
    
}
