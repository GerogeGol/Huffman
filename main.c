#include <stdio.h>

#include "Robin_Bobin_Barabek.h"
#include "decoding.h"
#include "iak_header.h"
#include "priority_queue.h"
#include "stdlib.h"
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

int GetCountOfSymb(int* freq_arr)
{
    int c = 0;

    /* for as long as we can get characters... */
    for (int i = 0; i < 256; i++) {
        if (freq_arr[i] != 0)
            c += freq_arr[i];
    }
    return c;
}

int main()
{
    char* FILE_NAME = "../input.txt";
    int freq_arr[256] = {0};
    FillFreqArrayFromFile(FILE_NAME, freq_arr);
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
    int c = GetCountOfSymb(freq_arr);
    char* str = (char*)calloc(c * 1000, sizeof(char));
    FILE* file = fopen(FILE_NAME, "rb");
    transferChar2Bin(alpha, str, file);

    int unic = GetCountUnic(freq_arr);
    char* coded = CodeBitString(str);

    WriteToFile("../output.txt", coded, c, unic, freq_arr);

    FILE* fr = fopen("../output.txt", "rb");
    Node* new_que = NULL;
    int len;
    GetInfoFromFile(fr, &new_que, &len, &unic);
    char* new_str = (char*)malloc(len * 1000 * sizeof(char));
    BuildFromFile(fr, new_str);
    fclose(fr);

    Node* new_tree = CreateHUFTree(new_que);
    char code2[100] = {"\0"};
    char alpha2[256][1000];
    CreateCodeArray(new_tree, 0, code2, alpha2);
    FILE* fw = fopen("../output2.txt", "wb");
    DecodedString(fw, new_tree, new_str, len);
}