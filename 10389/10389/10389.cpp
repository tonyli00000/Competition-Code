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
#define INF 10000000
using namespace std;

int n;
vector<vector<pair<int, int>>>adj;
void SSSP(int src){
	priority_queue< pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>> > pq;
	vector<double> dist(n, INF);
	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		for (auto i:adj[u]){
			int v = i.first;
			int weight = i.second;
			if (dist[v] > dist[u] + weight){
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--){
		map<pair<int, int>, int>node;
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		node[{a, b}] = 0;
		node[{c, d}] = 1;
		string line;
		getline(cin, line);
		while (getline(cin, line) && line != ""){
			stringstream ss(line);
			vector<int>x, y;
			int a, b;
			while (ss >> a >> b && (a!=-1 && b!=-1)){
				x.push_back(a);
				y.push_back(b);
			}
			
		}
		if (t)cout << "\n";
	}
	return 0;
}
