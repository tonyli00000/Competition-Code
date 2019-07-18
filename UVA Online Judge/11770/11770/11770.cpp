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

using namespace std;

stack<long> st;
vector<long> adjList[100010];
bool visited[100010];


void dfs2(long index) {
	visited[index] = true;
	for (long j = 0; j<adjList[index].size(); j++) {
		if (!visited[adjList[index][j]]) {
			dfs2(adjList[index][j]);
		}
	}
}

void dfs(long index) {
	visited[index] = true;
	for (long j = 0; j<adjList[index].size(); j++) {
		if (!visited[adjList[index][j]]) {
			dfs(adjList[index][j]);
		}
	}
	st.push(index);
}


int main() {
	int tc;
	cin >> tc;
	for (int k = 0; k < tc;k++) {

		long n, m;
		cin >> n >> m;
		for (long i = 0; i <= n; i++) {
			visited[i] = false;
		}
		for (long i = 0; i<m; i++) {
			long a, b;
			cin >> a >> b;
			adjList[a].push_back(b);
		}

		for (long i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		for (long i = 0; i <= n; i++)
			visited[i] = false;
		long count = 0;
		while (!st.empty()) {
			long index = st.top();
			st.pop();
			if (!visited[index]) {
				count++;
				dfs2(index);
			}
		}

		cout <<"Case "<<k+1<<": "<< count << "\n";
		for (int i = 1; i <= n; i++) {
			adjList[i].clear();
		}
	}
	return 0;
}