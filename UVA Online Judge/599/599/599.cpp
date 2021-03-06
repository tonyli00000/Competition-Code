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

using namespace std;

int i, j, k, nodes[30],mat[30],a[2];
bool connected[30][30],used[30];
bool istree;
bool floodfill(int x, int p,int ind,int prev) {
	int i, j, k;
	mat[x] = p;
	used[x] = true;
	for (i = 0; i < ind; i++) {
		if (connected[nodes[x]][nodes[i]]) {
			if (mat[i]==-1 && i!=prev)floodfill(i, p, ind,x);
			else {
				if(i!=prev)
					istree = false;
			}
		}
	}
	return istree;
}
int main()
{
	string line;
	for (i = 0; i < 30; i++) {
		for(j = 0; j < 30; j++) {
			connected[i][j] = false;
		}
	}
	int t;
	cin >> t;
	getline(cin, line);
	for (k = 0; k < t;k++){
		
		for (i = 0; i < 30; i++) {
			for (j = 0; j < 30; j++) {
				connected[i][j] = false;
			}
		}

		while (getline(cin, line)) {
			if (line[0] == '*') {
				getline(cin, line);
				int ind = 0;
				for (i = 0; i < 30; i++) {
					nodes[i] = 0;
					mat[i] = -1;
				}
				for (i = 0; i < line.length(); i++) {
					if ('A' <= line[i] && line[i] <= 'Z') {
						nodes[ind] = line[i] - 'A';
						mat[ind] = -1;
						ind++;
					}
				}
				int p = 1;
				bool l[30];
				for (i = 0; i < 30; i++)l[i] = true;
				for (i = 0; i < ind; i++) {
					if (mat[i] == -1) {
						for (j = 0; j < 30; j++)used[j] = false;
						istree = true;
						if (!floodfill(i, p, ind,-2))l[p] = false;
						p++;
					}
				}
				int acorn = 0, tree = 0;
				for (i = 1; i < p; i++) {
					int ct = 0;
					for (j = 0; j < ind; j++)
						if (mat[j] == i)
							ct++;
					if (ct == 1)acorn++;
					else if(l[i])tree++;
				}
				cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";
				break;
			}
			else {
				bool flag = false;
				for (i = 0; i < line.length(); i++) {
					if ('A' <= line[i] && line[i] <= 'Z' && flag)a[1] = line[i] - 'A';
					if ('A' <= line[i] && line[i] <= 'Z' && !flag) {
						a[0] = line[i] - 'A';
						flag = true;
					}
				}
				connected[a[0]][a[1]] = true;
				connected[a[1]][a[0]] = true;
			}
		}
	}
	return 0;
}
