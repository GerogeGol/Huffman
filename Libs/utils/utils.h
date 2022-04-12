#ifndef UTILS_H
#define UTILS_H

#define CODE_SIZE 100

typedef struct Node {
    unsigned char symbol;
    int is_symbol;
    unsigned int frequency;
    unsigned char code[CODE_SIZE];
    int level;
    struct Node *left, *right, *next;
} Node;

typedef union bit2char {
    char symb;
    struct bit {
        unsigned b0 : 1;
        unsigned b1 : 1;
        unsigned b2 : 1;
        unsigned b3 : 1;
        unsigned b4 : 1;
        unsigned b5 : 1;
        unsigned b6 : 1;
        unsigned b7 : 1;
    } byte;
} bit2char;

void FillFreqArrayFromFile(char *file_name, int *freq_arr);
char *CodeBitString(char *bit_string);
void WriteToFile(char *file_name, char *str, int len, int unic, int *freq_arr);

#endif