//
// Created by Игорь Камышенков on 18.03.2022.
//

#ifndef HUFFMAN_CODE_IAK_HEADER_H
#define HUFFMAN_CODE_IAK_HEADER_H
#include "stdio.h"

#define LENGTH_OF_CODE 10
typedef struct code_symbol {
    char symbol;
    int code;
} code_symbol;

void CreateCodeArray(Node *root, int level, char *code, char alpha[256][1000]);
void transferChar2Bin(char alpha[256][1000], char *out, FILE *fr);
#endif  // HUFFMAN_CODE_IAK_HEADER_H
