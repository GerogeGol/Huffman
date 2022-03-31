#include "decoding.h"
#include "stdio.h"

void GetInfoFromFile(FILE * fr, NODE** elem, char* str, FILE *fw, int *len, int *unic) {
    int num1 = 0;
    int num2 = 0;
    unsigned newFreq[256] = {0};
    fscanf(fr, "%d %d ", len, unic);
    int i = 0;
    while (fscanf(fr, "%d %d ", &num1, &num2) == 2) {
        newFreq[num1] = num2;
        AddNewNode(&(*elem), newFreq, num1);
        i += 1;
        if (i == *unic) {break;};
    }
}

void BuildFromFile(FILE * fr, char * newSrtCodes) {
    BIT2CHAR symb;
    int i = 0;
    while (1) {
        int symbol = fgetc(fr);
        if (symbol == EOF) {
            break;
        }
        symb.symb = (char) symbol;
        newSrtCodes[i] = symb.mbit.b1 ? '1' : '0';
        newSrtCodes[i + 1] = symb.mbit.b2 ? '1' : '0';
        newSrtCodes[i + 2] = symb.mbit.b3 ? '1' : '0';
        newSrtCodes[i + 3] = symb.mbit.b4 ? '1' : '0';
        newSrtCodes[i + 4] = symb.mbit.b5 ? '1' : '0';
        newSrtCodes[i + 5] = symb.mbit.b6 ? '1' : '0';
        newSrtCodes[i + 6] = symb.mbit.b7 ? '1' : '0';
        newSrtCodes[i + 7] = symb.mbit.b8 ? '1' : '0';

        i+=8;
    }
    newSrtCodes[i] = '\0';

}

void DecodedString(FILE * fw,NODE * newHead, const char * newSrtCodes, int lenght) {
    for (int pos = 0, count = 0; count < lenght; ++count) {
        NODE * saveNode = newHead;
        int len = 0;
        while (saveNode->right || saveNode->left) {
            if (newSrtCodes[pos + len++] == '0')
                saveNode = saveNode->left;
            else
                saveNode = saveNode->right;
        }
        fprintf(fw, "%c", saveNode->symb);
        pos += len;
    }
}