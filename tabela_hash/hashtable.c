#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hashtable.h"

#define SIZE 23

// array de pessoas
PESSOA* array[SIZE];

// gera uma hash universal a partir do somatorio de caracteres da string
int hash(char* key){

    srand(time(NULL));

    int p = 65543; 

    int temp1 = p;

    int temp2 = p;

    int a = rand() % (temp1-1) + 1;

    int b = rand() %  (temp2-1);
    
    int len = strnlen(key, 256);

    int value = 0;

    for(int i = 0; i < len; i++){

        value += key[i];

    }

    int hash_value = ((a*value + b)%p) % SIZE;

    return hash_value;

}

// inseres as pessoas, nome e idade
// a lista recebe uma pessoa no indice do array em que a chave foi gerada
int insere(int idade, char* key){

    PESSOA* items = (PESSOA*)malloc(sizeof(PESSOA));

    if(items == NULL){

        printf("ERRO");

        return 0; 
    }

    int index = hash(key);

    items -> idade = idade;

    strcpy(items->key, key);

    items -> next = array[index];

    array[index] = items;

}

// imprime todos os elementos da lista
void print_list(){
    
    for(int i = 0; i < SIZE;i++){

        PESSOA* aux = array[i];    

        if(aux == NULL){

            printf(" ~~~ ");

        }else{

            while(aux != NULL){

                printf("[ %i, %s ]", aux->idade, aux->key);

                aux = aux->next;

            }
       
        }

    }

    printf("\n");
 
}
// procura por um elemento na lista, usando a chave
int search(char * key){

    int index = hash(key);

    PESSOA* list = array[index];

    while(list != NULL){

            if(strcmp(list->key, key) == 0){
                
                return 1;
            }

        list = list->next;
        
    }


}
