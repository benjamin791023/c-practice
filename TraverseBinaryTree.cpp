#include <stdio.h>
#include <stdlib.h>
struct treenode{
	treenode *leftchild;
	treenode *rightchild;
	treenode *parent;
	char val;
};

struct queuenode{
	treenode *node;
	queuenode *next;
};

struct queuelist{
	queuenode *front;
	queuenode *back;
	int size; 
};

void preorder(treenode *current){
	if (current){
		printf("%c ", current->val);
		preorder(current->leftchild);
		preorder(current->rightchild);
	}
}

void inorder(treenode *current){
	if (current){
		inorder(current->leftchild);
		printf("%c ", current->val);
		inorder(current->rightchild);
	}
}

void postorder(treenode *current){
	if (current){
		postorder(current->rightchild);
		printf("%c ", current->val);
		postorder(current->leftchild);
	}
}

bool isempty(queuelist *list){
	return list->size == 0;
}

void push(queuelist *list, treenode *x){
	if (isempty(list)){
		list->front = (queuenode *)malloc(sizeof(queuenode));
		list->front->node = x;
		list->front->next = NULL;
		list->back = list->front;
		list->size++;
		return;
	}
	queuenode *tmp = (queuenode *)malloc(sizeof(queuenode));
	tmp->node = x;
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

treenode *getfront(queuelist *list){
	if (isempty(list)){
		printf("no data. cannot get front");
		return NULL;
	}
	return list->front->node;
}

treenode *getback(queuelist *list){
	if (isempty(list)){
		printf("no data, cannot get back");
		return NULL;
	}
	return list->back->node;
}

void levelorder(queuelist *que, treenode *current){
	push(que, current);
	
	while (! isempty(que)){
		
		treenode *tmp = getfront(que);
		pop(que);
		printf("%c ", tmp->val);
		
		if (tmp->leftchild != NULL){
			push(que, tmp->leftchild);
		}
		if (tmp->rightchild != NULL){
			push(que, tmp->rightchild);
		}
	}
}

treenode *leftmost(treenode *current){
	treenode *tmp = current;
	while(tmp->leftchild != NULL){
		tmp = tmp->leftchild;
	}
	return tmp;
}

treenode *rightmost(treenode *current){
	treenode *tmp = current;
	while(tmp->rightchild != NULL){
		tmp = tmp->rightchild;
	}
	return tmp;
}

treenode *inorderseccusor(treenode *current){
	if (current->rightchild != NULL){
		return leftmost(current->rightchild);
	}
	
	treenode *succesor = current->parent;
	treenode *tmp = current;
	while (succesor != NULL && tmp == succesor->rightchild){
		tmp = succesor;
		succesor = succesor->parent;
	}
	return succesor;
}

treenode *inorderpredecessor(treenode *current){
	if (current->leftchild != NULL){
		return rightmost(current->leftchild);
	}
	
	treenode *predecessor = current->parent;
	treenode *tmp = current;
	while (predecessor != NULL && predecessor->leftchild == tmp){
		tmp = predecessor;
		predecessor = predecessor->parent;
	}
	return predecessor;
}


int main(){
	treenode *a = (treenode *)malloc(sizeof(treenode)); a->val = 'A'; a->leftchild = NULL; a->rightchild = NULL; a->parent = NULL;
	treenode *b = (treenode *)malloc(sizeof(treenode)); b->val = 'B'; b->leftchild = NULL; b->rightchild = NULL; b->parent = a;
	treenode *c = (treenode *)malloc(sizeof(treenode)); c->val = 'C'; c->leftchild = NULL; c->rightchild = NULL; c->parent = a;
	treenode *d = (treenode *)malloc(sizeof(treenode)); d->val = 'D'; d->leftchild = NULL; d->rightchild = NULL; d->parent = b;
	treenode *e = (treenode *)malloc(sizeof(treenode)); e->val = 'E'; e->leftchild = NULL; e->rightchild = NULL; e->parent = b;
	treenode *f = (treenode *)malloc(sizeof(treenode)); f->val = 'F'; f->leftchild = NULL; f->rightchild = NULL; f->parent = c;
	treenode *g = (treenode *)malloc(sizeof(treenode)); g->val = 'G'; g->leftchild = NULL; g->rightchild = NULL; g->parent = e;
	treenode *h = (treenode *)malloc(sizeof(treenode)); h->val = 'H'; h->leftchild = NULL; h->rightchild = NULL; h->parent = e;
	treenode *i = (treenode *)malloc(sizeof(treenode)); i->val = 'I'; i->leftchild = NULL; i->rightchild = NULL; i->parent = f;
	
	a->leftchild = b; a->rightchild = c;
	b->leftchild = d; b->rightchild = e;
	e->leftchild = g; e->rightchild = h;
	c->leftchild = f; f->rightchild = i;
	preorder(a);
	printf("\n");
	inorder(a);
	printf("\n");
	postorder(a);
	printf("\n");
	treenode *tmp = leftmost(a);
	printf("%c", tmp->val);
	printf("\n");
	tmp = rightmost(a);
	printf("%c", tmp->val);
	printf("\n");
	queuelist *qlist = (queuelist *)malloc(sizeof(queuelist));
	qlist->size = 0;
	levelorder(qlist, a);
	return 0;
}
