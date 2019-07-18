/*
ID:tonyli21
PROG:schlnet
LANG:C++11
*/
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
#define MAXX 105
int adj[MAXX][MAXX] = { 0 }, DFN[MAXX] = { 0 }, low[MAXX] = { 0 }, in[MAXX] = { 0 }, out[MAXX] = { 0 };
int step[MAXX] = { 0 };
bool flag[MAXX] = { false };
stack<int>S;
int ret, tot, M, ans, ans1;

void tarjan(int v){
	DFN[v] = low[v] = ++tot;//Initialization. Used for finding the root
	int u;
	flag[v] = 1;
	S.push(v);
	for (int i = 1; i <= M; i++){
		if (adj[v][i]){
			if (!DFN[i]){ //If not visited
				tarjan(i);
				low[v] = min(low[v], low[i]);
			}
			else if (flag[i])low[v] = min(low[v], low[i]);
		}
	}

	if (DFN[v] == low[v]){
		ret++;
		do{
			u = S.top();
			S.pop();
			flag[u] = 0;
			step[u] = ret;
		} while (v != u);
	}
}
void solve(){
	for (int i = 1; i <= M; i++){
		for (int j = 1; j <= M; j++){
			if (step[i] != step[j] && adj[i][j]){
				in[step[j]]++;
				out[step[i]]++;
			}
		}
	}
	int xx = 0, yy = 0;
	for (int i = 1; i <= ret; i++){
		if (in[i] == 0)xx++;
		else if (out[i] == 0)yy++;
	}
	ans = xx;
	ans1 = max(xx, yy);
	cout << ans << "\n";
	cout << ans1 << "\n";
}
int main()
{
	freopen("schlnet.in", "r", stdin);
	freopen("schlnet.out", "w", stdout);
	while (cin>>M){
		tot = 0;
		ret = 0;
		for (int i = 1; i <= M; i++){
			int x;
			while (cin>>x && x){
				adj[i][x] = 1;
			}
		}
		for (int i = 1; i <= M; i++){
			if (!DFN[i])tarjan(i);
		}
		if (ret == 1)cout << 1 << "\n" << 0 << "\n";
		else solve();
	}
	return 0;
}