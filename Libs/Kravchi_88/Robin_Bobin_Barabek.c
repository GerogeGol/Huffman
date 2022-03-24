#include "Robin_Bobin_Barabek.h"

Node *generate_new_node(Node *left, Node *right){
    Node *New_node = (Node*)malloc(sizeof(Node));
    New_node->symbol = 0;
    New_node->is_symbol = 0;
    New_node->frequency = left->frequency + right->frequency;
    New_node->left = left;
    New_node->right = right;
    New_node->next = NULL;
    return New_node;
}

void add_to_queue(Node *New_node){

}

Node *bebra(Node *head){
    while (head->next != NULL){
        Node *left = head;
        Node *right = head->next;
        Node *New_node = generate_new_node(left, right);
        add_to_queue(New_node);
        head = head->next->next;
    }
    return head;
}