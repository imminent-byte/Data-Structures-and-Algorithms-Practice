#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};

typedef struct Node node;

void insertAtBeginning(node** head_ref, int new_data) {
	//Allocating memory
	node* newNode = (node*)malloc(sizeof(node));

	//inserting the data
	newNode->data = new_data;
	newNode->next = (*head_ref);

	//Moving head to new node
	(*head_ref) = newNode;
}

void insertAfter(node* prev_node, int new_data) {
	if (prev_node == NULL) {
		cout << "The given previous node cannot be NULL\n";
		return;
	}

	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = new_data;
	newNode->next = prev_node->next;
	prev_node->next = newNode;
}

void insertEnd(node** head_ref, int new_data) {
	node* newNode = (node*)malloc(sizeof(node));
	node* last = *head_ref;

	newNode->data = new_data;
	newNode->next = NULL;

	if (*head_ref == NULL) {
		*head_ref = newNode;
		return;
	}

	while (last->next != NULL) last = last->next;

	last->next = newNode;
	return;
}

void deleteNode(node** head_ref, int key) {
	node* temp = *head_ref;
	node* prev;

	if (temp != NULL && temp->data == key) {
		*head_ref = temp->next;
		free(temp);
		return;
	}

	node* current = *head_ref;
	while (current->next != NULL) {
		if (current->next->data == key) {
			temp = current->next;
			current->next = current->next->next;
			free(temp);
			break;
		}
		else {
			current = current->next;
		}
	}
}

bool searchNode(node** head_ref, int key) {
	node* current = *head_ref;

	while (current != NULL) {
		if (current->data == key) return true;
		current = current->next;
	}
	return false;
}

void sortLinkedList(node** head_ref) {
	node* current = *head_ref, * index = NULL;
	int temp;

	if (head_ref == NULL) {
		return;
	}
	else {
		while (current != NULL) {
			//index points to the node next to current
			index = current->next;

			while (index != NULL) {
				if (current->data > index->data) {
					temp = current->data;
					current->data = index->data;
					index->data = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

void printLinkedList(node* node) {
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

int main() {
	node* head = NULL;

	insertEnd(&head, 1);
	insertAtBeginning(&head, 2);
	insertAtBeginning(&head, 3);
	insertEnd(&head, 4);
	insertAfter(head->next, 5);

	cout << "Linked list: ";
	printLinkedList(head);

	cout << "\nAfter deleting an element: ";
	deleteNode(&head, 5);
	printLinkedList(head);

	int item_to_find = 5;
	if (searchNode(&head, item_to_find)) {
		cout << endl << item_to_find << " is found";
	}
	else {
		cout << endl << item_to_find << " is not found";
	}

	sortLinkedList(&head);
	cout << "\nSorted List: ";
	printLinkedList(head);
}
