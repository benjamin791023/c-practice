#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
struct treenode{
	treenode *leftchild;
	treenode *rightchild;
	treenode *parent;
	char data;
	int key;
};

treenode *search(treenode *current, int key){
	treenode *tmp = current;
	while(tmp && tmp->key !=key){
		if (key < tmp->key){
			tmp = tmp->leftchild;
		}
		else if(key > tmp->key){
			tmp = tmp->rightchild;
		}
	}
	return tmp;
}

void insert(treenode *current, char string, int key){
	treenode *x = NULL;
	treenode *y = NULL;
	treenode *in = (treenode *)malloc(sizeof(treenode)); in->leftchild = NULL; in->rightchild = NULL; in->data = string; in->key = key;
	x = current;
	while(x != NULL){
		y = x;
		if (in->key < x->key){
			x = x->leftchild;
		}
		else{
			x = x->rightchild;
		}
	}
	
	in->parent = y;
	if (y == NULL){
		current = in;
	}
	else if(in->key < y->key){
		y->leftchild = in;
	}
	else{
		y->rightchild = in;
	}
}

void traverse(treenode *current){
	if (current){
		printf("%c, %d\n", current->data, current->key);
		traverse(current->leftchild);
		traverse(current->rightchild);
	}
}

void delete_node(treenode *current, int key){
	
}

int main(){
	treenode *uko = (treenode *)malloc(sizeof(treenode)); uko->leftchild = NULL; uko->rightchild = NULL; uko->data = 'u'; uko->key = 1000;
	treenode *ki = (treenode *)malloc(sizeof(treenode)); ki->leftchild = NULL; ki->rightchild = NULL; ki->data = 'k'; ki->key = 627;
	treenode *fo = (treenode *)malloc(sizeof(treenode)); fo->leftchild = ki; fo->rightchild = uko; fo->data='f'; fo->key = 709;
	ki->parent = fo; uko->parent = fo;
	treenode *li = (treenode *)malloc(sizeof(treenode)); li->leftchild = NULL; li->rightchild = NULL; li->data='l'; li->key=514;
	treenode *da = (treenode *)malloc(sizeof(treenode)); da->leftchild = li; da->rightchild = fo; da->data = 'd'; da->key=524;
	li->parent = da; fo->parent=da;
	treenode *ti = (treenode *)malloc(sizeof(treenode)); ti->leftchild = NULL; ti->rightchild = NULL; ti->data = 't'; ti->key=43;
	treenode *uf = (treenode *)malloc(sizeof(treenode)); uf->leftchild = ti; uf->rightchild = NULL; uf->data = 'U'; uf->key = 79;
	ti->parent = uf;
	treenode *ku = (treenode *)malloc(sizeof(treenode)); ku->leftchild = NULL; ku->rightchild = uf; ku->data = 'K'; ku->key = 8;
	uf->parent = ku;
	treenode *pi = (treenode *)malloc(sizeof(treenode)); pi->leftchild = ku; pi->rightchild = da; pi->data = 'p'; pi->key = 513;
	ku->parent = pi; da->parent=pi;
	treenode *root = pi;
	treenode *a = search(root, 513);
	treenode *in = (treenode *)malloc(sizeof(treenode)); in->leftchild = NULL; in->rightchild = NULL; in->data = 'i'; in->key = 51;
	
	treenode *to_uk = (treenode *)malloc(sizeof(treenode)); to_uk->leftchild = NULL; to_uk->rightchild = NULL; to_uk->data = 'u'; to_uk->key=1000; 
	treenode *to_kl = (treenode *)malloc(sizeof(treenode)); to_kl->leftchild = NULL; to_kl->rightchild = NULL; to_kl->data = 'l'; to_kl->key=8;
	treenode *to_ku = (treenode *)malloc(sizeof(treenode)); to_ku->leftchild = to_kl; to_ku->rightchild = to_uk; to_ku->data = 'K'; to_ku->key=2;
	to_kl->parent = to_ku; to_uk->parent = to_ku;
	treenode *to_pi = (treenode *)malloc(sizeof(treenode)); to_pi->leftchild = NULL; to_pi->rightchild = NULL; to_pi->data = 'p'; to_pi->key=513;
	root = to_ku;
	traverse(root);
	printf("\n"); 
	insert(root, 'p', 513);
	traverse(root);
	return 0;
}
