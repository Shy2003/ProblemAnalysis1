// Data Structure and Algorithm - Assignment 04 - Huynh Minh Quan Nguyen
#include "hash.h"

void hashInit(int* hashTable, int* input, int M, int R) {
    for (int i = 0; i < M; i++) {
        hashTable[i] = -1; // Initialize all hash table entries as -1 (indicating empty)
    }

    for (int i = 0; i < M; i++) {
        int key = input[i];
        int h1 = key % M;
        int h2 = R - (key % R);

        int j = 0;
        int index = (h1 + h2 * j) % M;

        while (hashTable[index] != -1) {
            j++;
            index = (h1 + h2 * j) % M;
        }

        hashTable[index] = key;
    }
}

