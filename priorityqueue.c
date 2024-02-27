#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5

struct node {
    int data;
    int priority;
};

struct node *queue[MAX_SIZE];
int front = -1, rear = -1;

int is_empty() {
    return front == -1;
}

int is_full() {
    return (rear + 1) % MAX_SIZE == front;
}

void enqueue(int data, int priority) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->priority = priority;
    if (is_full()) {
        printf("Queue overflow\n");
        return;
    }
    if (is_empty()) {
        front = rear = 0;
        queue[rear] = new_node;
        return;
    }
    int i = rear;
    while (i != front && priority > queue[i]->priority) {
        queue[(i + 1) % MAX_SIZE] = queue[i];
        i = (i - 1 + MAX_SIZE) % MAX_SIZE;
    }
    if (i == front && priority > queue[i]->priority) {
        queue[(i + 1) % MAX_SIZE] = queue[i];
        i = (i - 1 + MAX_SIZE) % MAX_SIZE;
    }
    queue[(i + 1) % MAX_SIZE] = new_node;
    rear = (rear + 1) % MAX_SIZE;
}

struct node* dequeue() {
    if (is_empty()) {
        printf("Queue underflow\n");
        return NULL;
    }
    struct node *item = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return item;
}

void print_queue() {
    if (is_empty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents:\n");
    int i = front;
    while (i != rear) {
        printf("%d (priority: %d)\n", queue[i]->data, queue[i]->priority);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d (priority: %d)\n", queue[i]->data, queue[i]->priority);
}

int main() {
    enqueue(18, 2);
    enqueue(3, 1);
    enqueue(43, 3);
    print_queue();
    struct node *item = dequeue();
    printf("Dequeued item: %d (priority: %d)\n", item->data, item->priority);
    print_queue();
    enqueue(40, 2);
    print_queue();
    return 0;
}

