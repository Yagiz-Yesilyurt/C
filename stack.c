#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int s[SIZE];
int top = -1;

int isEmpty(){
	return top <= -1;
}

int pop(){
	if(isEmpty()){
		printf("Stack underflow\n");
		return -1;
	}
int val = s[top];
top--;
return val;
}

int push(int data){
if(top >= SIZE){
	printf("Stack overflow");
return -1;
}
s[++top] = data;
return data;
}

int peek(int data){
if(isEmpty()){
	printf("Stack overflow");
return -1;
}
return s[top];
}

int display(){
	int i;
	printf("Stack internals\n");
	printf("--------------------\n");
	printf("TOP: %2d\n", top);
	for(i=0;i<=top;i++){
		printf("%2d %2d\n", i, s[i]);
	}
	printf("\n");
	return 0;
}

int main(){
	display();
	push(3);
	push(5);
	push(7);
	display();
	int val = pop();
	printf("Popped val: %2d\n", val);
	display();
	val = pop();
	printf("Popped val: %2d\n", val);
	val = pop();
	printf("Popped val: %2d\n", val);
	val = pop();
	return 0;
}
