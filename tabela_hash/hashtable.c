#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 23

typedef struct pessoa PESSOA;

struct pessoa{
    
    char key[256];

    int idade;

    struct pessoa* next;

};


PESSOA* array[SIZE];

int hash(char* key){

    srand(time(NULL));

    int p = 65543; 

    int temp1 = p;
    int temp2 = p;

    int a = rand() % (temp1-1) + 1;

    int b = rand() %  (temp2-1);
    

    //int radom2 = rand() % 101;
    
    int len = strnlen(key, 256);

    int value = 0;

    for(int i = 0; i < len; i++){

        value += key[i];
        
        //value = (value * key[i]% SIZE);

        //int hash_value = ((radom1*value + radom2)%101) % SIZE;

    }

    int hash_value = ((a*value + b)%p) % SIZE;

    //printf("a hash eh %i", value);

    return hash_value;

}


void insere(int idade, char* key){

    PESSOA* items = (PESSOA*)malloc(sizeof(PESSOA));

    int index = hash(key);

    items -> idade = idade;

    strcpy(items->key, key);

    items -> next = array[index];

    array[index] = items;

}

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


int main(){

/*
    printf("hash eh %i\n",hash("tiago"));

    printf("hash eh %i\n",hash("emerson"));

    printf("hash eh %i\n",hash("lucas"));

    printf("hash eh %i\n",hash("dario"));

    printf("hash eh %i\n",hash("andre"));

    printf("hash eh %i\n",hash("samuel"));

    printf("hash eh %i\n",hash("luiz"));

  */  
    //printf("hash eh %i\n",hash("jessicadossantos"));





    insere(50, "joao");

    insere(38, "maria");

    insere(21, "jose");

    insere(42, "carlos");

    insere(49, "adriano");

    insere(31, "albuquerque");

    insere(70, "silvana");

    insere(80,"roberto");

    print_list();


   search("joao")? printf("%s", "True\n"):printf("%s\n", "False");
   search("maria")? printf("%s", "True\n"):printf("%s\n", "False");
   search("jose")? printf("%s", "True\n"):printf("%s\n", "False");
   search("carlos")? printf("%s", "True\n"):printf("%s\n", "False");
   search("adriano")? printf("%s", "True\n"):printf("%s\n", "False"); 
   search("albuquerque")? printf("%s", "True\n"):printf("%s\n", "False");
   search("silvana")? printf("%s", "True\n"):printf("%s\n", "False"); 
   search("roberto")? printf("%s", "True\n"):printf("%s\n", "False");

   search("josney")? printf("%s", "True\n"):printf("%s\n", "False");
   search("eduardo")? printf("%s", "True\n"):printf("%s\n", "False");

    return 0;
}