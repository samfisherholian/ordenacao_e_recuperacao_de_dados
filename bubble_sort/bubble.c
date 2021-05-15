#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void bubbleSort(int arr[], int n){

    if(n < 1){

        return;

    }

    for(int i = 0;i< n;i++){

        if(arr[i] > arr[i+1]){

            int temp = arr[i];

            arr[i] = arr[i+1];

            temp = arr[i+1];

        }

        bubbleSort(arr, n-1);

    }

}


void randomArray(int arr[], int n){

    for(int i = 0; i < n; i++){

        arr[i] = rand() % 10;

    }

}


int main(){

    int arr[SIZE];

    randomArray(arr, SIZE);

    printf("normal array\n");

    for(int i = 0 ; i < SIZE; i++){

        printf("%i,",arr[i]);

    }

    printf("\n");

    bubbleSort(arr, SIZE);

    for(int j = 0; j < SIZE; j++){

        printf("%i,",arr[j]);

    }   

    printf("\n");

    return 0;
}