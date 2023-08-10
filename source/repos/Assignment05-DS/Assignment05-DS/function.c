// Huynh Minh Quan Nguyen - PROG72365 - Assignment 05

#define CRT_SECURE_NO_WARNINGS // for strcpy

#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Function to perform byte-oriented RLE encoding
// inputBuffer: Input data to be encoded
// outputBuffer: Buffer to store the encoded data
// escapeChar: Character used as an escape indicator
// Returns: Length of the encoded data in output Buffer
int byteRLEEncode(unsigned char* inputBuffer, unsigned char* outputBuffer, unsigned char escapeChar) {
    int inputLength = strlen((const char*)inputBuffer); // Get the length of input data
    int outputLength = 0; // Initialize the output length

    int i = 0;
    while (i < inputLength) {
        int count = 1;
        while (i + 1 < inputLength && inputBuffer[i] == inputBuffer[i + 1]) {
            count++;
            i++;
        }

        if (count > 1 || inputBuffer[i] == escapeChar) {
            outputBuffer[outputLength++] = escapeChar;
            outputBuffer[outputLength++] = count;
            outputBuffer[outputLength++] = inputBuffer[i];
        }
        else {
            outputBuffer[outputLength++] = inputBuffer[i];
        }

        i++;
    }

    return outputLength;
}

// Function to perform byte-oriented RLE decoding
// inputBuffer: Encoded data to be decoded
// outputBuffer: Buffer to store the decoded data
// escapeChar: Character used as an escape indication
// Returns: Length of the deecoded data in outputBuffer
int byteRLEDecode(unsigned char* inputBuffer, unsigned char* outputBuffer, unsigned char escapeChar) {
    int inputLength = strlen((const char*)inputBuffer);
    int outputLength = 0;

    for (int i = 0; i < inputLength; i++) {
        if (inputBuffer[i] == escapeChar) {
            int count = inputBuffer[i + 1];
            unsigned char ch = inputBuffer[i + 2];
            for (int j = 0; j < count; j++) {
                outputBuffer[outputLength++] = ch;
            }
            i += 2;
        }
        else {
            outputBuffer[outputLength++] = inputBuffer[i];
        }
    }

    return outputLength;
}
