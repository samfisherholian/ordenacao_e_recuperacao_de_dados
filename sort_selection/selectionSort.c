#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10

void swap(int arr,int arr2){

    int temp = arr;

    arr = arr2;

    arr2 = temp;

}


void randomArray(int arr[], int n){

    for(int i = 0; i < n; i++){

        arr[i] = rand() % 10;

    }

}

void selectionSort(int arr[], int n){

    for(int i = 0; i < n-1;i++){
        //valor minimo como candidato
        int min = i;

        // seleciona o menor valor do array
        for(int j = i + 1;j < n;j++){

            if (arr[j] < arr[min]){

                min = j;

            }

        }
        
        int temp = arr[i];

        arr[i] = arr[min];

        arr[min] = temp;

    }


}


int main(){

    int arr[size];

    randomArray(arr, size);

    for (int j = 0;j < size;j++){

        printf("%i,",arr[j]);

    }

    printf("\n");
    

    selectionSort(arr,size);

    for (int i = 0;i < size;i++){

        printf("%i,",arr[i]);

    }

    printf("\n");

    return 0;
}