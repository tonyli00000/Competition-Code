#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int i, j, k;
int dist[101][101];

void d(int vertex){
	int i, j, k;
	for (i = 0; i < vertex; i++)dist[i][i] = 0;
	for (k = 0; k < vertex; k++){
		for (i = 0; i < vertex; i++){
			for (j = 0; j < vertex; j++){
				if (dist[i][k] + dist[k][j] < dist[i][j])dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

int main()
{
	int t,n,r,u,v;
	cin >> t;
	for (k = 0; k < t; k++){
		for (i = 0; i < 101; i++)
			for (j = 0; j < 101; j++)
				dist[i][j] = 30000;
		cin >> n;
		cin >> r;
		for (i = 0; i < r; i++){
			cin >> u >> v;
			dist[u][v] = 1; dist[v][u] = 1;
		}
		cin >> u >> v;
		d(n);
		int maxd = 0;
		for (i = 0; i < n; i++){
			if (dist[u][i] + dist[v][i] > maxd)maxd = dist[u][i] + dist[v][i];
		}
		cout << "Case "<<k+1<<": "<<maxd<<"\n";
	}
	return 0;
}
