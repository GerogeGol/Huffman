#include "utils.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void FillFreqArrayFromFile(char *file_name, int *freq_arr)
{
    FILE *fr = fopen(file_name, "rb");
    if (!fr)
        exit(228);
    fseek(fr, 0L, SEEK_END);
    long length = ftell(fr);
    fseek(fr, 0, SEEK_SET);
    for (int i = 0; i < length; i++) {
        freq_arr[(unsigned char)fgetc(fr)]++;
    }
    fclose(fr);
}

char *CodeBitString(char *bit_string, int *tail, int *len)
{
    int count = strlen(bit_string) / 8;
    *tail = strlen(bit_string) % 8;
    *len = count;

    char *res = (char *)calloc(count + 1, sizeof(char));
    bit2char symb;
    for (int i = 0; i < count + 1; i++) {
        symb.byte.b0 = bit_string[i * 8 + 0];
        symb.byte.b1 = bit_string[i * 8 + 1];
        symb.byte.b2 = bit_string[i * 8 + 2];
        symb.byte.b3 = bit_string[i * 8 + 3];
        symb.byte.b4 = bit_string[i * 8 + 4];
        symb.byte.b5 = bit_string[i * 8 + 5];
        symb.byte.b6 = bit_string[i * 8 + 6];
        symb.byte.b7 = bit_string[i * 8 + 7];
        res[i] = symb.symb;
    }
    return res;
}

void WriteToFile(char *file_name, char *str, int len, int unic, int *freq_arr)
{
    FILE *fw = fopen(file_name, "wb");

    fprintf(fw, "%d %d ", len, unic);
    for (int i = 0; i < 256; i++) {
        if (freq_arr[i] != 0)

            fprintf(fw, "%d %d ", i, freq_arr[i]);
    }
    fwrite(str, sizeof(char), strlen(str), fw);
    fclose(fw);
}