#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
}; 

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(node));

	node->data = data;

	node->left = NULL;
	node->right = NULL;
	return (node);
}

void traversePreOrder(Node* temp) {
	if (temp != NULL) {
		cout << " " << temp->data;
		traversePreOrder(temp->left);
		traversePreOrder(temp->right);
	}
}

// Traverse Inorder
void traverseInOrder(Node* temp) {
	if (temp != NULL) {
		traverseInOrder(temp->left);
		cout << " " << temp->data;
		traverseInOrder(temp->right);
	}
}

// Traverse Postorder
void traversePostOrder(Node* temp) {
	if (temp != NULL) {
		traversePostOrder(temp->left);
		traversePostOrder(temp->right);
		cout << " " << temp->data;
	}
}

int main() {
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);

	cout << "preorder traversal: ";
	traversePreOrder(root);
	cout << "\nInorder traversal: ";
	traverseInOrder(root);
	cout << "\nPostorder traversal: ";
	traversePostOrder(root);
}
