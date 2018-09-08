#ifndef _Queue_h

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue q);
int IsFull(Queue q);
Queue CreateQueue(int maxElements);
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





#endif // _Queue_h
