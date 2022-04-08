#ifndef HUFFMAN_CODE_DECODING_H
#define HUFFMAN_CODE_DECODING_H
#include "../priority_queue/priority_queue.h"
#include "../utils/utils.h"
#include "stdio.h"

void GetInfoFromFile(FILE* fr, Node** elem, int* len, int* unic);

void BuildFromFile(FILE* fr, char* newSrtCodes);

void DecodedString(FILE* fw, Node* newHead, const char* newSrtCodes, int length);

#endif
