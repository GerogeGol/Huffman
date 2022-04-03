#include "priority_queue.h"

#include <stdio.h>
#include <stdlib.h>

#include "../utils/utils.h"

Node* CreateNode(char symbol, int frequency)
{
    Node* pnew = (Node*)calloc(1, sizeof(Node));
    pnew->symbol = symbol;
    pnew->is_symbol = 1;
    pnew->frequency = frequency;
    return pnew;
}
void PushQueue(Node** queue, Node* pnew)
{
    while (*queue) {
        if ((*queue)->frequency > pnew->frequency)
            break;
        queue = &((*queue)->next);
    }
    pnew->next = *queue;
    *queue = pnew;
}

void PrintQueue(Node* queue)
{
    printf("Queue in format value(priority):\n");
    while (queue) {
        printf("%c(%d)-->", queue->symbol, queue->frequency);
        queue = queue->next;
    }
    printf("NULL\n");
}
void PR(int kek)
{
    printf("LOL\n");
}