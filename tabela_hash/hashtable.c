#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 21

typedef struct pessoa PESSOA;

struct pessoa{
    
    char key[256];

    int idade;

    struct pessoa* next;

};


PESSOA* array[SIZE];

int hash(char* key){
    
    int len = strnlen(key, 256);

    int value = 0;

    for(int i = 0; i < len; i++){

        value += key[i];

        value = (value * key[i] % SIZE);

    }

    return value;

}


void insere(int idade, char* key, PESSOA* head){

    PESSOA* items = (PESSOA*)malloc(sizeof(PESSOA));

    int index = hash(key);

    items -> idade = idade;

    strcpy(items->key, key);

    items -> next = array[index];

    array[index] = items;

}

void print_list(){

    for(int i = 0; i< SIZE;i++){
        
        if(array[i] != NULL){

            printf("[ %i, %s ]", array[i]->idade, array[i]->key);

        }else{

            printf(" ~~~ ");
        }

    }

    printf("\n");
 
}


int main(){

    PESSOA* individuos;

    insere(23, "tiago", individuos);

    insere(20, "emerson", individuos);

    insere(21, "lucas", individuos);

    insere(25, "dario", individuos);

    insere(24, "andre", individuos);

    insere(21, "samuel", individuos);

    print_list();




    return 0;
}