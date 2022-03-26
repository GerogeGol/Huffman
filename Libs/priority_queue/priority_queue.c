#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
void PushQueue(Node** queue, char symbol, int frequency)
{
    while (*queue)
    {
        if ((*queue)->frequency > frequency)
            break;
        queue = &((*queue)->next);
    }
    Node* pnew = (Node*)malloc(sizeof(Node));
    pnew->symbol= symbol;
    pnew->is_symbol = 1;
    pnew->frequency = frequency;
    pnew->next = *queue;
    *queue = pnew;
}
void PrintQueue(Node* queue)
{
    while (queue)
    {
        printf("value: %c priority: %d\n", queue->symbol, queue->frequency);
        queue = queue->next;
    }
}