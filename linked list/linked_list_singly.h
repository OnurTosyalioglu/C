#ifndef LINKED_LIST_SINGLY_H_
#define LINKED_LIST_SINGLY_H_

typedef struct Node node;

struct Node{
    int data;
    node *next;
};

int list_count(node *);
void list_print(node *);
void list_print_back(node *);
void list_sort(node **);

int node_is_empty(node *);
void node_create(node **);
void node_init(node **,int);
void node_default(node **);

void push(node **,int);
void push_front(node **,int);
int push_at(node **,int,int);

int pop(node **);
int pop_front(node **);
int pop_at(node **,int );
void pop_all(node **);

#endif
