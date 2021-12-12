#include <stdlib.h>
#include <stdio.h>
typedef int Data;
typedef struct Node
{
    Data data;
    struct Node * next;
    struct Node * prev;
}Node;
void print(Node * list) // печатать по порядку
{
    Node * p = list -> next;
    while(p != list)
    {
        printf("%d\n", p -> data);
        p = p->next;
    }
}
void print_dbg(Node * list)
{
    Node * p = list -> next;
    printf("---------\n");
    printf("list: prev=%p %p next = %p\n",  p->prev, p, p->next);
    printf("---------\n");
    while(p != list)
    {
        printf("%d [prev=%p %p next = %p]\n", p -> data, p->prev, p, p->next);
        p = p->next;
    }
    
}
void print_back(Node * list) // печатать в обратном порядке
{
    Node * p = list -> prev;
    while(p >= list)
    {
        printf("%d\n", p -> data);
        p = p->prev;
    }
}
void insert(Node * p,Node * t)  //вставить после
{
    Node * q = p->next;
    t->prev = p;
    t->next = q;
    p->next = t;
    q->prev = t;
}
void insert_before(Node * q, Node * t) // вставить до
{
    insert(q->prev, t);
}
void init(Node * list)
{
    list->next=list;
    list->prev=list;
}
int main()
{
    Node z, a, b, c, u, w;
    Node * list = &z;
    z.data = 0;
    a.data = 3;
    b.data = 17;
    c.data = 21;
    u.data = 10;
    w.data = 8;
    // z.next = &a;
    // z.prev = &c;
    // a.next = &b;
    // a.prev = &z;
    // b.next = &c;
    // b.prev = &a;
    // c.next = &z;
    // c.prev = &b;

    init(list);
    // print(list);
    // printf("\n");
    // print_back(list);
    // printf("\n");
    // print_dbg(list);

    insert_before(list, &a);
    print(list);
    printf("\n");

    insert_before(list, &b);
    print(list);
    printf("\n");

    insert_before(list, &c);
    print(list);
  //  insert_before(&z, &w);
    
    // print(list);
    // printf("\n");
 //   print_back(list);
  //  printf("\n");
  //  print_dbg(list);
    return 0;
}