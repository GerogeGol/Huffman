#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "../utils/utils.h"
Node* CreateNode(char symbol, int frequency);
void PushQueue(Node** queue, Node* pnew);
void PrintQueue(Node* queue);

#endif