#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left, * right;
	Node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

Node* insert(Node* root, int data) {
	if (root == NULL) {
		return new Node(data);
	}
	if (data < root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}

	return root;
}

Node* search(Node* root, int key) {
	if (root == NULL) return NULL;

	if (root->data == key) return root;

	if (key < root->data) return search(root->left, key);

	if (key > root->data) return search(root->right, key);
}

Node* inorderSucc(Node* root) {
	Node* current = root;

	while (current && current->left != NULL)
		current = current->left;

	return current;
}

Node* deleteNode(Node* root, int key) {
	//Finding Node
	if (key < root->data) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->data) {
		root->right = deleteNode(root->right, key);
	}
	//When Node is found
	else {
		//Case 1 and 2
		// Case 1: Node to delete is leaf node : Delete the Node
		//Case 2: Node to delete has one child : Replace node with child & delete the node
		if (root->left == NULL) {
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			Node* temp = root->left;
			free(root);
			return temp;
		}

		//Case 3: Replace node with inorder successor and then delete the node 
		Node* temp = inorderSucc(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

//Binary Search Tree inorder always gives sorted output
void inorder(Node* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main() {
	Node* root = NULL;
	root = insert(root, 5);
	insert(root, 1);
	insert(root, 3);
	insert(root, 4);
	insert(root, 2);
	insert(root, 7);

	inorder(root);
	cout << endl;

	if (search(root, 5) == NULL)
		cout << "Key doesnt exist" << endl;
	else
		cout << "Key exists" << endl;

	deleteNode(root, 5);
	inorder(root);
	cout << endl;

	if (search(root, 5) == NULL)
		cout << "Key doesnt exist" << endl;
	else
		cout << "Key exists" << endl;

	deleteNode(root, 4);
	inorder(root);
	cout << endl;

	if (search(root, 5) == NULL)
		cout << "Key doesnt exist" << endl;
	else
		cout << "Key exists" << endl;
}
