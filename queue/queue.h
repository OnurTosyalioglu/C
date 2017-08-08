/*  
 *  Author : Kemal Onur Tosyalioglu
 *  Email  : onurtosyalioglu@gmail.com
 *  Date   : 08.08.2017
 *  Topic  : basic queue operations
 *
 */

#ifndef QUEUE_H_
#define QUEUE_H_

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
int dequeueAll(data **);

void display(data *);
void displayBack(data *);
int isEmpty(data *);

#endif