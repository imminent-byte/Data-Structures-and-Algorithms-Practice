#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;

	node(int val) {
		data = val;
		next = NULL;
	}
};

void insertAtBeginning(node*& head, int data) {
	node* newNode = new node(data);

	if (head == NULL) {
		newNode->next = newNode;
		head = newNode;
		return;
	}

	node* temp = head;

	while (temp->next != head) {
		temp = temp->next;
	}
	
	temp->next = newNode;
	newNode->next = head;
	head = newNode;
}

void insertAtEnd(node*& head, int data) {
	if (head == NULL) {
		insertAtBeginning(head, data);
		return;
	}

	node* newNode = new node(data);
	node* temp = head;

	while (temp->next != head) temp = temp->next;

	temp->next = newNode;
	newNode->next = head;
}

void deleteAtHead(node*& head) {
	node* temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}

	node* todelete = head;
	temp->next = head->next;
	head = head->next;

	delete todelete;
}

void deletion(node*& head, int pos) {
	if (pos == 1) {
		deleteAtHead(head);
		return;
	}

	node* temp = head;
	int count = 1;

	while (count != pos - 1) {
		temp = temp->next;
		count++;
	}

	node* todelete = temp->next;
	temp->next = temp->next->next;

	delete todelete;
}

void display(node* head) {
	node* temp = head;

	//Didn't use while loop here because if the condition gets true we wont get to last element
	do {
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != head);
	cout << endl;
}

bool searchNode(node*& head, int key) {
	node* current = head;

	do {
		if (current->data == key) return true;
		current = current->next;
	} while (current != head);
	return false;
}

int main() {
	node* head = NULL;
	insertAtEnd(head, 1);
	insertAtEnd(head, 2);
	insertAtEnd(head, 3);
	insertAtEnd(head, 4);
	display(head);
	insertAtBeginning(head, 5);
	display(head);

	int item_to_find = 4;
	if (searchNode(head, item_to_find)) {
		cout << endl << item_to_find << " is found";
	}
	else {
		cout << endl << item_to_find << " is not found";
	}

}
