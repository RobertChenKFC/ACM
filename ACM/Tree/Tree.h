#include <iostream>
#include <cstddef>

using namespace std;

// Binary Tree Node
template <class T>
struct Node {
	Node(int d) : data(d), left(NULL), right(NULL) {}
	~Node() {
		if(left != NULL) delete left;
		if(right != NULL) delete right;
	}

	T data;
	Node *left, *right;
};

template <class T>
void Preorder(Node<T> *tree) {
	if(tree != NULL) {
		cout << tree->data << " ";
		Preorder(tree->left);
		Preorder(tree->right);
	}
}

template <class T>
void Inorder(Node<T> *tree) {
	if(tree != NULL) {
		Inorder(tree->left);
		cout << tree->data << " ";
		Inorder(tree->right);
	}
}

template <class T>
void Postorder(Node<T> *tree) {
	if(tree != NULL) {
		Postorder(tree->left);
		Postorder(tree->right);
		cout << tree->data << " ";
	}
}

int main() {
	// first level
	Node<int> *tree = new Node<int>(1);
	// second level
	tree->left = new Node<int>(2), tree->right = new Node<int>(3);
	// third level
	tree->left->left = new Node<int>(4), tree->left->right = new Node<int>(5);
	tree->right->left = new Node<int>(6), tree->right->right = new Node<int>(7);
	// foruth level
	tree->left->left->left = new Node<int>(8), tree->left->left->right = new Node<int>(9);
	tree->left->right->left = new Node<int>(10), tree->left->right->right = new Node<int>(11);
	tree->right->left->left = new Node<int>(12), tree->right->left->right = new Node<int>(13);
	tree->right->right->left = new Node<int>(14), tree->right->right->right = new Node<int>(15);

	// preorder (root, left, right)
	cout << "Preorder: " << endl;
	Preorder(tree);
	cout << endl << endl;

	// Inorder (left, root, right)
	cout << "Inorder: " << endl;
	Inorder(tree);
	cout << endl << endl;

	// Postorder (left, right, root)
	cout << "Postorder: " << endl;
	Postorder(tree);
	cout << endl << endl;

	delete tree;
}
