#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10


//faz a troca das posicoes do array do menor para o maior
void changePosition(int value, int hole, int arr[]){

    while(hole > 0 && arr[hole - 1] > value){

        arr[hole] = arr[hole - 1];

        hole--;

    }

    arr[hole] = value;
    
}

//funcao que ordena o array
void insertionsort(int arr[], int size){

    for(int i = 1; i <= size-1;i++){

        int VALUE_IN_POSITION = arr[i];

        int HOLE = i;
/*
        while(HOLE > 0 && arr[HOLE - 1] > VALUE_IN_POSITION){

            arr[HOLE] = arr[HOLE - 1];

            HOLE--;

        }

        arr[HOLE] = VALUE_IN_POSITION;
*/

        changePosition(VALUE_IN_POSITION,HOLE, arr);

    }

}

//funcao que gera valores aleatorios para as posicoes do array
void randomArray(int arr[], int size){

    srand(time(NULL));

    for(int i = 0; i < size; i++){

        arr[i] = rand() % size;

    }

}

int main(){

    int arr[SIZE];


    randomArray(arr,SIZE);

    printf("unsorted\n");
    for(int i = 0;i< SIZE;i++){

        printf("%i,", arr[i]);
    }

    printf("\n");

    insertionsort(arr,SIZE);


    printf("now sorted\n");

    for(int i = 0;i< SIZE;i++){

        printf("%i,", arr[i]);
    }

    printf("\n");

    return 0;
}