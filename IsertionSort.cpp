#include <stdio.h>
#include <stdlib.h>

void insertionsort(int *arr, int size){
	for (int i=1; i<size; i++){
		int key = arr[i];
		int j = i - 1;
		while (key < arr[j] && j >=0 ){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void printarray(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
}

int main(){
	int array[6] = {5, 3, 1, 2, 6, 4};
	printf("origin\n");
	printarray(array, 6);
	printf("\n");
	
	insertionsort(array, 6);
	printf("sorted \n");
	printarray(array, 6);
	return 0;
}
