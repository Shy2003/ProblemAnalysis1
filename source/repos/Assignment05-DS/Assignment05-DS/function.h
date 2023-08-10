// Huynh Minh Quan Nguyen - PROG72365 - Assignment 05

#define CRT_SECURE_NO_WARNINGS

#pragma once
#define BUFFER_SIZE 200

int byteRLEEncode(unsigned char* inputBuffer, unsigned char* outputBuffer, unsigned char escapeChar);
int byteRLEDecode(unsigned char* inputBuffer, unsigned char* outputBuffer, unsigned char escapeChar);