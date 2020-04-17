#include <stdio.h>
#include <stdlib.h>

struct StackArray {
	int capacity;
	int top;
	int *stack;
};

void DoubleCapacity(StackArray *sa){
	sa->capacity = sa->capacity * 2;
	int stack[sa->capacity];
	int *newstack = stack;
	for (int i=0; i<sa->capacity/2; i++){
		newstack[i] = sa->stack[i];
	}
	sa->stack = newstack;
}

bool isempty(StackArray *sa){
	return sa->top == -1;
}

int top(StackArray *sa){
	if (isempty(sa)){
		printf("Stack is empty");
		return -1;
	}
	return sa->stack[sa->top];
}

int getSize(StackArray *sa){
	return sa->top+1;
}

int main(){
	StackArray *stack = (StackArray *)malloc(sizeof(StackArray));
	stack->capacity = 1;
	stack->top = -1;
	DoubleCapacity(stack);
	printf("123");
	printf("%d", stack->capacity);
	int b;
	b = getSize(stack);
	printf("%d", b);
	return 0;
}
