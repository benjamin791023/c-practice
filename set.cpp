#include <stdio.h>
#include <stdlib.h>

int findsetcollapsing(int *subset, int i){
	int root;
	for (root=i; subset[root] >=0; root=subset[root]);
	
	while(i != root){
		int parent = subset[i];
		subset[i] = root;
		i = parent;
	}
	return root;
}

void unionset(int *subset, int x, int y){
	int xroot = findsetcollapsing(subset, x);
	int yroot = findsetcollapsing(subset, y);
	
	if (subset[xroot] <= subset[yroot]){
		subset[xroot] += subset[yroot];
		subset[yroot] = xroot;
	}else{
		subset[yroot] += subset[xroot];
		subset[xroot] = yroot;
	}
}

int printarray(int *array, int size){
	for (int i=0; i<size; i++){
		printf("%d ", i);
	}
	printf("\n");
	for (int i=0; i<size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(){
	const int size = 6;
	int array[size] = {-1, -1, -1, -1, -1, -1};
	printarray(array, size);
	
	unionset(array, 1, 2);
	printarray(array, size);
	
	unionset(array, 0, 2);
	printarray(array, size);
	
	unionset(array, 3, 5);
	printarray(array, size);
	
	unionset(array, 2, 5);
	printarray(array, size);
	return 0;
}
