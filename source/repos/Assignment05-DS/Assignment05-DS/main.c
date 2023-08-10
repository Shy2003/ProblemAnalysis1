// Huynh Minh Quan Nguyen - PROG72365 - Assignment 05
#define CRT_SECURE_NO_WARNINGS
#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    unsigned char* testBuffer = (unsigned char*)malloc(sizeof(unsigned char) * BUFFER_SIZE);

    if (!testBuffer) {
        return -1;
    }

    // Test Case 1: Compresses well
    strcpy_s((char*)testBuffer, BUFFER_SIZE, "aaabbbbcccddeee");
    printf("Original: %s Length: %zu\n", testBuffer, strlen((const char*)testBuffer));

    unsigned char* compressedBuffer = (unsigned char*)malloc(sizeof(unsigned char) * BUFFER_SIZE);
    int compressedLength = byteRLEEncode(testBuffer, compressedBuffer, '*');
    compressedBuffer[compressedLength] = '\0'; // Null-terminate the compressed buffer
    printf("Compressed: %s Length: %d\n", compressedBuffer, compressedLength);

    unsigned char* decompressedBuffer = (unsigned char*)malloc(sizeof(unsigned char) * BUFFER_SIZE);
    int decompressedLength = byteRLEDecode(compressedBuffer, decompressedBuffer, '*');
    decompressedBuffer[decompressedLength] = '\0'; // Null-terminate the string
    printf("Decompressed: %s Length: %d\n", decompressedBuffer, decompressedLength);

    free(compressedBuffer);
    free(decompressedBuffer);

    // Test Case 2: Does not compress
    strcpy_s((char*)testBuffer, BUFFER_SIZE, "abcdefgh");
    printf("Original: %s Length: %lu\n", testBuffer, strlen((const char*)testBuffer));

    compressedLength = byteRLEEncode(testBuffer, compressedBuffer, '*');
    if (compressedLength == -1) {
        printf("Error: Cannot compress further.\n");
    }

    free(testBuffer);

    return 0;
}