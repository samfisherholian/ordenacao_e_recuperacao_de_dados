#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 21

typedef struct pessoa PESSOA;

struct pessoa{
    
    char key[256];

    int idade;

    struct pessoa* next;

};


PESSOA* array[SIZE];

int hash(char* key){

    //srand(time(NULL));

    //int radom1 = rand() % 101;

    //int radom2 = rand() % 101;
    
    int len = strnlen(key, 256);

    int value = 0;

    for(int i = 0; i < len; i++){

        value += key[i];
        
        value = (value * key[i] % SIZE);

        //int hash_value = ((radom1*value + radom2)%101) % SIZE;

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

int search(char * key){

    int index = hash(key);

    while(array[index] != NULL){

        if(strcmp(array[index]->key, key) == 0){
            
            return 1;
        }

        array[index] = array[index]->next;

    }


}


int main(){

    PESSOA* individuos;

    insere(50, "tiago", individuos);

    insere(38, "emerson", individuos);

    insere(21, "lucas", individuos);

    insere(42, "dario", individuos);

    insere(49, "andre", individuos);

    insere(31, "samuel", individuos);

    print_list();


   search("tiago")? printf("%s", "True\n"):printf("%s\n", "False");



    return 0;
}