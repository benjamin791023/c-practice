#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define a 0.6180339887
#define ini_size 8
struct node{
	int key;
	char val[];
	node *next;
};

struct hashtable{
	int size;
	int count;
	node **table;
};

int hashfunction(int size, int key){
	double frac = key * a - floor(key * a);
	return floor(size * frac);
}

void rehashing(hashtable *table, int size){
	node **newtable = (node **)malloc(sizeof(*node) * table->size);
	for (int i=0; i<size; i++){
		newtable[i] = 0;
	}
	
	for (int i=0; i<ori_size; i++){
		node *ori_current = table->table[i];
		node *ori_next = NULL;
		
		while (ori_current != NULL){
			ori_next = ori_current->next;
			int index = hashfunction(ori_current->key);
			if (newtable[i] == NULL){
				newtable[i] = ori_current;
			}
			else{
				node *next = newtable[i]->next;
				newtable->next = ori_current;
				ori_current->next = next;
			}
			ori_current = ori_next;
		}
	}
	free(table->table);
	table->table = newtable; 
}

void tabledoubling(hashtable *table){
	int ori_size = table->size;
	table->size *= 2;
	rehashing(table, ori_size);
}

void tableshrinking(hashtable *table){
	int ori_size = table->size;
	table->size /= 2;
	rehashing(table, ori_size);
}

void insert(hashtable *table, node *data){
	table->count++;
	int count = table->count;
	int size = table->size;
	if (count > size){
		tabledoubling(table);
	}
	int index = hashfunction(size, data->key);
	if (table->table[index] == NULL){
		table->table[index] = data;
	}
	else{
		node *next = table->table[index]->next;
		table->table[index] = data;
		data->next = next;
	}
}

void delete(hashtable* table, int key){
	int index = hashfunction(key);
	node *current = table->table[index];
	previous = NULL;
	
	while (current != NULL && current->key != key){
		prevoius = current;
		current = current->next;
	}
	
	if (current == NULL){
		printf(" data %d not found", key);
	}
	else{
		if(previous == NULL){
			table->table[index] = current->next;
		}
		else{
			previous->next = current->next;
		}
		free(current);
	}
	table->count--;
	if (table->count < table->size / 4){
		shrinktable(table);
	}
}


int main(){
	hashtable *hash = (hashtable *)malloc(sizeof(hashtable));
	hash->size = ini_size;
	hash->count = 0;
	return 0;
}
