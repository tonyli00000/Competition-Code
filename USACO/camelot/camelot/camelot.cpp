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
#define INF 200000
using namespace std;

long long dx[8] = { -1,-1,1,1,2,2,-2,-2 };
long long dy[8] = { -2,2,2,-2,-1,1,-1,1 };
bool comp(pair<long long, long long>x, pair<long long, long long>y) {
	return (x.first - x.second) < (y.first - y.second);
}
int main()
{
	long long r, c;
	long long n;
	cin >> r >> c >> n;
	vector<vector<vector<vector<long long>>>>dist(r + 5, vector<vector<vector<long long>>>(c + 5, vector<vector<long long>>(r + 5, vector<long long>(c + 5, INF))));
	
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			dist[i][j][i][j] = 0;
			queue<pair<long long,long long>>Q;
			Q.push({ i,j });
			while (!Q.empty()) {
				pair<long long, long long>a = Q.front();
				Q.pop();
				long long x = a.first, y = a.second;
				for (int k = 0; k < 8; k++) {
					long long x2 = x + dx[k], y2 = y + dy[k];
					if (x2 >= 1 && x2 <= r && y2 >= 1 && y2 <= c && dist[i][j][x2][y2]==INF) {
						dist[i][j][x2][y2] = dist[i][j][x][y] + 1;
						Q.push({ x2,y2 });
					}
				}
			}
		}
	}

	vector<pair<long long, long long>>knight;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		knight.push_back({ x,y });
	}
	long long best = INF;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			for (int a = 1; a <= r; a++) {
				for (int b = 1; b <= c; b++) {
					if (i == a && j == b)continue;
					vector<pair<long long, long long>>d;
					for (int x = 0; x < n; x++) {
						d.push_back( { dist[knight[x].first][knight[x].second][i][j],dist[knight[x].first][knight[x].second][a][b] });
					}
					sort(d.begin(), d.end(), comp);
					long long curr = 0;
					for (int x = 0; x < n / 2; x++) {
						curr += d[x].first;
					}
					for (int x = n / 2; x < n; x++) {
						curr += d[x].second;
					}
					best = min(best, curr);
				}
			}
		}
	}
	cout << best << "\n";
	return 0;
}
