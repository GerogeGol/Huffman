#include <stdio.h>

#include "Robin_Bobin_Barabek.h"
#include "priority_queue.h"
#include "utils.h"

//#include ".../priority_queue/priority_queue.h"
void PrintTree(Node* root, int level)
{
    if (!root)
        return;

    PrintTree(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    if (root->is_symbol)
        printf("%c - %d\n", root->symbol, root->frequency);
    else
        printf("0\n");
    PrintTree(root->left, level + 1);
}

Node* CreateHUFTree(Node* head)
{
    while (head->next != NULL) {
        Node *left = head, *right = head->next;
        Node* new_node = generate_new_node(left, right);
        Node* new_head = head->next->next;
        PushQueue(&new_head, new_node);
        head = new_head;
    }
    return head;
}

int main()
{
    int freq_arr[256] = {0};
    FillFreqArrayFromFile("../input.txt", freq_arr);
    Node* queue = NULL;
    for (int i = 0; i < 256; i++) {
        if (freq_arr[i] == 0)
            continue;
        PushQueue(&queue, CreateNode(i, freq_arr[i]));
    }
    PrintQueue(queue);
    Node* tree = CreateHUFTree(queue); // Дерево для кодирования
    PrintTree(tree, 0);

    char* str = "1111000000001111";
    int len;
    int tail;
    char* coded = CodeBitString(str, &tail, &len);
    WriteToFile("../output.txt", coded);
}
