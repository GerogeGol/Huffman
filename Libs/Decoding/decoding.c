#include "decoding.h"

#include "stdio.h"

void GetInfoFromFile(FILE* fr, Node** elem, int* len, int* unic)
{                  // берет информацию с зашифрованного файла
    int num1 = 0;  //передается сюда файл, пустое дерево, зашифрованная строка
    int num2 = 0;  //количество всего символов, количество уникальных символов
    unsigned newFreq[256] = {0};
    fscanf(fr, "%d %d ", len, unic);
    int i = 0;
    while (fscanf(fr, "%d %d ", &num1, &num2) == 2) {
        newFreq[num1] = num2;
        PushQueue(&(*elem), CreateNode((char)num1, num2));
        i += 1;
        if (i == *unic) {
            break;
        };
    }
}

void BuildFromFile(FILE* fr, char* newSrtCodes)
{  // строит дерево по зашифрованной строке из файла
    bit2char symb;
    int i = 0;
    while (1) {
        int symbol = fgetc(fr);
        if (symbol == EOF) {
            break;
        }
        symb.symb = (char)symbol;
        newSrtCodes[i] = symb.byte.b0 ? '1' : '0';
        newSrtCodes[i + 1] = symb.byte.b1 ? '1' : '0';
        newSrtCodes[i + 2] = symb.byte.b2 ? '1' : '0';
        newSrtCodes[i + 3] = symb.byte.b3 ? '1' : '0';
        newSrtCodes[i + 4] = symb.byte.b4 ? '1' : '0';
        newSrtCodes[i + 5] = symb.byte.b5 ? '1' : '0';
        newSrtCodes[i + 6] = symb.byte.b6 ? '1' : '0';
        newSrtCodes[i + 7] = symb.byte.b7 ? '1' : '0';

        i += 8;
    }
    newSrtCodes[i] = '\0';
}

void DecodedString(FILE* fw, Node* newHead, const char* newSrtCodes, int length)
{  //расшифровка по закодированной строке
    for (int pos = 0, count = 0; count < length; ++count) {
        Node* saveNode = newHead;
        int len = 0;
        while (saveNode->right || saveNode->left) {
            if (newSrtCodes[pos + len++] == '0')
                saveNode = saveNode->left;
            else
                saveNode = saveNode->right;
        }

        fprintf(fw, "%c", saveNode->symbol);
        pos += len;
    }
}