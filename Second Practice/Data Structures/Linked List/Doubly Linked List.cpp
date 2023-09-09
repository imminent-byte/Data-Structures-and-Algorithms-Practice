#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

typedef struct Node node;

void insertAtBeginning(node** head_ref, int new_data) {
	node* newNode = (node*)malloc(sizeof(node));

	newNode->data = new_data;
	newNode->next = (*head_ref);
	newNode->prev = NULL;

	if ((*head_ref) != NULL)
		(*head_ref)->prev = newNode;

	(*head_ref) = newNode;
}

void insertAfter(node* prev_node, int new_data) {
	if (prev_node == NULL) {
		cout << "the given previous node cannot be NULL\n";
		return;
	}

	node* newNode = (node*)malloc(sizeof(node));

	newNode->data = new_data;
	newNode->next = prev_node->next;
	prev_node->next = newNode;

	newNode->prev = prev_node;

	if (newNode->next != NULL)
		newNode->next->prev = newNode;
}

void insertEnd(node** head_ref, int new_data) {
	node* newNode = (node*)malloc(sizeof(node));

	newNode->data = new_data;
	newNode->next = NULL;

	node* last = *head_ref;

	if (*head_ref == NULL) {
		newNode->prev = NULL;
		*head_ref = newNode;
		return;
	}

	while (last->next != NULL) last = last->next;

	last->next = newNode;
	newNode->prev = last;
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


void printLinkedList(node* node) {
	while (node != NULL) {
		cout << node->data << "->";
		node = node->next;
	}
	if (node == NULL)
		cout << "NULL\n";
}

int main() {
	node* head = NULL;

	insertEnd(&head, 5);
	insertAtBeginning(&head, 1);
	insertAtBeginning(&head, 6);
	insertEnd(&head, 9);

	insertAfter(head, 11);

	insertAfter(head->next, 15);

	printLinkedList(head);

	deleteNode(&head, head->next->next->next->next->next);

	printLinkedList(head);
}
