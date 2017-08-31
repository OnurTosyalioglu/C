#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node data;

struct Node{
	int pack;
	data *next;
};

data* createNode();
void initDefault(data **);
void initNode(data **,int );

void enqueue(data **,int);
int dequeue(data **);
void dequeueAll(data **);

void display(data *);
void displayBack(data *);
int isEmpty(data *);

#endif
