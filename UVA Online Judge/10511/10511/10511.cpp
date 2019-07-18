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
#define MAX_V 50000
#define INF 1000000000

int mf, f, s, t;
vector<vector<int>>cap;
vector<int> p;
typedef vector<int> vi;
void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	}
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, cap[p[v]][v]));
		cap[p[v]][v] -= f;
		cap[v][p[v]] += f;
	}
}
int main()
{
	int w,i,j,k;
	cin >> w;
	string line;
	getline(cin, line);
	vector<string> resident;
	vector<string> d;
	map<string, int> party;
	map<string, int>club;
	vector<int>connected;
	string name, q, clubs;
	for (k = 0; k < w; k++) {
		if (k != 0)cout << "\n";
		int ct = 0, c = 0, con = 0;
		resident.clear();
		d.clear();
		party.clear();
		club.clear();
		connected.clear();
		vector<int> person[1005];
		if(k==0)getline(cin, line);
		while (getline(cin, line) && line != "") {
			stringstream ss(line);
			ss >> name >> q;
			resident.push_back(name);
			ct++;
			if (party.find(q) == party.end())party[q] = c++;
			connected.push_back(party[q]);
			while (ss >> clubs) {
				if (club.find(clubs) == club.end()) {
					club[clubs] = con++;
					d.push_back(clubs);
				}
				person[ct - 1].push_back(club[clubs]);
			}
		}
		int a = party.size(), b = resident.size(), g = club.size();
		s = 0;
		t = a+b+g+1;
		cap.clear();
		cap.resize(t + 11);
		for (i = 0; i <= t + 10; i++) {
			cap[i].resize(t+10,0);
		}
		for (i = 0; i <= t; i++) {
			for (j = 0; j <= t; j++) {
				cap[i][j] = 0;
			}
		}
		for (i = 1; i <= a; i++) {
			cap[0][i] = c / 2 - (1 - g% 2);
		}
		for (i = t - g; i < t; i++) {
			cap[i][t] = 1;
		}
		for (i = 0; i < connected.size(); i++) {
			cap[connected[i]+1][i+1+a] = 1;
		}
		for (i = 0; i < b; i++) {
			for (j = 0; j < person[i].size(); j++) {
				cap[i+a+1][person[i][j]+1+a+b] = 1;
			}
		}
		mf = 0;
		while (1) {
			f = 0;
			vi dist(t+5, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(t+5, -1);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				if (u == t)
					break;
				for (int v = 0; v < t+5; v++)
					if (cap[u][v] > 0 && dist[v] == INF) {
						dist[v] = dist[u] + 1;
						q.push(v);
						p[v] = u;
					}
			}
			augment(t, INF);
			if (!f)break;
			mf += f;
		}
		if (mf < g)cout << "Impossible.\n";
		else {
			for (i = t - g; i < t; i++) {
				for (j = t - g - b; j < t - g; j++) {
					if (cap[i][j] == 1) {
						cout << resident[j - a - 1] << " " << d[connected[j - a - 1]] << "\n";
					}
				}
			}
		}
		//cout << "\n";
	}
	return 0;
}
