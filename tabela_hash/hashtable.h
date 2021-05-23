#ifndef _HASHTABLE_
#define _hashtable

typedef struct pessoa PESSOA;

// a idade e o nome da pessoa
// o nome da pessoa é chave
struct pessoa{
    
    char key[256];

    int idade;

    struct pessoa* next;

};

int hash(char* key);
int insere(int idade, char* key);
void print_list();
int search(char * key);

#endif