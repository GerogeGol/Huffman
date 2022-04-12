#include <stdbool.h>

#include "../utils/utils.h"
#include "iak_header.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct letterCode {
    char symb;
    char code;
} LetterCode;

void DelSymb(char *code)
{
    int i = 0;
    for (i = 0; code[i] != 0; ++i) {
    }
    code[i - 1] = 0;
}

void CreateCodeArray(Node *root, int level, char *code, char alpha[256][1000])
{
    if (!root) {
        DelSymb(code);
        return;
    }
    strcat(code, "0");
    CreateCodeArray(root->left, level + 1, code, alpha);

    if (root->is_symbol) {
        strcpy(alpha[root->symbol], code);
        strcpy(root->code, code);
    }

    strcat(code, "1");
    CreateCodeArray(root->right, level + 1, code, alpha);
    DelSymb(code);
}

void transferChar2Bin(char alpha[256][1000], char *out, FILE *fr)
{
    int c;
    while ((c = fgetc(fr)) != EOF) {  // standard C I/O file reading loop
        strcat(out, alpha[c]);
    }
}