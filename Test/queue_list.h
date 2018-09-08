#ifndef _Queue_List_h

struct QueueRecord;
struct ListNode;
typedef struct QueueRecord *Queue;
typedef struct ListNode *Position;
typedef struct ListNode *PtrNode;

int IsEmpty(Queue q);
Queue CreateQueue();
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

#endif // _Queue_List_h
