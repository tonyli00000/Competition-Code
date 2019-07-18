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
#define k 2


using namespace std;

set<pair<int, int>>r_search;
pair<int, int>q;
struct Node
{
	int point[k];
	Node *left, *right;
};
long long dist(int x1, int y1, int x2, int y2){
	return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}
struct Node* newNode(int arr[]){
	struct Node* temp = new Node;
	for (int i = 0; i<k; i++)
		temp->point[i] = arr[i];
	temp->left = temp->right = NULL;
	return temp;
}

Node *insert(Node *root, int point[], int depth){
	if (root == NULL)
		return newNode(point);
	int cd = depth % k;
	if (point[cd] < (root->point[cd]))
		root->left = insert(root->left, point, depth + 1);
	else root->right = insert(root->right, point, depth + 1);

	return root;
}


bool same(int point1[], int point2[])
{
	for (int i = 0; i < k; ++i)
		if (point1[i] != point2[i])
			return false;

	return true;
}

bool search(Node* root, int point[], int depth)
{
	if (root == NULL)
		return false;
	if (same(root->point, point))
		return true;
	int cd = depth % k;
	if (point[cd] < root->point[cd])
		return search(root->left, point, depth + 1);
	return search(root->right, point, depth + 1);
}
void RangeSearch(Node* root, int depth, int x, int y, int xm, int ym){
	if (root == NULL)
		return;
	if (x <= root->point[0] && root->point[0] <= xm && y <= root->point[1] && root->point[1] <= ym){
		r_search.insert(make_pair(root->point[0], root->point[1]));
		//cout << root->point[0] << " " << root->point[1] << "\n";
		RangeSearch(root->left, depth + 1, x, y, xm, ym);
		RangeSearch(root->right, depth + 1, x, y, xm, ym);
	}
	int cd = depth % k;
	if (cd){
		if (ym < root->point[cd])RangeSearch(root->left, depth + 1, x, y, xm, ym);
		else RangeSearch(root->right, depth + 1, x, y, xm, ym);
	}
	else{
		if (xm<root->point[cd])RangeSearch(root->left, depth + 1, x, y, xm, ym);
		else RangeSearch(root->right, depth + 1, x, y, xm, ym);
	}
	return;
}
void NearestNeighbor(Node* root, int point[], int depth, Node* best, long long bestd){
	if (!root)return;
	long long d = dist(root->point[0], root->point[1], point[0], point[1]);
	if (!best && d < bestd){
		bestd = d;
		best = root;
	}
	int cd = depth % k;
	int dx = root->point[cd] - point[cd];
	int y = dx * dx;
	if (dx > 0)NearestNeighbor(root->left, point, depth + 1, best, bestd);
	else NearestNeighbor(root->right, point, depth + 1, best, bestd);
	if (y >= bestd)return;
	if (dx>0)NearestNeighbor(root->right, point, depth + 1, best, bestd);
	else NearestNeighbor(root->left, point, depth + 1, best, bestd);
	q = make_pair(best->point[0], best->point[1]);
}


int main()
{
	struct Node *root = NULL;
	int points[][k] = { { 3, 6 }, { 17, 15 }, { 13, 15 }, { 6, 12 },
	{ 9, 1 }, { 2, 7 }, { 10, 19 } };

	int n = sizeof(points) / sizeof(points[0]);

	for (int i = 0; i<n; i++)
		root = insert(root, points[i],0);

	//range search
	r_search.clear();
	RangeSearch(root, 0, 1, 2, 20, 20);
	for (auto it = r_search.begin(); it != r_search.end(); it++){
		cout << it->first << " " << it->second << "\n";
	}
	cout << "\n";

	//nearest neighbor
	int point1[] = { 5, 5 };
	Node* best = NULL;
	long long bestd = 1000000000000;
	NearestNeighbor(root, point1, 0, best, bestd);
	cout << q.first << " " << q.second << "\n\n";

	//searching
	int point2[] = { 10, 19 };
	if (search(root, point2, 0))cout << "Found\n";
	else cout << "Not Found\n";
	cout << "\n";

	int point3[] = { 12, 19 };
	if (search(root, point3, 0))cout << "Found\n";
	else cout << "Not Found\n";

	return 0;
}