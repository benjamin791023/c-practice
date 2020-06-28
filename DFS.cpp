#include <stdio.h>
#include <stdlib.h>
#define vertex_num 8
int color[vertex_num];
int discover[vertex_num];
int finish[vertex_num];
int predecessor[vertex_num];

void traverse(int *finish, int *perdecessor, int *sizea){
	for (int i=0; i<vertex_num; i++){
		printf("predecessor %d, finish %d\n", predecessor[i], finish[i]);
	}
}

void DFSvisit(int **adjlist, int i, int *time, int *sizea){
	color[i] = 1;
	discover[i] = ++*time;
	for (int j=0; j<sizea[i]; j++){
		if (color[adjlist[i][j]] == 0){
			predecessor[adjlist[i][j]] = i;
			DFSvisit(adjlist, adjlist[i][j], time, sizea);
		}
	}
	color[i] = 2;
	finish[i] = ++*time;
}

void DFS(int **adjlist, int start, int *sizea){
	
	int time = 0;
	for (int i=0; i<vertex_num; i++){
		color[i] = 0;
		discover[i] = 0;
		finish[i] = 0;
		predecessor[i] = -1;
	}
	
	int i = start;
	for (int j=0; j<vertex_num; j++){
		if (color[i] == 0){
			DFSvisit(adjlist, i, &time, sizea);
		}
		i = j;
	}
	traverse(finish, predecessor, sizea);
}

int main(){
	int **adjlist = (int **)malloc(sizeof(int*) * 9);
	int a[2] = {1, 2};
	adjlist[0] = a;
	int b[1] = {3};
	adjlist[1] = b;
	int c[2] = {1,5};
	adjlist[2] = c;
	int d[2] = {4, 5};
	adjlist[3] = d;
	int f[1] = {1};
	adjlist[5] = f;
	int g[2] = {4, 7};
	adjlist[6] = g;
	int h[1] = {6};
	adjlist[7] = h;
	int sizea[8] = {2,1,2,2,0,1,2,1};
	DFS(adjlist, 0, sizea);
	return 0;
}
