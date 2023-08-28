#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

typedef struct Node node;

void insertFront(node** head, int data) {
	node* newNode = new Node;

	newNode->data = data;
	newNode->next = (*head);
	newNode->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = newNode;

	(*head) = newNode;
}

void insertAfter(node* prev_node, int data) {
	if (prev_node == NULL) {
		cout << "previous node cannot be null;";
		cout << endl;
		return;
	}

	node* newNode = new Node;

	newNode->data = data;
	newNode->next = prev_node->next;

	prev_node->next = newNode;

	newNode->prev = prev_node;

	if (newNode->next != NULL)
		newNode->next->prev = newNode;
}

void insertEnd(node** head, int data) {
	node* newNode = new Node;

	newNode->data = data;

	newNode->next = NULL;

	node* temp = *head;

	if (*head == NULL) {
		newNode->prev = NULL;
		*head = newNode;
		return;
	}

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newNode;

	newNode->prev = temp;
}

void deleteNode(node** head, node* deleteNode) {
	if (*head == NULL || deleteNode == NULL)
		return;

	if (*head == deleteNode)
		*head = deleteNode->next;

	if (deleteNode->next != NULL)
		deleteNode->next->prev = deleteNode->prev;

	if (deleteNode->prev != NULL)
		deleteNode->prev->next = deleteNode->next;

	free(deleteNode);
}

void displayList(node* Node) {
	node* last;

	while (Node != NULL) {
		cout << Node->data << "->";
		last = Node;
		Node = Node->next;
	}
	if (Node == NULL)
		cout << "NULL\n";
}

int main() {
	node* head = NULL;

	insertEnd(&head, 5);
	insertFront(&head, 1);
	insertFront(&head, 6);
	insertEnd(&head, 9);

	insertAfter(head, 11);

	insertAfter(head->next, 15);

	displayList(head);

	deleteNode(&head, head->next->next->next->next->next);

	displayList(head);
}
