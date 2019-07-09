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
#pragma warning(disable:4996)

using namespace std;

vector<string>sequence;
vector<vector<int>>unmatched;
int n, i, j, k;


struct compare {
	bool operator() (const int &a, const int &b) const {
		for (int i = 0; i < n; i++) {
			if (unmatched[i][a] != unmatched[i][b]) {
				return unmatched[i][a] < unmatched[i][b];
			}
		}
		return false;
	}
};
int main(){
	freopen("cbs.in", "r", stdin);
	freopen("cbs.out", "w", stdout);

	cin >> n >> k;
	sequence.resize(n);
	unmatched.resize(n + 1, vector<int>(k + 1, 0));
	for (i = 0; i < n; i++){
		cin >> sequence[i];
		for (j = 1; j < k; j++){
			if(sequence[i][j]=='(')unmatched[i][j] = unmatched[i][j-1] + 1;
			else unmatched[i][j] = unmatched[i][j-1] - 1;
		}
	}

	map<int, int,compare>s; 
	priority_queue<pair<int, int>>pq[15]; //Stores all possible locations for sequence i

	int ct = 0;
	for (i = 0; i < k; i++){
		for (j = 0; j < n; j++){
			while (!pq[j].empty() && pq[j].top().first > unmatched[j][i]){
				s[pq[j].top().second]=0;
				pq[j].pop();
			}
			pq[j].push({ unmatched[j][i], i });
		}
		ct += s[i];
		s[i]++;
	}

	cout << ct << "\n";
	return 0;
}