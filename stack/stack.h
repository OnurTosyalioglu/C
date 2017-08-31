#ifndef STACK_H_
#define STACK_H_

typedef struct Node node;

struct Node
{
    int data;
    node *next;
};

int node_is_empty(node *);
void node_create(node **);
void node_init(node **,int);
void node_default(node **);

int stack_count(node *);
void stack_print(node *);
void stack_print_back(node *);

int pop(node **);
void push(node **,int);

#endif
