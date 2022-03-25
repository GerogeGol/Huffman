#include <stdio.h>
#include "utils.h"
#include "Robin_Bobin_Barabek.h"
#include "priority_queue.h"


int main(int, char**) {
    printf("KEK");
    Node*lol = NULL;
    Node*cheburek = NULL;
    //Node*kek = generate_new_node(lol, cheburek);
    Node*queue = NULL;
    PushQueue(&queue, 'a', 4);
    PrintQueue(queue);
}
