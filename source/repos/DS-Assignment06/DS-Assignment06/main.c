// Huynh Minh Quan Nguyen - Data Structure and Algorithm 
// Assignment 06
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

int main(void) {
    int size = 20000;
    int* array1 = (int*)malloc(size * sizeof(int));
    int* array2 = (int*)malloc(size * sizeof(int));

    if (array1 == NULL || array2 == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand(time(NULL));

    // Generate a random number to insert into arrays
    int randomNumber = rand();

    // Insert the same random number into both arrays
    for (int i = 0; i < size; i++) {
        array1[i] = randomNumber;
        array2[i] = randomNumber;
    }

    // Bubble Sort
    clock_t startTimeBubble = clock();
    bubbleSort(array1, size);
    clock_t endTimeBubble = clock();
    double sortTimeBubble = (double)(endTimeBubble - startTimeBubble) / CLOCKS_PER_SEC;

    // Heap Sort
    clock_t startTimeHeap = clock();
    heapSort(array2, size);
    clock_t endTimeHeap = clock();
    double sortTimeHeap = (double)(endTimeHeap - startTimeHeap) / CLOCKS_PER_SEC;

    printf("Time taken for Bubble Sort: %lf seconds\n", sortTimeBubble);
    printf("Time taken for Heap Sort: %lf seconds\n", sortTimeHeap);


    free(array1);
    free(array2);

    return 0;
}