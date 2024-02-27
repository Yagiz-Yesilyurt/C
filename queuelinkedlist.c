#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node *front=NULL;
struct node *rear=NULL;


struct node* allocate(int data){
	struct node *tmp=malloc(sizeof(struct node));
	tmp->data=data;
	tmp->next=NULL;
	
	return tmp;
}

int is_empty(){
	
	return front == NULL;
	
}

struct node* enqueue(int data) {
    struct node* n = allocate(data);
    struct node* tmp = front;
    struct node* prev = NULL;

    if (is_empty()) {
        front = n;
        rear = n;
        return n;
    }

    if (front == rear) {
        if (front->data > data) {
            n->next = front;
            front = n;
        } else {
            front->next = n;
            rear = n;
        }
        return front;
    }

    while (tmp != NULL && tmp->data <= data) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (prev == NULL) {
        n->next = front;
        front = n;
    } else {
        n->next = prev->next;
        prev->next = n;
    }

    if (tmp == NULL) {
        rear = n;
    }

    return front;
}
int dequeue() {
    if (is_empty()) {
        printf("empty queue\n");
        return 0;
    }
    int res = front->data;
    struct node* n = front;
    front = front->next;
    free(n);
    if (front == NULL) {
        rear = NULL;
    }
    return res;
}

int print(){
	struct node* tmp= front;
	printf("The contents of the queue:");
	
	while(tmp){
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
	return 0;
}

int main(){
	
	enqueue(12);
	enqueue(7);
	enqueue(35);
	dequeue();
	enqueue(8);
	print();	
	
}
