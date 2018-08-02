#include "linked_list_singly.h"

int node_is_empty(node *head){
    return head == NULL ? 1 : 0;
}

int list_count(node *head){
    int counter = 0;
    while( !node_is_empty(head) ){
        head = head->next;
        counter++;
    }
    return counter;
}

void list_print(node *head){
    while( !node_is_empty(head) ){
        printf("%d\n", head->data);
        head = head->next;
    }
}

void list_print_back(node *head){
    if(!node_is_empty(head)){
        list_print_back(head->next);
        printf("%d\n",head->data);
    }
}

void list_sort(node **head){
    if(!node_is_empty(*head)){
        node *iter;
        int swap;
        int temp;
        swap = 1;
        while(swap){
            swap = 0;
            iter = (*head);
            while(!node_is_empty(iter->next)){
                if(iter->data > iter->next->data){
                    temp = iter->data;
                    iter->data = iter->next->data;
                    iter->next->data = temp;
                    swap = 1;
                }
                iter = iter->next;
            }
        }
    }
}

void node_create(node **newNode){
    (*newNode) = (node *)malloc(sizeof(node));
    node_default(newNode);
}

void node_default(node **newNode){
    (*newNode)->data = 0;
    (*newNode)->next = NULL;
}

void node_init(node **newNode,int number){
    (*newNode)->data = number;
    (*newNode)->next = NULL;
}

void push(node **head,int number){
    if(node_is_empty(*head)){
        node_create(head);
        node_init(head,number);
    }else{
        node *iter;
        iter = (*head);
        while( !node_is_empty(iter->next) ){
            iter = iter->next;
        }
        node_create(&(iter->next));
        node_init(&(iter->next),number);
    }
}

void push_front(node **head,int number){
    node *temp;
    node_create(&temp);
    node_init(&temp,number);
    temp->next = (*head);
    (*head) = temp;
}

int push_at(node **head,int number,int position){
    if( position < 0 || list_count(*head) < position ){
        return 0;
    }else{
        if( position == 0 ){
            push_front(head,number);
        }else if( position == list_count(*head) ){
            push(head,number);
        }else{
            int counter;
            node *iter,*temp;

            iter = (*head);
            counter = 1;

            node_create(&temp);
            node_init(&temp,number);

            while(counter < position){
                counter++;
                iter = iter->next;
            }

            temp->next = iter->next;
            iter->next = temp;
        }
        return 1;
    }
}

int pop(node **head){
    if( !node_is_empty(*head) ){
        if( node_is_empty((*head)->next) ){
            free(*head);
            *head = NULL;
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
    }else{
        return 0;
    }
}

int pop_front(node **head){
    if( node_is_empty(*head) ){
        return 0;
    }else{
        node *temp;
        temp = (*head);
        (*head) = (*head)->next;
        free(temp);
        return 1;
    }
}

int pop_at(node **head,int position){
    if( position < 0 || list_count(*head) < position ){
        return 0;
    }else{
        if(list_count(*head) == position){
            pop(head);
        }else{
            int counter;
            node *iter,*next;

            iter = (*head);
            counter = 1;

            while( counter < position ){
                counter++;
                iter = iter->next;
            }
            next = iter->next->next;
            free(iter->next);
            iter->next = next;
        }
        return 1;
    }
}

void pop_all(node **head){
    while(!node_is_empty(*head)){
        pop_front(head);
    }
    (*head) = NULL;
}
