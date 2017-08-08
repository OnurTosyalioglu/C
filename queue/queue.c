/*  
 *  Author : Kemal Onur Tosyalioglu
 *  Email  : onurtosyalioglu@gmail.com
 *  Date   : 08.08.2017
 *  Topic  : basic queue operation functions
 *
 */
#include "queue.h"

int isEmpty(data *head){
	return head == NULL ? 1 : 0;
}

data* createNode(){
	data *temp;
	temp = (data*)malloc(sizeof(data));
	return temp;
}

void initDefault(data **temp){
	(*temp)->pack = 0;
	(*temp)->next = NULL;
}

void initNode(data **temp,int number){
	(*temp)->pack = number;
	(*temp)->next = NULL;
}

void enqueue(data **head,int number){
	data *iter;
	iter = (*head);
	if(isEmpty(*head)){
		(*head) = createNode();
		initDefault(head);
		initNode(head,number);
	}else{
		while(!isEmpty(iter->next)){
			iter = iter->next;
		}
		iter->next = createNode();
		initNode(&(iter->next),number);
	}
}

int dequeue(data **head){
	data *iter;

	if(isEmpty(*head)){
		return 0;
	}else{
		iter = (*head)->next;
		free(*head);
		(*head) = iter;
		return 1;
	}
}

int  dequeueAll(data **head){
	data *iter;
	
	if( isEmpty(*head) ){
		return 0;
	}else{
		while( !isEmpty(*head) ){
			iter = (*head);
			(*head) = (*head)->next;
			dequeue(&iter);
		}
		return 1;
	}
}

void display(data *head){
	while( !isEmpty(head) ){
		printf("%d\n",head->pack);
		head = head->next;
	}
}