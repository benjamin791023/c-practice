#include <stdio.h>
#include <stdlib.h>

struct queuenode{
	int capacity;
	int front;
	int back;
	int *queue;
};


int getsize(queuenode *queue){
	int size;
	if (queue->front < queue->back){
		size = queue->back - queue->front;
	}else{
		size = queue->capacity - (queue->front - queue->back);
	}
	return size;
}

void traverse(queuenode *queue){
	int size = getsize(queue);
	for (int i=queue->front+1; i<=queue->front+size; i++){
		printf("que %d %d\n", i %queue->capacity, queue->queue[i%queue->capacity]);
	}
}

void doublecapacity(queuenode *queue){
	int *newqueue = (int *)malloc(sizeof(int) * queue->capacity * 2);
	int j = queue->front, size=getsize(queue);
	for (int i=1; i<=size; i++){
		newqueue[i] = queue->queue[++j % queue->capacity];
	}
	queue->back = getsize(queue);
	queue->front = 0;
	queue->capacity = queue->capacity*2;
	free(queue->queue);
	queue->queue = newqueue;
}

bool isfull(queuenode *queue){
	return (queue->back+1)%queue->capacity == queue->front;
}

bool isempty(queuenode *queue){
	return queue->front == queue->back;
} 

void push(queuenode *queue, int x){
	if (isfull(queue)){
		doublecapacity(queue);
	}
	queue->back = (queue->back + 1) % queue->capacity;
	queue->queue[queue->back] = x;
}

void pop(queuenode *queue){
	if (isempty(queue)){
		printf("queue is empty.\n");
		return;
	}
	queue->front = (queue->front + 1) % queue->capacity;
}

int getfront(queuenode *queue){
	if (isempty(queue)){
		printf("queue is empty.\n");
	}
	return queue->queue[(queue->front + 1) % queue->capacity];
}

int getback(queuenode *queue){
	if (isempty(queue)){
		printf("queue is empty.\n");
	}
	return queue->queue[(queue->back) % queue->capacity];
}

int main(){
	queuenode *queue = (queuenode *)malloc(sizeof(queuenode));
	queue->back = 0;
	queue->front = 0;
	queue->capacity = 2;
	queue->queue = (int *)malloc(sizeof(int) * queue->capacity);
	push(queue, 9);
//	traverse(queue);
	printf("\n");
	push(queue, 8);
//	traverse(queue);
	printf("\n");
	push(queue, 6);
//	traverse(queue);
	
	int f = getfront(queue);
	printf("f %d\n", f);
	f = getback(queue);
	printf("b %d\n", f);
	pop(queue);
//	traverse(queue);
	pop(queue);
	printf("\n");
//	traverse(queue);
	printf("\n");
	push(queue, 3);
//	traverse(queue);
	printf("\n");
	push(queue, 7);
//	traverse(queue);
	printf("\n");
	push(queue, 4);
	printf("\n");
	traverse(queue);
	
	return 0;
}
