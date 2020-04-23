#include <stdio.h>
#include <stdlib.h>
void printarr(int *arr, int size){
	for(int i=0; i<size; i++){
		printf("%d", arr[i]);
	}
	printf("%d\n");
}

void heapsort(int *arr, int size){
	
}

int main(){
	int size = 6;
	int arr[size] = {6,2,8,3,9,5};
	printarr(arr)
	return 0;
}
