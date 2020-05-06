#include <stdio.h>
#include <stdlib.h>
#include "que_list"

struct queuenode{
	int data;
	queuenode *next;
};

struct queuelist{
	queuenode *front;
	queuenode *back;
	int size; 
};

bool isempty(queuelist *list){
	return list->size == 0;
}

void push(queuelist *list, int x){
	if (isempty(list)){
		list->front = (queuenode *)malloc(sizeof(queuenode));
		list->front->data = x;
		list->front->next = NULL;
		list->back = list->front;
		list->size++;
		return;
	}
	queuenode *tmp = (queuenode *)malloc(sizeof(queuenode));
	tmp->data = x;
	tmp->next = NULL;
	list->back->next = tmp;
	list->back = tmp;
	list->size++;
}

void pop(queuelist *list){
	if (isempty(list)){
		printf("queue list is empty. cannot pop");
		return;
	}
	list->front = list->front->next;
	list->size--;
}

int getfront(queuelist *list){
	if (isempty(list)){
		printf("no data. cannot get front");
		return -1;
	}
	return list->front->data;
}

int getback(queuelist *list){
	if (isempty(list)){
		printf("no data, cannot get back");
		return -1;
	}
	return list->back->data;
}

void traverse(queuelist *list){
	queuenode *tmp = list->front;
	while(tmp){
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

int main(){
	queuelist *list = (queuelist *)malloc(sizeof(queuelist));
	list->size=0;
	push(list, 8);
	push(list, 9);
	push(list, 4);
	push(list, 7);
	traverse(list);
	pop(list);
	traverse(list);
	int a = getfront(list);
	int b = getback(list);
	printf("%d %d", a, b);
	return 0;
}
