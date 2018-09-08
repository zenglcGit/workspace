#include "queue.h"
#include <stdlib.h>

#define MinQueueSize (5)

struct QueueRecord
{
    int capacity;//队列容量
    int front; //队头
    int rear; //队尾
    int size; //队列中有效元素的个数
    int *array; //指向队列的指针
};


int IsEmpty(Queue q)
{
    return q->size == 0;
}

int IsFull(Queue q)
{
    return q->size == q->capacity;
}

Queue CreateQueue(int maxElements)
{
    if (maxElements < MinQueueSize) {
        printf("Queue size is too small!\n");
        return NULL;
    }

    Queue q = malloc(sizeof(struct QueueRecord));
    if (NULL == q) {
        printf("Queue size is too small!\n");
        return NULL;
    }

    q->array = malloc(sizeof(int) * maxElements);
    if (NULL == q->array) {
        printf("Queue size is too small!\n");
        return NULL;
    }

    q->capacity = maxElements;
    MakeEmpty(q);
    return q;
}

void DisposeQueue(Queue q)
{
    if (IsEmpty(q)) {
        free(q->array);
        free(q);
    }
    else {
        while (!IsEmpty(q)) {
            Dequeue(q);
        }

        free(q->array);
        free(q);
    }
}

void MakeEmpty(Queue q)
{
    if (NULL != q) {
        q->size = 0;
        q->front = 1;
        q->rear = 0;
    }
}

//判断队尾/队头的索引是否等于队列容量-1，如果是，队尾绕回开头
static int Succ(int value, Queue q)
{
    if (value++ == q->capacity)
        value = 0;
    return value;
}
//进队列
void Enqueue(int x, Queue q)
{
    if (IsFull(q)) {
        printf("Queue is full");
        return;
    }
    else {
        q->size++;
        q->rear = Succ(q->rear, q);
        q->array[q->rear] = x;
    }

    return;
}

int Front(Queue q)
{
    return q->array[q->front];
}

//出队列
void Dequeue(Queue q)
{
    q->size--;
    q->front = Succ(q->front, q);
    return;
}

//返回栈顶元素并且出队列
int FrontAndDequeue(Queue q)
{
    int x = Front(q);
    Dequeue(q);
    return x;
}

void Traverse(Queue q)
{
    int i, y;

    if (NULL == q)
        return;

    if (IsEmpty(q))
        return;

    y = q->front;
    for (i = 0; i < q->size; i++) {
        printf("%d\n", q->array[y]);
        y = Succ(y, q);
    }

    printf("================\n");
    return;
}
