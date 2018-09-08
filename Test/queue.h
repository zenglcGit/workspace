#ifndef _Queue_h

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue q);
int IsFull(Queue q);
Queue CreateQueue(int maxElements);
void DisposeQueue(Queue q);
void MakeEmpty(Queue q);
//进队列
void Enqueue(int x, Queue q);
int Front(Queue q);
//出队列
void Dequeue(Queue q);
//返回栈顶元素并且出队列
int FrontAndDequeue(Queue q);
//遍历队列
void Traverse(Queue q);





#endif // _Queue_h
