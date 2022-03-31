#ifndef HUFFMAN_CODE_DECODING_H
#define HUFFMAN_CODE_DECODING_H
#include "coding.h"

void GetInfoFromFile(FILE *, NODE**, char*, FILE *, int*, int*);

void BuildFromFile(FILE *, char *);

void DecodedString(FILE *, NODE *, const char *, int);

#endif
