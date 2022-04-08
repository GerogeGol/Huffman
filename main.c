#include <stdio.h>

#include "Robin_Bobin_Barabek.h"
#include "decoding.h"
#include "priority_queue.h"
#include "string.h"
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
    if (root->is_symbol) {
        printf("%c - %d", root->symbol, root->frequency);
        if (strlen(root->code) != 0)
            printf(" - %s", root->code);
        printf("\n");
    } else
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

int GetCountUnic(int* freq_arr)
{
    int k = 0;
    for (int i = 0; i < 256; i++) {
        if (freq_arr[i] != 0)
            k++;
    }
    return k;
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
    Node* tree = CreateHUFTree(queue);  // Дерево для кодирования

    printf("\n\n\n\n\n\n\n\n");
    char code[100] = {"\0"};
    char alpha[256][1000];

    CreateCodeArray(tree, 0, code, alpha);
    PrintTree(tree, 0);
    char* str = "01";
    int len;
    int tail;
    int unic = GetCountUnic(freq_arr);
    char* coded = CodeBitString(str, &tail, &len);

    WriteToFile("../output.txt", coded, len * 8 + tail, unic, freq_arr);

    char* new_str = (char*)calloc(10000, sizeof(char));
    FILE* fr = fopen("../output.txt", "rb");
    Node* new_que = NULL;
    GetInfoFromFile(fr, &new_que, &len, &unic);
    BuildFromFile(fr, new_str);
    fclose(fr);

    Node* new_tree = CreateHUFTree(new_que);
    char code2 = {"\0"};
    CreateCodeArray(new_tree, 0, code2, alpha);
    FILE* fw = fopen("../output2.txt", "wb");
    DecodedString(fw, new_tree, new_str, len);
}