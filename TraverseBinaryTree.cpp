#include <stdio.h>
#include <stdlib.h>
struct treenode{
	treenode *leftchild;
	treenode *rightchild;
	char val;
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

int main(){
	treenode *a = (treenode *)malloc(sizeof(treenode)); a->val = 'A'; a->leftchild = NULL; a->rightchild = NULL;
	treenode *b = (treenode *)malloc(sizeof(treenode)); b->val = 'B'; b->leftchild = NULL; b->rightchild = NULL;
	treenode *c = (treenode *)malloc(sizeof(treenode)); c->val = 'C'; c->leftchild = NULL; c->rightchild = NULL;
	treenode *d = (treenode *)malloc(sizeof(treenode)); d->val = 'D'; d->leftchild = NULL; d->rightchild = NULL;
	treenode *e = (treenode *)malloc(sizeof(treenode)); e->val = 'E'; e->leftchild = NULL; e->rightchild = NULL;
	treenode *f = (treenode *)malloc(sizeof(treenode)); f->val = 'F'; f->leftchild = NULL; f->rightchild = NULL;
	treenode *g = (treenode *)malloc(sizeof(treenode)); g->val = 'G'; g->leftchild = NULL; g->rightchild = NULL;
	treenode *h = (treenode *)malloc(sizeof(treenode)); h->val = 'H'; h->leftchild = NULL; h->rightchild = NULL;
	treenode *i = (treenode *)malloc(sizeof(treenode)); i->val = 'I'; i->leftchild = NULL; i->rightchild = NULL;
	
	a->leftchild = b; a->rightchild = c;
	b->leftchild = d; b->rightchild = e;
	e->leftchild = g; e->rightchild = h;
	c->leftchild = f; f->rightchild = i;
	preorder(a);
	printf("\n");
	inorder(a);
	printf("\n");
	postorder(a);
	return 0;
}
