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

using namespace std;

long long min(long long x, long long y) {
	if (x < y)return x;
	else return y;
}
int d[20000][20000];
int next[20000];
void MSSP(int m) {
	int i, j, k;
	for (k = 0; k < m; k++) {
		for (i = 0; i < m; i++) {
			for (j = 0; j < m; j++) {
				if (d[i][k] != -1 && d[k][j] != -1)min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = 40000, min_index;

	for (int v = 0; v < 20000; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}
void printMST(int parent[], int n, int graph[20000][20000])
{
	printf("Edge   Weight\n");
	for (int i = 1; i < n; i++)
		printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[20000][20000],int n)
{
	int parent[20000];
	int key[20000]; 
	bool mstSet[20000];  
	for (int i = 0; i < n; i++)
		key[i] = 60000, mstSet[i] = false;
	key[0] = 0;     
	parent[0] = -1; 
	for (int count = 0; count < n - 1; count++)
	{
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < n; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	//printMST(parent, n, graph);
}
int main()
{
	int m, n, i, j, k;
	while (cin >> m >> n) {
		for (i = 0; i < 20000; i++) {
			for (j = 0; j < 20000; j++) {
				d[i][j] = -1;
			}
		}
		for (i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			d[a][b] = c;
		}
		primMST(d,m);
	}
	return 0;
}
