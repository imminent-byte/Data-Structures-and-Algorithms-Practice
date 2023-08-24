#include<stdlib.h>
#include<iostream>

using namespace std;

#define MAX 10
int size = 0;

struct stack {
	int items[MAX];
	int top;
};

typedef struct stack st;

void createEmptyStack(st* s) {
	s->top = -1;
}

int isFull(st* s) {
	if (s->top == MAX - 1)
		return 1;
	else
		return 0;
}

int isEmpty(st* s) {
	if (s->top == -1)
		return 1;
	else
		return 0;
}


void push(st* s, int element) {
	if (isFull(s)) {
		cout << "FULL STACLK";
	}
	else {
		s->top++;
		s->items[s->top] = element;
	}
	::size++;

}

void pop(st* s) {
	if (isEmpty(s)) {
		cout << "\nEMPTY STACK\n";
	}
	else {
		cout << "Element Popped is: " << s->items[s->top];
		s->top--;
	}
	::size--;
	cout << endl;
}

void printStack(st* s) {
	for (int i = 0; i < ::size; i++) {
		cout << s->items[i] << " ";
	}
	cout << endl;
}

int main() {
	st* s = (st*)malloc(sizeof(st));

	createEmptyStack(s);

	push(s, 12);
	push(s, 1);
	push(s, 13);
	push(s, 2);
	push(s, 5);

	printStack(s);

	pop(s);

	cout << "Stack after popping\n";
	printStack(s);
}
