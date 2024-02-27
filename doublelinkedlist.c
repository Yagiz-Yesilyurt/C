#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
struct node{
	int data;
	struct node* next;
};
struct node* head = NULL;
struct node* last_node = NULL;

int linkedlist(){
	int i;
	head = (struct node*) malloc(sizeof(struct node));
	head->data = 0;
	head->next = NULL;
	last_node = head;
	for(i=1;i<SIZE;i++){
		struct node* tmp = (struct node*) malloc(sizeof(struct node));
		tmp->data = i;
		tmp->next = head;
		head = tmp;	
	}
	struct node* tmp = head;
	printf("Struct values: ");
	while(tmp){
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n\n");
	return 0;
}
int s[SIZE];
int top = -1;
int reverse_function()
{	
	struct node* tmp = head;
	while(tmp){
		s[++top] = tmp->data;
		tmp = tmp->next;
	}
	printf("Stack Values:\n");
	while(top>=0){
		printf("%2d %2d\n", top, s[top]);
		top--;
	}
	return 0;
}

int main(){
	linkedlist();
	reverse_function();
	return 0;
}
