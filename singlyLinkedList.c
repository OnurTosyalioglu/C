#include <stdio.h>

typedef struct Node node;

struct Node{
	int data;
	node *next;
};

int isEmpty(node *);
node* createNode();
void defaultNode(node **);
void initNode(node **,int );


int main(int argc,char *argv[]){
	
}

int isEmpty(node *head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

node* createNode(){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    if( isEmpty(temp) ){
        printf("Error :: can't allocate node\n");
        return NULL;
    }else{
        defaultNode(&temp);
        return temp;
    }
}
void defaultNode(node **temp){
    (*temp)->data = 0;
    (*temp)->next = NULL;
}

void initNode(node **temp,int number){
    (*temp)->data = number;
    (*temp)->next = NULL;
}

void pushFront(node **head,int number){
    node *temp;
    temp = createNode();
    initNode(&temp,number);
    temp->next = (*head);
    (*head) = temp;
}

void pushEnd(node **head,int number){
    node *temp;
    if( (*head) == NULL ){
        (*head) = createNode();
        (*head)->data = number;
    }else{
        temp = (*head);
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = createNode();
        initNode(&(temp->next),number);
    }
}

void pushAt(node **head,int place,int number){
    if( isEmpty(*head) ){
        errorEmpty();
    }else if( length((*head)) == (place-1) ){
        pushEnd(head,number);
    }else if( length((*head)) > (place-1) ){
        int i = 1;
        node *temp,*iter;

        iter = (*head);

        temp = createNode();
        initNode(&temp,number);

        while(++i<place){
            iter = iter->next;
        }

        temp->next = iter->next;
        iter->next = temp;

    }else{
        errorOverFlow(place);
    }
}

void popFront(node **head){
    if( isEmpty(*head) ){
        errorEmpty();
    }else{
        node *temp;
        temp = (*head)->next;
        free( *head );
        (*head) = temp;
    }
}

void popEnd(node **head){
    if( isEmpty(*head) ){
        errorEmpty();
    }else if( isEmpty((*head)->next)) {
        free(*head);
        (*head) = NULL;
    }else{
        node *temp;
        temp = (*head);
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void popAt(node **head,int place){
    if( isEmpty(*head) ){
        errorEmpty();
    }else if(length(*head) >= place ){

        if(place == 1){
            popFront(head);
        }else if( place == length(*head)){
            popEnd(head);
        }else{
            node *temp,*iter;

            iter = (*head);
            int i = 1;

            while( i<(place-1) ){
                i++;
                iter = iter->next;
            }
            temp = iter->next->next;
            free(iter->next);
            iter->next = temp;
        }
    }else{
        errorOverFlow(place);
    }
}

void popAll(node **head){
   node *iter,*temp;
   iter = (*head);
   if( isEmpty(iter) )){
        errorEmpty();
   }else{
        while( isEmpty(iter) ){
            temp = iter;
            iter = iter->next;
            free(temp);
        }
        (*head) = NULL;
   }
}

void reverse(node **head){
    node *prev,*next;
    prev = NULL;
    while((*head) != NULL){
        //  Reverse
        next = (*head)->next;
        (*head)->next = prev;
        //  Shift
        prev = (*head);
        (*head) = next;
    }
    (*head) = prev;
}

int length(node *head){
    node *temp;
    int count = 0;
    temp = head;

    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

void printList(node *head){
    int i = 1;
    if(head == NULL){
        errorEmpty();
    }else{
        while(head != NULL){
            printf("%d. element : %d\n",i,head->data);
            head = head->next;
            i++;
        }
    }
}

void printListBack(node *head,int size){
    if( !isEmpty(head->next) ){
        printListBack(head->next,size);
    }
    printf("%d. element : %d\n",size-length(head)+1,head->data);
}

int contains(node *head,int number){
    while( head != NULL){
        if(head->data == number){
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int search(node *head,int number){
    int counter = 1;
    while(head != NULL){
        if(head->data == number){
            return counter;
        }
        counter++;
        head = head->next;
    }
    return -1;
}

void errorEmpty(){
    printf("Error :: List is empty\n");
}
void errorOverFlow(int number){
    printf("Error :: List doesn't contain %d element(s) !!\n",number);