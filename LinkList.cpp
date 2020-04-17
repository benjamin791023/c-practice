#include <stdio.h>
#include <stdlib.h>
struct LinkList {
	LinkList *next;
	int value;
};


void printlist(LinkList *node){
	LinkList *tmp = node;
	while (!tmp == NULL){
		printf("%d\n", tmp->value);
		printf("\t%p\n", tmp->next);
		tmp = tmp->next;
	}
}


LinkList *pushfront(LinkList *node, int val){
	LinkList *tmp = (LinkList *)malloc(sizeof(LinkList) * 1);
	tmp->value = val;
	tmp->next = node;
	return tmp;
}

void *pushback(LinkList *node, int val){
	LinkList *back = (LinkList *)malloc(sizeof(LinkList) * 1);
	back->value = val;
	back->next = NULL;
	LinkList *tmp = node;
	while (tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = back;
}

LinkList *deletenode(LinkList *node, int val){
	LinkList *tmp = node;
	LinkList *prior = node;
	int count = 0;
	while (tmp != NULL){
		if (tmp->value == val){
			if (count == 0){
				node = tmp->next;
				free(tmp);
				tmp = node;
			}else{
				prior->next = tmp->next;
				free(tmp);
				tmp = prior->next;
			}
		}else{
		prior = tmp;
		tmp = tmp->next;
		}
		count++; 
	}
	return node;
}

void clearList(LinkList *node){
	LinkList *tmp = node;
	while (node != NULL){
		tmp = node;
		node = tmp->next;
		free(tmp);
	}
}

LinkList *reverseList(LinkList *node){
	LinkList *prior = NULL;
	LinkList *tmp = node;
	LinkList *next;
	while (tmp != NULL){
		next = tmp->next;
		tmp->next = prior;
		prior = tmp;
		tmp = next;
	}
	return prior;
} 

int main(){
	LinkList *e = (LinkList *)malloc(sizeof(LinkList) * 1);
	e->value = 9;
	e->next = NULL;
	LinkList *d = (LinkList *)malloc(sizeof(LinkList) * 1);
	d->value = 2;
	d->next = e;
	LinkList *c = (LinkList *)malloc(sizeof(LinkList) * 1);
	c->value = 5;
	c->next = d;
	LinkList *b = (LinkList *)malloc(sizeof(LinkList) * 1);
	b->value = 6;
	b->next = c;
	LinkList *a = (LinkList *)malloc(sizeof(LinkList) * 1);
	a->value = 1;
	a->next = b;
	printlist(a);
	printf("\n");
	a = reverseList(a);
	//printf("%u", a);
	printlist(a);
	return 0;
}
