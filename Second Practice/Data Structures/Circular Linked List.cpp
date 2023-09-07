#include <iostream>
using namespace std;

class Node {
public: 
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next = NULL;
	}
};

void insertAtStart(Node** head, int data) {
	Node* newNode = new Node(data);

	if (*head == NULL) {
		newNode->next = newNode;
		*head = newNode;
		return;
	}

	Node* temp = *head;

	//changing the next of last node to point at the new node
	while (temp->next != *head) {
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->next = *head;
	*head = newNode;
}

void insertAtEnd(Node** head, int data) {
	if (*head == NULL) {
		insertAtStart(head, data);
		return;
	}

	Node* newNode = new Node(data);
	Node* temp = *head;

	while (temp->next != *head) temp = temp->next;

	temp->next = newNode;
	newNode->next = *head;
}

void deleteAtHead(Node*& head) {
	Node* temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}

	Node* todelete = head;
	temp->next = head->next;
	head = head->next;

	delete todelete;
}

void deletion(Node** head, int pos) {
	if (pos == 1) {
		deleteAtHead(*head);
		return;
	}

	Node* temp = *head;
	int count = 1;

	while (count != pos - 1) {
		temp = temp->next;
		count++;
	}

	Node* todelete = temp->next;
	temp->next = temp->next->next;

	delete todelete;
}

void display(Node* head) {
	Node* temp = head;

	//Didn't use while loop here because if the condition gets true we wont get to last element
	do {
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
	cout << endl;
}

bool searchNode(Node** head, int key) {
	Node* current = *head;

	do {
		if (current->data == key) return true;
		current = current->next;
	} while (current != *head);
	return false;
}

int main() {
	Node* head = NULL;
	insertAtEnd(&head, 1);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 3);
	insertAtEnd(&head, 4);
	display(head);
	insertAtStart(&head, 5);
	display(head);

	int item_to_find = 4;
	if (searchNode(&head, item_to_find)) {
		cout << endl << item_to_find << " is found";
	}
	else {
		cout << endl << item_to_find << " is not found";
	}

}
