#include <stdlib.h>
#include <stdio.h>
typedef int Data;
typedef struct Node
{
    Data data;
    struct Node * next;
    struct Node * prev;
}Node;
void print(Node * list)
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
void print_back(Node * list)
{
    Node * p = list -> prev;
    while(p != list)
    {
        printf("%d\n", p -> data);
        p = p->prev;
    }
}

int main()
{
    Node z, a, b, c, u;
    Node * list = &z;
    z.data = 0;
    a.data = 3;
    b.data = 17;
    c.data = 21;
    u.data = 10;
    z.next = &a;
    z.prev = &c;
    a.next = &b;
    a.prev = &z;
    b.next = &c;
    b.prev = &a;
    c.next = &z;
    c.prev = &b;

    print(list);
    printf("\n");
    print_back(list);
    printf("\n");
    print_dbg(list);

    u.prev = &a;
    u.next = &b;
    a.next = &u;
    b.prev = &u;
    print(list);
    printf("\n");
    print_back(list);
    printf("\n");
    print_dbg(list);
    return 0;
}