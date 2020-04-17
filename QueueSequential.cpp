#include <stdio.h>
#include <stdlib.h>

struct queuesequential{
	int capacity;
	int front;
	int back;
	int *queue;
};

void traverse(queuesequential *queue){
	if (queue->back == -1){
		return;
	}
	for (int i=queue->front+1; i<=queue->back; i++){
		printf("t%d %d\n", i, queue->queue[i]);
	}
}

void doublecapacity(queuesequential *queue){
	queue->capacity *= 2;
	int *newqueue = (int *)malloc(sizeof(int)*queue->capacity);
	
	int j = -1;
	for (int i=queue->front+1; i <= queue->back; i++){
		j++;
		newqueue[j] = queue->queue[i];
	}
	queue->front = -1;
	queue->back = j;
	free(queue->queue);
	queue->queue = newqueue;
}


bool isempty(queuesequential *queue){
	return queue->back == -1;
}

bool isfull(queuesequential *queue){
	return queue->back+1 == queue->capacity;
}

void push(queuesequential *queue, int x){
	if (isfull(queue)){
		doublecapacity(queue);
	}
	queue->queue[++queue->back] = x;
}

void pop(queuesequential *queue){
	if (isempty(queue)){
		printf("queue is empty.\n");
		return;
	}
	queue->front++;
}

int getfront(queuesequential *queue){
	if (isempty(queue)){
		printf("queue is empty.\n");
	}
	return queue->queue[queue->front+1];
}

int getback(queuesequential *queue){
	if (isempty(queue)){
		printf("queue is empty.\n");
	}
	return queue->queue[queue->back];
}

int getcapacity(queuesequential *queue){
	return queue->capacity;
}


int main(){
	queuesequential *queue = (queuesequential *)malloc(sizeof(queuesequential));
	queue->capacity = 2;
	int *tmp = (int *)malloc(sizeof(int) * queue->capacity);
	queue->queue = tmp;
	queue->front=-1;
	queue->back=-1;
	push(queue, 5);
	push(queue, 7);
	traverse(queue);
	push(queue, 8);
	traverse(queue);
	return 0;
}
