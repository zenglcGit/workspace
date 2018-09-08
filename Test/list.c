#include <stdio.h>
#include "list.h"
struct Node
{
    int Element;
    Position next;
};

List MakeEmpty(List L)
{
    L->next = NULL;
    return L;
}

int IsEmpty(List L)
{
    return L->next == NULL;
}

int IsLast(Position p, List L)
{
    return p->next == NULL;
}

