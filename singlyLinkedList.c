#include <stdio.h>

typedef Node node;

struct Node{
	int data;
	node *next;
};


node* createNode();
void defaultNode();
void initNode();
void deleteNode();

int isEmpty(node *);
void print(node *);
void printBack(node *);
int count(node *);

void push();
void pushFront();
void pop();
void popFront();
void popAll();

int main(int argc, char const *argv[])
{
	
	return 0;
}

int isEmpty(node *head){
	return (head == NULL) ? 1 : 0 ;
}

void print(node *tempHead){
	while(){

	}
}

void printBack(node *tempHead){
	while(){

	}
}