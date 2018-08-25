#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

typedef struct Node node;
typedef struct Data data;

struct Node{
    data *data;

    node *prev;
    node *next;
};

struct Data{
  int number;
};

#endif
