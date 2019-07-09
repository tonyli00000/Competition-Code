#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 3000000
#define N 110
using namespace std;

long long dist[N][N],vertex[N],previous[N],v[N];
bool used[N][N];

//void find(int t) {
//	int i, j, k;
//	for (k = 1; k <= t; k++) {
//		for (i = 1; i <= t; i++) {
//			for (j = 1; j <= t; j++) {
//				if (dist[i][k] + dist[k][j] < dist[i][j] && used[i][k] && used[j][k]) {
//					dist[i][j] = dist[i][k] + dist[k][j];
//					used[i][k] = false;
//					used[k][i] = false;
//					used[k][j] = false;
//					used[j][k] = false;
//				}
//			}
//		}
//	}
//}
void find(int t,int source,int num) {
	int i, j, k;
	dist[source][source] = 0;
	for (i = 0; i < t; i++) {
		if (i != source) {
			previous[i] = -1;
		}
	}
	long long min = 0;
	for (j = 0; j < t; j++) {
		for (i = 0; i < t; i++)if (vertex[i] != -1 && vertex[i] < vertex[min])min = i;
		for (i = 0; i < t; i++) {
			if (used[min][i]) {
				if (dist[source][min] + dist[min][i] < dist[source][i]) {
					dist[source][i] = dist[source][min] + dist[min][i];
					previous[i] = vertex[min];
				}
			}
		}
		vertex[min] = 3000000;
	}
}
int main()
{
	int t,i,j,k;
	while (cin >> t && t != 0) {
		int n;
		for (i = 0; i < 100; i++) {
			for (j = 0; j < 100; j++) {
				dist[i][j] = 3000000;
				used[i][j] = false;
			}
		}
		cin >> n;
		for (i = 0; i < n; i++) {
			int a, b,ind=0;
			cin >> a >> b;
			for (j = 0; j < ind; j++)if (a-1 == vertex[j])break;
			if (j == ind) {
				vertex[ind] = a-1;
				v[ind] = a - 1;
				ind++;
			}
			for (j = 0; j < ind; j++)if (b-1 == vertex[j])break;
			if (j == ind) {
				vertex[ind] = b-1;
				v[ind] = b - 1;
				ind++;
			}
			cin >> dist[a-1][b-1];
			dist[b-1][a-1] = dist[a-1][b-1];
			used[a-1][b-1] = true;
			used[b-1][a-1] = true;
		}
		for (j = 0; j < t; j++)if (vertex[j] == 0) {
			find(t, j, 0);
			while (previous[j] != -1) {
				used[j][previous[j]] = false;
				used[previous[j]][j] = false;
				j = previous[j];
			}
			break;
		}
		for (j = 0; j < t; j++)if (v[j] == 0) {
			find(t, j, 0);
		}
		if ((dist[0][n-1] == 3000000) || (dist[n-1][0] == 3000000))cout << "Back to jail\n";
		else cout << dist[0][n-1] + dist[n-1][0] << "\n";
	}
	return 0;
}
