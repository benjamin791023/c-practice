#include <stdio.h>
#include <stdlib.h>
#define num_vertex 9

struct queuenode{
	int ind;
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
		list->front->ind = x;
		list->front->next = NULL;
		list->back = list->front;
		list->size++;
		return;
	}
	queuenode *tmp = (queuenode *)malloc(sizeof(queuenode));
	tmp->ind = x;
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
		return NULL;
	}
	return list->front->ind;
}

int getback(queuelist *list){
	if (isempty(list)){
		printf("no data, cannot get back");
		return NULL;
	}
	return list->back->ind;
}

void bfs(int **adjlist, int start){
	int color[num_vertex];
	int predecessor[num_vertex];
	int distance[num_vertex];
	for (int i=0; i<num_vertex; i++){
		color[i] = 0;
		predecessor[i] = -1;
		distance[i] = num_vertex + 1;
	}
	
	int i = start;
	
	queuelist *q = (queuelist *)malloc(sizeof(queuelist));
	q->size=0;
	for (int j=0; j<num_vertex; j++){
		if (color[i] == 0){
			color[i] = 1;
			distance[i] = 0;
			predecessor[i] = -1;
			push(q, i);
			while (!isempty(q)){
				int u = getfront(q);
				printf("aa%d\t", u);
				printf("size%d\n", sizeof(adjlist));
				for (int k=0; k<sizeof(adjlist[u]) / sizeof(int); k++){
					printf("%d", adjlist[u][k]);
					if (color[adjlist[u][k]] == 0){
						color[adjlist[u][k]] = 1;
						distance[adjlist[u][k]] = distance[u] + 1;
						predecessor[adjlist[u][k]] = u;
						push(q, adjlist[u][k]);
					}
				}
				printf("\n");
				pop(q);
				color[u] = 2;
			}
		}
		i = j;
	}
	
	for (int i=0; i<num_vertex; i++){
		printf("%d", predecessor[i]);
	}
}


int main(){
	int **adjlist = (int **)malloc(sizeof(int *) * 9);
	int a[3] = {1,2,3};
	adjlist[0] = (int *)a;
	int b[2] = {0, 4};
	adjlist[1] = (int *)b;
	int c[5] = {0, 4, 5, 6, 7};
	adjlist[2] = (int *)c;
	int d[2] = {0, 7};
	adjlist[3] = (int *)d;
	int e[3] = {1, 2, 5};
	adjlist[4] = (int *)e;
	int f[3] = {2, 4, 8};
	adjlist[5] = (int *)f;
	int g[3] = {2,7, 8};
	adjlist[6] = (int *)g;
	int h[3] = {2, 3, 6};
	adjlist[7] = (int *)h;
	int i[2] = {5, 6};
	adjlist[8] = (int *)i;
	printf("%d\n",sizeof(adjlist));
	
	bfs(adjlist, 0);
	
	return 0;
}
