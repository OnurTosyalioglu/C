#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_

typedef struct Node node;
typedef struct Data data;

struct Node{
    data *data;
    node *next;
};

struct Data{
  int number;
};

#endif
