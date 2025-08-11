#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
typedef struct DListNode
{
int data;
struct DListNode *prev;
struct DListNode *next;
}DListNode;
#endif

