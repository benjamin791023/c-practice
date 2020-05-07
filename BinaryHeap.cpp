#include <stdio.h>
#include <stdlib.h>
struct keys{
	int key;
	char val;
};

void minheapify(char *heap, int node, int length){
	int left = 2*node;
	int right = 2*node+1;
	int smallest;
	
	if (left <=length && heap[left].key < heap[node].key){
		smallest = left;
	}
	else{
		smallest = node;
	}
	
	if (right <= length && heap[right].key < heap[node].key){
		smallest = right;
	}
	
	if (smallest != node){
		swap(heap[smallest], heap[node]);
		
	}
}

int main(){
	keys *heap = (keys *)malloc(sizeof(keys) * 10);
	(heap+1)->key = 2; (heap+1)->val = 'D';
	(heap+2)->key = 7; (heap+2)->val = 'A';
	(heap+3)->key = 4; (heap+3)->val = 'F';
	(heap+4)->key = 8; (heap+4)->val = 'G';
	(heap+5)->key = 15; (heap+5)->val = 'H';
	(heap+6)->key = 20; (heap+6)->val = 'E';
	(heap+7)->key = 10; (heap+7)->val = 'I';
	(heap+8)->key = 22; (heap+8)->val = 'B';
	(heap+9)->key = 12; (heap+9)->val = 'C';

	
	for (int i=0; i<10; i++){
		printf("%d\n", i );
		printf("%c\n", (heap+i)->val);
	}
	return 0;
}
