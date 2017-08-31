#include "queue.h"

int node_is_empty(node *head){
	return (head == NULL) ? 1 : 0;
}

void node_create(node **newNode){
	(*newNode) = (node *)malloc(sizeof(node));
}

void node_default(node **newNode){
	(*newNode)->next = NULL;
	(*newNode)->data = 0;
}

void node_init(node **newNode,int number){
	(*newNode)->next = NULL;
	(*newNode)->data = number;
}

void queue_print(node *head){
    while( !node_is_empty(head) ){
        printf("%d\n", head->data);
        head = head->next;
    }
}

void queue_print_back(node *head){
	if(!node_is_empty(head)){
		queue_print_back(head->next);
        printf("%d\n",head->data);
	}
}

int queue_count(node *head){
	int counter;
	counter = 0;
	while(!node_is_empty(head)){
		head = head->next;
		counter++;
	}
	return counter;
}

void queue(node **head,int number){
	if(node_is_empty(*head)){
		node_create(head);
		node_init(head,number);
	}else{
		node *iter;
		iter = (*head);

		while(!node_is_empty(iter->next)){
			iter = iter->next;
		}

		node_create(&(iter->next));
		node_init(&(iter->next),number);
	}

}

int dequeue(node **head){
    if( !node_is_empty(*head) ){
        node *temp;
        temp = (*head);
        (*head) = temp->next;
        free(temp);
        return 1;
    }else{
        return 0;
    }
}

void dequeue_all(node **head){
    while(!node_is_empty(*head)){
        dequeue(head);
    }
    (*head) = NULL;
}
