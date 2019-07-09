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


long long n, k;
vector<vector<int> > v;
vector<long long> d;

class Compare{
public:
	bool operator() (const vector<pair<int,int>> &p, const vector<pair<int,int>> &q){
		long long x = 0, y = 0;
		for (auto i : p){
			x += v[i.first][i.second] - v[i.first][0];
		}
		for (auto i : q){
			y += v[i.first][i.second] - v[i.first][0];
		}
		return x > y;
	}
};

bool cmp(const vector<int> &a, const vector<int> &b){
	return a[1] - a[0] < b[1] - b[0];
}
vector<long long> solve(int c){
	long long tot = 0;
	for (int i = 0; i<n; i++) tot += v[i][0];

	priority_queue<vector<pair<int,int>>, vector<vector<pair<int,int>>>,Compare>pq;
	set<vector<pair<int,int>>> used;
	vector<long long> ans;

	vector<pair<int,int>> w;
	for (int j = 0; j < c; j++) w.push_back({ j, 1 });
	pq.push(w);

	while (!pq.empty() && ans.size() < k){
		auto cur = pq.top();
		pq.pop();
		if (used.find(cur) != used.end()) continue;
		used.insert(cur);
		long long ret = tot;
		for (auto i : cur){
			ret += v[i.first][i.second] - v[i.first][0];
		}
		if (d.size() + ans.size() >= k && ret >= d.back()) continue;
		ans.push_back(ret);
		for (int i = 0; i<c; i++){
			auto p = cur;
			if (p[i].second + 1 < v[p[i].first].size()){
				p[i].second++;
				pq.push(p);
				p[i].second--;
			}
			if (p[i].second == 1 && i < c - 1 && p[i].first + 1 < p[i + 1].first){
				p[i].first++;
				pq.push(p);
				p[i].first--;
			}
			if (p[i].second == 1 && i == c - 1 && p[i].first + 1 < n){
				p[i].first++;
				pq.push(p);
				p[i].first--;
			}
		}
	}
	return ans;
}

int main(){
	freopen("roboherd.in", "r", stdin);
	freopen("roboherd.out", "w", stdout);
	cin >> n >> k;
	long long ret = 0;
	d.push_back(0);
	for (int i = 0; i<n; i++){
		int x;
		cin >> x;
		vector<int> parts(x);
		for (int j = 0; j<x; j++){
			cin >> parts[j];
		}
		if (x == 1)ret += (long long)parts[0] * k;
		else{
			sort(parts.begin(), parts.end());
			v.push_back(parts);
			d[0] += parts[0];
		}
	}
	sort(v.begin(), v.end(), cmp);
	n = v.size();
	for (int i = 1; i <= 16 && i <= n; i++){
		vector<long long> parts = solve(i);
		for (int j = 0; j<parts.size();j++){
			d.push_back(parts[j]);
		}
		sort(d.begin(), d.end());
		while (d.size() > k){
			d.pop_back();
		}
	}
	for (int i = 0; i<k; i++) ret += d[i];
	cout << ret<<"\n";
	return 0;
}