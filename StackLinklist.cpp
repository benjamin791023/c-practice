#include <stdio.h> 
#include <stdlib.h>

struct stacknode{
	int data;
	stacknode *next;
};

struct stacklist{
	stacknode *top;
	int size;
};

bool isempty(stacklist *list){
	return list->size == 0;
};

void push(stacklist *list, int x){
	if (isempty(list)){
		stacknode *node = (stacknode *)malloc(sizeof(stacknode));
		node->data = x;
		node->next = NULL;
		list->top = node;
		list->size++;
		printf("push empty");
		return;
	}
	printf("push");
	stacknode *node = (stacknode *)malloc(sizeof(stacknode));
	node->data = x;
	node->next = list->top;
	list->top = node;
	list->size++;
	return;
}

int getsize(stacklist *list){
	return list->size;
}

void pop(stacklist *list){
	if (isempty(list)) {
		printf("no data to pop");
	}
	list->top = list->top->next;
	list->size--;
	return;
}

void traverselist(stacklist *list){
	stacknode *tmp = list->top;
	while(tmp){
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	return;
}

int main(){
	stacklist *list = (stacklist *)malloc(sizeof(stacklist));
	list->size = 0;
	stacknode *node = (stacknode *)malloc(sizeof(stacknode));
	push(list, 3);
	push(list, 9);
	int a = getsize(list);
	printf("%d\n", a);
	printf("\n");
	traverselist(list);
	printf("\n");
	pop(list);
	pop(list);
	pop(list);
	traverselist(list);
	return 0;
}
