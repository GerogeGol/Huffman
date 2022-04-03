#include "Robin_Bobin_Barabek.h"

#include "stdio.h"
#include "stdlib.h"

Node *generate_new_node(Node *left, Node *right)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->symbol = 0;
    new_node->is_symbol = 0;
    new_node->frequency = left->frequency + right->frequency;
    new_node->left = left;
    new_node->right = right;
    new_node->next = NULL;
    return new_node;
}

void add_to_queue(Node *head, Node *new_node)
{
    int limit = new_node->frequency, current_frequency = head->frequency;
    Node *current_node = head;
    while (current_frequency < limit) {
        if (current_node->next && current_node->next->frequency == limit) {
            new_node->next = current_node->next;
            current_node->next = new_node;
            break;
        }
        current_node = current_node->next;
        current_frequency = current_node->frequency;
    }
}
