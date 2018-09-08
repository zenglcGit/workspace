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
//������
void Enqueue(int x, Queue q);
int Front(Queue q);
//������
void Dequeue(Queue q);
//����ջ��Ԫ�ز��ҳ�����
int FrontAndDequeue(Queue q);
//��������
void Traverse(Queue q);

#endif // _Queue_List_h
