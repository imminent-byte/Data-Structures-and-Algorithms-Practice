#include <iostream>
using namespace std;

class node {
public:
	int item;
	node* left;
	node* right;
};

node* newNode(int item) {
	node* Node = new node();
	Node->item = item;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

bool checkHeightBalace(node* root, int* height) {
	if (root == NULL)
		return true;

	int leftHeight = 0, rightHeight = 0;

	if (checkHeightBalace(root->left, &leftHeight) == false)
		return false;

	if (checkHeightBalace(root->right, &rightHeight) == false)
		return false;

	*height = max(leftHeight, rightHeight) + 1;
	
	if (abs(leftHeight - rightHeight) <= 1)
		return true;
	else
		return false;
}

int main() {
	int height = 0;

	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	if (checkHeightBalace(root, &height))
		cout << "The tree is balanced";
	else
		cout << "The tree is not balanced";
}
