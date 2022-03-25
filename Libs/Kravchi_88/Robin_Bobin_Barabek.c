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

void add_to_queue(Node *head, Node *New_node){

}

Node *bebra(Node *head){
    while (head->next != NULL){
        Node *left = head;
        Node *right = head->next;
        Node *new_node = generate_new_node(left, right);
        Node *new_head = head->next->next;
        add_to_queue(new_head, new_node);
        head = new_head;
    }
    return head;
}