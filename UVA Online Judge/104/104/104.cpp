#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k,m,used[23];
double dist[23][23],path[23][23];

void p(int q,int last){
	for (i = 0; i < last; i++){
		if (used[i] == q)return;
	}
	if (q == k)return;
	cout << q + 1 << " ";
	used[last] = q;
	last++;
	p(path[q][k],last);
}
void find(int n){
	int i, j, k;
	for (i = 0; i < n; i++)dist[i][i] = 1.0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			path[i][j] = j;
	for (k = 0; k < n; k++){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (dist[i][k] * dist[k][j] > dist[i][j]){
					dist[i][j] = dist[i][k] * dist[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}
}
int main()
{
	int n;
	while (cin >> n){
		for (i = 0; i < 23; i++){
			for (j = 0; j < 23; j++){
				dist[i][j] = 0.000001;
			}
		}
		for (i = 0; i < n; i++)dist[i][i] = 1.0;
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (dist[i][j] == 0.000001){
					cin >> dist[i][j];
				}
			}
		}
		find(n);

		for (i = 0; i < n; i++){
			if (dist[i][i] > 1.0){
				k = i;
				cout << i + 1 << " ";
				for (j = 0; j < 23; j++)used[j] = 0;
				p(path[i][i],0);
				cout << i + 1 << "\n";
				break;
			}
		}
		if (i == n)cout << "no arbitrage sequence exists\n";
	}
	return 0;

}