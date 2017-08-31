#include "stack.h"

int node_is_empty(node *head){
    return head == NULL ? 1 : 0;
}

void node_create(node **newNode){
    (*newNode) = (node *)malloc(sizeof(node));
}

void node_init(node **newNode,int number){
    (*newNode)->next = NULL;
    (*newNode)->data = number;
}

void node_default(node **newNode){
    (*newNode)->data = 0;
    (*newNode)->next = NULL;
}

int stack_count(node *head){
    int counter;
    counter = 0;
    while(!node_is_empty(head)){
        counter++;
        head = head->next;
    }
    return counter;
}

void stack_print(node *head){
    if(!node_is_empty(head)){
        while(!node_is_empty(head)){
            printf("%d\n",head->data);
            head = head->next;
        }
    }
}

void stack_print_back(node *head){
    if(!node_is_empty(head)){
        stack_print_back(head->next);
    }

    if(!node_is_empty(head)){
        printf("%d\n",head->data);
    }
}

int pop(node **head){
    if(node_is_empty(*head)){
        return 0;
    }else{
        if( node_is_empty((*head)->next) ){
            free(*head);
            (*head) = NULL;
        }else{
            node *iter;
            node *prevIter;
            iter = (*head);
            while( !node_is_empty(iter->next) ){
                prevIter = iter;
                iter = iter->next;
            }
            free(iter);
            prevIter->next = NULL;
        }
        return 1;
    }
}

void push(node **head,int number){
    node *temp;

    node_create(&temp);
    node_init(&temp,number);

    if(node_is_empty(*head)){
        (*head) = temp;
    }else{
        node *iter;
        iter = (*head);

        while(!node_is_empty(iter->next)){
            iter = iter->next;
        }

        iter->next = temp;
    }
}

