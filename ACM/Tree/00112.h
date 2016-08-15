#include <iostream>
#include <string>
#include <sstream>
#include <cstddef>

using namespace std;

struct Node {
	Node() : left(NULL), right(NULL) {}
	~Node() {
		if(left != NULL) delete left;
		if(right != NULL) delete right;
	}

	int data;
	Node *left, *right;
};

const int BALANCE = 0, MISS_LEFT = -1, MISS_RIGHT = 1;
const int INIT = -1;

Node* ToTree(string s, Node *tree = NULL) {
	// test
	//cout << s << endl;

	int numLeft = 0;
	for(int i = 0; i < s.length() && numLeft < 2; i++)
		if(s[i] == '(') numLeft++;
	if(numLeft < 2) return tree;

	tree = new Node;

	int start, end;
	for(start = 0; s[start] != '('; start++);
	start++;
	stringstream ss;
	for(end = start; s[end] != '('; end++);
	ss << s.substr(start, end - start);
	ss >> tree->data;

	start = INIT;
	int stat = BALANCE;
	bool branchIsLeft = true;
	for(int i = end; i < s.length(); i++) {
		switch(s[i]) {
		case '(':
			if(start == INIT) start = i;
			stat += MISS_RIGHT;
			break;
		case ')':
			stat += MISS_LEFT;
			if(stat == BALANCE) end = i;
			break;
		}
		if(s[i] != ' ') {
			if(stat == BALANCE) {
				if(branchIsLeft) tree->left = ToTree(s.substr(start, end - start + 1)), branchIsLeft = false, start = INIT;
				else tree->right = ToTree(s.substr(start, end - start + 1));
			}
		}
	}
	return tree;
}

bool HasSum(Node *tree, int checkSum, int curSum = 0, bool added = false) {
	if(tree == NULL) return (checkSum == curSum) && added;

	curSum += tree->data, added = true;
	return HasSum(tree->left, checkSum, curSum, added) || HasSum(tree->right, checkSum, curSum, added);
}

int main() {
	string s, input;
	int numLeft = 0, numRight = 0;
	while(getline(cin, s)) {
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '(') numLeft++;
			else if(s[i] == ')') numRight++;
		}
		input += s;
		if(numLeft == numRight && numLeft > 0) {
			stringstream ss;
			ss << input;
			int sum;
			ss >> sum;
			getline(ss, input);

			Node *tree = ToTree(input);
			if(HasSum(tree, sum))
				cout << "yes" << endl;
			else
				cout << "no" << endl;

			input.clear();
			s.clear();
			numLeft = 0, numRight = 0;
		}
	}
}
