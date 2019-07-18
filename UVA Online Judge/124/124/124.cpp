//#include <iostream>
//#include <string>
//#include <sstream>
//#include <iomanip> 
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <vector>
//#include <map>
//#include <set>
//#include <functional>
//#include <algorithm>
//
//using namespace std;
//
//char seq[25];
//int tup[25];
//bool in[124];
//bool cons[124][124];
//int N;
//
//
//bool isok(int d) {
//	for (int i = 0; i < d; i++)
//		if (cons[seq[tup[d]]][seq[tup[i]]])
//			return false;
//	return true;
//}
//void bkt(int depth) {
//	//printf("%d\n", depth);
//
//	if (!isok(depth))return;
//	if (depth == N - 1) {
//		for (int i = 0; i < N; i++)putchar(seq[tup[i]]);
//		puts("");
//		return;
//	}
//	for (int i = 0; i < N; i++) {
//		if (in[seq[i]] == false) {
//			in[seq[i]] = true;
//			tup[depth + 1] = i;
//			bkt(depth + 1);
//			in[seq[i]] = false;
//		}
//	}
//}
////void dfs(int u) {
////	p[u] = true;
////	for (int j = 0; j < Adj[u].size(); j++) {
////		if (!p[Adj[u][j]])dfs(Adj[u][j]);
////	}
////	ts.push_back(u);
////}
////void solve(int n,int u) {
////	dfs(u);
////	//solution += c;
////	if (ts.size()==n) {
////		for (int i = ts.size()-1; i >= 0; i--) {
////			if (i != ts.size()-1)cout << " ";
////			cout << node[ts[i]];
////		}
////		cout << "\n";
////		return;
////	}
////	int i;
////	for (i = 0; i < n; i++) {
////		if (!p[i])solve(n,i);
////	}
////}
#include <string.h>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>


bool isok(int d) {
	for (int i = 0; i < d; i++)
		if (cons[seq[tup[d]]][seq[tup[i]]])
			return false;
	return true;
}
void bkt(int depth) {
	//printf("%d\n", depth);

	if (!isok(depth))return;
	if (depth == N - 1) {
		for (int i = 0; i < N; i++)putchar(seq[tup[i]]);
		puts("");
		return;
	}
	for (int i = 0; i < N; i++) {
		if (in[seq[i]] == false) {
			in[seq[i]] = true;
			tup[depth + 1] = i;
			bkt(depth + 1);
			in[seq[i]] = false;
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	string line;
	stringstream ss;
	char a, b;

	bool blank = false;
	while (getline(cin, line)) {
		ss.clear();
		ss << line;
		N = -1;
		while (ss >> seq[++N]);
		memset(cons, false, sizeof(cons));
		getline(cin, line);
		ss.clear();
		ss << line;
		while (ss >> a >> b)
			cons[a][b] = true;
		sort(seq, seq + N);
		memset(in, false, sizeof(in));


		if (blank)
			puts("");
		blank = true;

		for (int i = 0; i < N; i++) {
			in[seq[i]] = true;
			tup[0] = i;
			bkt(0);
			in[seq[i]] = false;
		}



	}


	return 0;
}