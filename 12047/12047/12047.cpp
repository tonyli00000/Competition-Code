#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int n, m, s, t, p,pos;
int dist[10000][10000],vertex[10000];

void find() {
	int i, j, k;
	for (i = 0; i < pos; i++)dist[vertex[i]][vertex[i]] = 0;
	for (k = 0; k < pos; k++) {
		for (i = 0; i < pos; i++) {
			for (j = 0; j < pos; j++) {
				if (dist[vertex[i]][vertex[k]] + dist[vertex[k]][vertex[j]]>dist[vertex[i]][vertex[j]] && dist[vertex[i]][vertex[k]] + dist[vertex[k]][vertex[j]]<p)dist[vertex[i]][vertex[j]] = dist[vertex[i]][vertex[k]] + dist[vertex[k]][vertex[j]];
			}
		}
	}
}

int main()
{
	int t,i,j,k,x,y,z;
	cin >> t;
	for (k = 0; k < t; k++) {
		cin >> n >> m >> s >> t >> p;
		pos = 0;
		for (i = 0; i < 10000; i++)vertex[i] = -1;
		for (i = 0; i < m; i++) {
			cin >> x >> y >> z;
			dist[x-1][y-1] = z;
			for (j = 0; j < pos; j++)if (vertex[j] == x-1)break;
			if (j == pos) {
				vertex[pos] = x-1;
				pos++;
			}
			for (j = 0; j < pos; j++)if (vertex[j] == y-1)break;
			if (j == pos) {
				vertex[pos] = y-1;
				pos++;
			}
		}
		find();
		if (dist[s][t]>p)cout << "-1\n";
		else cout << dist[s-1][t-1];
	}
	return 0;
}
