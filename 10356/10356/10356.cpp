#include <stdio.h>
#include <cmath>
#include <set> 
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stack>
#include <map>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <functional>

using namespace std;

#define r(input) freopen("input.txt","r",stdin)
#define w(output) freopen("output.txt","w",stdout)

#define FOR(i, a) for ( int i = 0 ; i < a ; i++ )
#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)

#define BitCount(i) __builtin_popcount(i)
#define Sort(v) sort(v.begin(),v.end())
#define cover(a, d) memset(a,d,sizeof(a))
#define remove(v,e) v.erase(std::find(v.begin(),v.end(),e))

#define sz size
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

#define VISITED 1
#define UNVISITED 0
#define INF 1000000000

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int, ii> iii;

inline int toInt(string s){ int v; istringstream sin(s); sin >> v; return v; }
inline ll toll(string s){ ll v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

vii adj[1005];

class Order
{
public:
	bool operator() (iii const &a, iii const &b) { return a.ft > b.ft; }
};


int main()
{
	int n, r, t = 0;
	while (cin >> n >> r)
	{
		FOR(i, n) adj[i].clear();
		FOR(i, r)
		{
			int u, v, w;
			cin >> u >> v >> w;
			if (u >= 0 && v >= 0 && u < n && v < n)
			{
				adj[u].pb(mp(v, w));
				adj[v].pb(mp(u, w));
			}
		}

		int dist2[1005][2];
		FOR(i, n) FOR(j, 2) dist2[i][j] = INF;

		if (n && r)
			dist2[0][0] = 0;
		priority_queue < iii, vector<iii>, Order > pq;
		pq.push(mp(0, mp(0, 0)));
		while (!pq.empty())
		{
			iii front = pq.top(); pq.pop();
			int dis = front.ft;
			int u = front.sd.ft;
			int bike = front.sd.sd;

			if (dis > dist2[u][bike])
				continue;

			for (int i = 0; i < adj[u].sz(); i++)
			{
				ii v = adj[u][i];
				if (dis + v.sd < dist2[v.ft][(bike + 1) % 2])
				{
					dist2[v.ft][(bike + 1) % 2] = dis + v.sd;
					pq.push(mp(dist2[v.ft][(bike + 1) % 2], mp(v.ft, (bike + 1) % 2)));
				}
			}
		}

		cout << "Set #" << ++t << endl;
		if (n && r &&dist2[n - 1][0] != INF)
			cout << dist2[n - 1][0] << endl;
		else
			cout << '?' << endl;
	}
}