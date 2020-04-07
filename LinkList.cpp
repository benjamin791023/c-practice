#include <stdio.h>
#include <stdlib.h>

int main(){
	struct LinkList {
		LinkList *next;
		int value;
	};
	LinkList *e = (LinkList *)malloc(sizeof(LinkList) * 1);
	e->value = 9;
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
	
	return 0;
}
