#ifndef _List_H
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position p, List L);
Position Find(int x, List L);
void Delete(int x, List L);
Position FindPrevious(int x, List L);
void Insert(int x, List L, Position p);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);

#endif // _List_H
