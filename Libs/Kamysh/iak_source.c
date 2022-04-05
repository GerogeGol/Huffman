#include "iak_header.h"
#include "../utils/utils.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct letterCode {
    char symb;
    char code;
} LetterCode;

void DelSymb(char *code) {
    int i = 0;
    for (i = 0; code[i] != 0; ++i) {}
    code[i-1] = 0;
}

void CreateCodeArray(Node *root, int level, char *code, char **alpha) {

    if (!root) {
        DelSymb(code);
        return;
    }

    strcat(code, "0");
    CreateCodeArray(root->left, level + 1, code, alpha);

//    for (int i = 0; i < level; i++) {
//        printf("\t");
//    }

    if (root->is_symbol) {
        strcpy(code, alpha[root->symbol]);
//        printf("%c - %s\n", root->symbol, code);

    } else
//        printf("0\n");

        strcat(code, "1");
    CreateCodeArray(root->right, level + 1, code, alpha);
    DelSymb(code);
}

void transferChar2Bin(char *word, code_symbol *alphabet, char *out) {
    for (int i = 0; i < sizeof(word); ++i) {

    }
}