#include <stdio.h>

// #include "Robin_Bobin_Barabek.h"
// #include "priority_queue.h"
#include "utils.h"

//#include ".../priority_queue/priority_queue.h"

int main()
{
    printf("KEK");
    Node* lol = NULL;
    Node* cheburek = NULL;
    // Node*kek = generate_new_node(lol, cheburek);
    Node* queue = NULL;
    // PushQueue(&queue, 'a', 4);
    // PrintQueue(queue);

    char* str = "1111000000001111";
    int len;
    int tail;
    char* coded = CodeBitString(str, &tail, &len);
    WriteToFile("../output.txt", coded);
}
