#include <iostream>
using namespace std;

class Node {
public:
	int key;
	Node* left;
	Node* right;
};

Node* newNode(char k) {
	Node* node = (Node*)malloc(sizeof(Node));

	node->key = k;
	node->right = node->left = NULL;
	return node;
}

bool isFullBinaryTree(Node* root) {
	//If the tree is empty
	if (root == NULL)
		return true;

	//Checking for the presence of children
	if (root->left == NULL && root->right == NULL)
		return true;

	if ((root->left) && (root->right))
		return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

	return false;
}

int main() {
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);
	root->left->right->right = newNode(7);

	if (isFullBinaryTree(root))
		cout << "The tree is a full binary tree\n";
	else
		cout << "The tree is not a full binary tree\n";
}
