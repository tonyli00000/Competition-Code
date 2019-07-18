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
int i, j, k;
vector<int>ct2;
bool compare(int i, int j){
	return ct2[j] > ct2[i];
}
int solve(vector<int>ct){
	int i, j, k;
	ct2 = ct;
	priority_queue<int, vector<int>, function<bool(int, int)>>pq(compare);
	for (i = 1; i < ct2.size(); i++){
		if (ct2[i] != 0)pq.push(i);
	}
	while (pq.size() > 1){
		int x = pq.top(); pq.pop();
		int y = pq.top(); pq.pop();
		ct2[x]--;
		ct2[y]--;
		if (ct2[x] != 0)pq.push(x);
		if (ct2[y] != 0)pq.push(y);
	}
	if (pq.empty())return ct2[0];
	return max(0, ct2[0] - ct2[pq.top()]);
}
int main(){
	freopen("gangs.in", "r", stdin);
	freopen("gangs.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int>gang(m);
	for (i = 0; i < m; i++)
		cin >> gang[i];
	int curr = solve(gang);
	if (curr == 0){
		cout << "NO\n";
		return 0;
	}
	vector<vector<int>>with(m);
	for (i = 0; i < m; i++){
		for (j = i + 1; j < m; j++){
			while (gang[i]>0 && gang[j] > 0){
				gang[i]--;
				gang[j]--;
				if (solve(gang) == curr)with[i].push_back(j);
				else{
					gang[i]++;
					gang[j]++;
					break;
				}
			}
		}
	}
	cout << "YES\n"<<curr<<"\n";
	bool f = true;
	for (i = 1; i < m; i++){
		if (with[i].size() > 0)break;
	}
	if (i == m){
		for (i = 0; i < curr; i++)
			cout << 1 << "\n";
	}
	else f = false;
	for (i = 0; i < m; i++){
		for (j = 0; j < with[i].size(); j++){
			cout << i + 1 << "\n";
		}
		for (auto s : with[i]){
			cout << s + 1 << "\n";
		}
	}
	if (!f){
		for (i = 0; i < curr; i++){
			cout << 1 << "\n";
		}
	}
	return 0;
}

