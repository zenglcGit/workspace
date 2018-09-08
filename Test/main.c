#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    int maxElements = 10;
    Queue q = CreateQueue(maxElements);

    Enqueue(10, q);
    Enqueue(20, q);
    Enqueue(30, q);
    Enqueue(40, q);
    Traverse(q);
    Dequeue(q);
    Traverse(q);
    DisposeQueue(q);
    Traverse(q);
    return 0;
}
