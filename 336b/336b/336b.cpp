#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, u, v,ttl=0,dist[33];
bool connected[33][33];
bool node[33], temp[33];
int nodes[33],Q[33];

void path(int x, int ttl,int nodenum){
	int i, j, k, v = 0, u = 0, r = 0;
	for (i = 0; i < nodenum; i++){
		if (i != x)dist[i] = 30000;
		else dist[x] = 0;
	}
	dist[x] = 0;
	for (i = 0; i < nodenum; i++){
		int min = 35001;
		for (j = 0; j < nodenum; j++){
			if ((dist[j] < min) && (Q[j] != -1)){
				v = j;
				min = dist[j];
			}
		}
		for (j = 0; j < nodenum; j++){
			if (connected[v][j]){
				if (dist[j] > min + 1){
					dist[j] = min + 1;
				}
			}
		}
		Q[v] = -1;
	}
}
int main()
{
	int m, n, t, nodenum = 0, test=1;
	while ((cin >> t)&&(t!=0)){
		nodenum = 0;
		for (i = 0; i < 33; i++){
			for (j = 0; j < 33; j++){
				connected[i][j] = false;
			}
		}
		for (i = 0; i < 33; i++){
			nodes[i] = 0;
			Q[i] = -1;
			dist[i] = 0;
		}
		for (i = 0; i < t; i++){
			cin >> m >> n;
			for (j = 0; j < nodenum; j++)if (nodes[j] == m){
				m = j;
				break;
			}
			if (j == nodenum){
				nodes[nodenum] = m;
				m = nodenum;
				nodenum++;
			}
			for (j = 0; j < nodenum; j++)if (nodes[j] == n){
				n = j;
				break;
			}
			if (j == nodenum){
				nodes[nodenum] = n;
				n = nodenum;
				nodenum++;
			}
			connected[m][n] = true;
			connected[n][m] = true;
		}
		while ((cin >> m >> ttl)){
			if (m == 0 && ttl == 0)break;
			if (ttl == 0)cout << "Case " << test << ": " << nodenum-1 << " nodes not reachable from node " << m << " with TTL = " << ttl << ".\n";
			else
			{
				for (i = 0; i < nodenum; i++){
					if (nodes[i] == m){
						m = i;
						break;
					}
				}
				for (i = 0; i < nodenum; i++)Q[i] = i;
				path(m, ttl, nodenum);
				int sum = 0;
				for (i = 0; i < nodenum; i++){
					if (dist[i] >ttl)sum++;
				}
				cout << "Case " << test << ": " << sum << " nodes not reachable from node " << nodes[m] << " with TTL = " << ttl << ".\n";
				sum = 0;
			}
			test++;
		}
	}
		return 0;

	}
