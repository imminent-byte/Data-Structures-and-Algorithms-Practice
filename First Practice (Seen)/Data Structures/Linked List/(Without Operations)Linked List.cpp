#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

typedef struct Node node;

int main() {
	node* HEAD;
	node* one = NULL;
	node* four = NULL;
	node* two = NULL;
	node* three = NULL;

	one = (node*)malloc(sizeof(node));
	four = (node*)malloc(sizeof(node));
	two = (node*)malloc(sizeof(node));
	three = (node*)malloc(sizeof(node));

	one->data = 1;
	four->data = 4;
	two->data = 2;
	three->data = 3;

	one->next = four;
	four->next = two;
	two->next = three;
	three->next = NULL;

	HEAD = one;

	while (HEAD != NULL) {
		cout << HEAD->data << " ";
		HEAD = HEAD->next;
	}
}
