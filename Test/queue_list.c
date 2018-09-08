#include "queue_list.h"
#include <stdlib.h>

//链表节点定义
struct ListNode
{
    int x;
    PtrNode next;
};

struct QueueRecord
{
    PtrNode front;
    PtrNode end;
};

int IsEmpty(Queue q)
{
    return q->front == q->end;
}

Queue CreateQueue()
{
    Queue q = malloc(sizeof(struct QueueRecord));
    if (NULL == q) {
        printf("malloc fail\n");
        return NULL;
    }

    PtrNode head = malloc(sizeof(struct ListNode));
    if (NULL == head) {
        printf("malloc fail\n");
        return NULL;
    }
    head->next = NULL;

    q->front = head;
    q->end = head;

    return q;
}

void DisposeQueue(Queue q)
{
    if(IsEmpty(q)) {
        free(q->front);
        free(q);
    }
    else {
        while(!IsEmpty(q))
            Dequeue(q);
        free(q->front);
        free(q);
    }

    return;
}

void MakeEmpty(Queue q)
{
    if (NULL == q)
        return;
    else {
        while (!IsEmpty(q))
            Dequeue(q);
    }

    return;
}

//进队列
void Enqueue(int x, Queue q)
{
    PtrNode node = malloc(sizeof(struct ListNode));
    if (NULL == node) {
        printf("malloc fail\n");
        return NULL;
    }
    node->x = x;
    node->next = NULL;

    q->end->next = node;
    q->end = node;

    return;
}

int Front(Queue q)
{
    if (NULL == q || IsEmpty(q))
        return 0;
    else
        return q->front->next->x;
}

//出队列
void Dequeue(Queue q)
{
    if (NULL == q || IsEmpty(q))
        return;

    PtrNode node = q->front->next;
    if (NULL == node->next)
        q->end = q->front;
    q->front->next = node->next;
    free(node);
}

//返回栈顶元素并且出队列
int FrontAndDequeue(Queue q)
{
    int x;
    if (NULL == q || IsEmpty(q))
        exit(-1);

    x = q->front->next->x;

    PtrNode node = q->front->next;
    if (NULL == node->next)
        q->end = q->front;
    q->front->next = node->next;
    free(node);

    return x;
}

//遍历队列
void Traverse(Queue q)
{
    if (NULL == q || IsEmpty(q))
        return;
    printf("=================\n");

    PtrNode node = q->front->next;
    while (NULL != node) {
        printf("%d\n", node->x);
        node = node->next;
    }

    printf("=================\n");

    return;
}
