#ifndef UTILS_H
#define UTILS_H

#define CODE_SIZE 100

struct node {
    unsigned char symb;
    unsigned char isSymb;
    unsigned int freq;
    unsigned char code[CODE_SIZE];
    int level;
    node *left, *right, *next;
};

union bit2char {
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
};

#endif