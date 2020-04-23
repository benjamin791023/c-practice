#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(int *arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}

void printarr(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main(){
	int size = 6;
	int array[size] = {6,2,8,9,3,5};
	printarr(array, size);
	QuickSort(array, 0, size-1);
	printarr(array, size);
	return 0;
}
