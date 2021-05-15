#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Avltree.h"

typedef struct node NODE;

struct node {

    int data;
    struct node* right;
    struct node* left;
    int height;

};

NODE* rightRotate(NODE* A);
NODE* leftRotate(NODE* A);


NODE* cria_arvore(int data){

    NODE* arvore = (NODE*)malloc(sizeof(NODE));

    if(arvore != NULL){  
        arvore->data = data;

        arvore->left = NULL;

        arvore->right = NULL;

        arvore->height = 1;

        return arvore;

    }
}

NODE* inserir_na_arvore(NODE* root, int data){

   
    if(root == NULL){

        // se a árvore não tiver nada vai inserir um dado na raiz.    
        root = cria_arvore(data);
    // caso não for vazia e o dado inserido seja menor que o dado que esta na arvore insere a esqierda
    }else if(root->data == data){

        printf("ERR this number already exist\n");

        return;

    }else if(data <= root->data){

        root->left = inserir_na_arvore(root->left,data);

    }else {

        root->right = inserir_na_arvore(root->right, data);

    }
    // atualiza a altura
    root->height = 1 + max(heightTree(root->left), heightTree(root->right));
    // pega o balance
    int balance = getBalance(root);

    // LL caso
    if(balance > 1 && data < root->left->data){

        return rightRotate(root);

    }   

    //RR caso
    if(balance < -1 && data > root->right->data){

        return leftRotate(root);
    }
    //LR caso
    if(balance > 1 && data > root->left->data){

        root->left = leftRotate(root->left);

        return rightRotate(root);
    }
    //RL caso
    if(balance < -1 && data < root->right->data){

        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

    return root;

}

int search(NODE* root, int data){

    if(root != NULL){
        // achou o nó
        if(root->data ==  data){

            return data;
        // caso nao ache procura na avore esquerda
        }else if(data <= root->data){

            return search(root->left, data);
        // caso nao ache na esquerda procura na direita
        }else{

            return search(root->right, data);

        }    

            return 0;

    }

}
// trata a raiz percorrre a esquerda depois a direita.
void imprime_arvore_preOrdem(NODE* root){

    printf("<");

    if(root != NULL){
        
        printf("%i",root->data);

        imprime_arvore_preOrdem(root->left);

        imprime_arvore_preOrdem(root->right);
    
    }   

    printf(">");

}

NODE* min_value(NODE* root){

    while(root->left != NULL){

        root = root->left;

    }

    return root;

}

NODE* delete(NODE* root, int data){

    if(root != NULL){

        if(data < root -> data){

            root ->left = delete(root->left, data);

        }else if(data > root->data){

            root ->right = delete(root->right, data);
        
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

            root->right = delete(root->right, temp3->data);

        }

        return root;

        root->height = 1 +max(heightTree(root->left), heightTree(root->right));

        int balance = getBalance(root);

        if(balance > 1 && getBalance(root->left) >= 0){

            return rightRotate(root);

        }

        if(balance > 1 && getBalance(root->left) < 0){

            root->left = leftRotate(root->left);

            return rightRotate(root);

        }

        if(balance < -1 && getBalance(root->right) <= 0){

            return leftRotate(root);

        }

        if(balance < -1 && getBalance(root->right) > 0){

            root->right = rightRotate(root->right);

            return leftRotate(root);

        }

        return root;
    }

}

NODE* rightRotate(NODE* A){

    NODE* P = NULL;

    NODE* B = NULL;

    P = A -> left;

    B = P -> right;

    P->right = A;

    A->left = B;

    A->height = max(heightTree(A->left), heightTree(A->right)) + 1;

    P->height = max(heightTree(P->left), heightTree(P->right)) + 1;

    return P;

}

NODE* leftRotate(NODE* B){

    NODE* P2 = NULL;

    NODE* A = NULL;

    P2 = B -> right;

    A = P2 -> left;

    P2->left = B;

    B->right = A;

    B->height = max(heightTree(B->left), heightTree(B->right)) + 1;

    P2->height = max(heightTree(P2->left), heightTree(P2->right)) + 1;

    return P2;

}

int max(int num1, int num2){

    if(num1 > num2){

        return num1;

    }else{

        return num2;

    }

}

int heightTree(NODE* root){

    if(root != NULL){
       return root->height;
    }

}

int getBalance(NODE* tree){

    if(tree != NULL){

        return heightTree(tree->left) - heightTree(tree->right);

    }

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

int isfree(NODE* root){

    if(root == NULL){
        return 1;
    }
    return 0;
}
