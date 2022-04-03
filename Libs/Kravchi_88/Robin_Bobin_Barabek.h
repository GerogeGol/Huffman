#ifndef HUFFMAN_CODE_ROBIN_BOBIN_BARABEK_H
#define HUFFMAN_CODE_ROBIN_BOBIN_BARABEK_H
#include "../utils/utils.h"

Node *generate_new_node(Node *left, Node *right);
void add_to_queue(Node *head, Node *new_node);

#endif
