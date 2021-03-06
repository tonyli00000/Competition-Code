#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int ct;
struct node {
	char c;
	int ct;
	node* left;
	node* right;
	node(char x) : c(x), left(NULL), right(NULL),ct(1) {}
};

string parse(string line) {
	string ret = "";
	for (auto c:line) {
		if ('a' <= c && c <= 'z')ret += (c - ('a' - 'A'));
		if ('A' <= c && c <= 'Z')ret += c;
	}
	return ret;
}

void addNode(node*& root,char c) {
	if (root->c == c) {
		(root->ct)++;
		return;
	}
	if ((root->c) < c) {
		if (!(root->right)) {
			node *n = new node(c);
			root->right = n;
		}
		else addNode(root->right, c);
	}
	else {
		if (!(root->left)) {
			node *n = new node(c);
			root->left = n;
		}
		else addNode(root->left, c);
	}
}

void solve(node* root) {
	if (!root)return;
	if (root->left && !root->right)ct += root->ct;
	if (root->right && !root->left)ct += root->ct;
	solve(root->left);
	solve(root->right);
}

int main() {
	string line;
	for(int k=0;k<5;k++){
		getline(cin, line);
		string s = parse(line);
		node *root=new node(s[0]);
		for (int i = 1; i < s.length(); i++) {
			addNode(root, s[i]);
		}
		ct = 0;
		solve(root);
		cout <<ct << "\n";
	}
	return 0;
}