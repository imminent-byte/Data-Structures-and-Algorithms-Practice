#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void traverse(struct Node* last) {
	struct Node* p;

	if (last == NULL) {
		cout << "The list is empty" << endl;
		return;
	}

	p = last->next;

	do {
		cout << p->data << " ";
		p = p->next;
	} while (p != last->next);
}

typedef struct Node node;

int main() {
	node* Head;
	node* one = new Node;
	node* two = new Node;
	node* three = new Node;
	node* four = new Node;

	one->data = 1;
	two->data = 2;
	three->data = 3;
	four->data = 4;

	one->next = two;
	two->next = three;
	three->next = four;
	four->next = one;

	Head = one;

	traverse(four);
}

