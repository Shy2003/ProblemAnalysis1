// Data Structure and Algorithm - Assignment 04 - Huynh Minh Quan Nguyen
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {
    int input[] = { 764, 35954, 8683, 41, 11004, 1362, 77, 1, 448, 118, 5507 };
    int M = 11;
    int R = 7;

    int* hashTable = (int*)malloc(M * sizeof(int));
    if (hashTable == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    hashInit(hashTable, input, M, R);

    // Print the contents of the hash table
    for (int i = 0; i < M; i++) {
        printf("hashTable[%d] = %d\n", i, hashTable[i]);
    }

    free(hashTable);

    return 0;
}

