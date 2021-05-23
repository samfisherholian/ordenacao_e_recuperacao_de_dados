#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hashtable.h"

int main(){

    // pessoas inseridas

    insere(50, "joao");

    insere(38, "maria");

    insere(21, "jose");

    insere(42, "carlos");

    insere(49, "adriano");

    insere(31, "albuquerque");

    insere(70, "silvana");

    insere(80,"roberto");

    print_list();

    // busca pelas pessoas a partir da chave
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