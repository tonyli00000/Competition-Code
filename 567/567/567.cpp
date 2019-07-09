#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

bool connected[20][20];
int i, j, k,Q[20];
int dist[20],c=1;
int w(int m, int n){
	int i, u, v = 0 , j, k;
	for (i = 0; i < 20; i++){
		if (Q[i] != m-1)dist[i] = 60000;
		if (Q[i]==m-1)dist[i] = 0;
	}
	int b;
	for (i = 0; i < 20; i++){
		int min = 10000;
		for (j = 0; j < 20; j++){
			if (i != 0){
				if(dist[j] < min && Q[j] != 0)min = j;
			}
			if (i == 0)if (dist[j] < min)min = dist[j];
		}
		u = min;
		for (j = 0; j < 20; j++){
			if (connected[u][j] == true){
				v = j;
				b = dist[u] + 1;
				if (dist[v]>b)dist[v] = b;
			}
		}
		Q[u] = 0;
	}
	return dist[n-1];
}
int main()
{
	int t,p;
	while (true){
		for (i = 0; i < 20; i++)Q[i] = i;
		for (i = 0; i < 20; i++){
			for (j = 0; j < 20; j++){
				connected[i][j] = false;
			}
		}
		for (i = 0; i < 19; i++){
			cin >> t;
			for (j = 0; j < t; j++){
				cin >> p;
				connected[i][p - 1] = true;
				connected[p - 1][i] = true;
			}
		}
		cin >> t;
		int m, n;
		cout << "Test Set #" << c << "\n";
		for (i = 0; i < t; i++){
			cin >> m >> n;
			if (m < 10)cout << " " << m << " to ";
			else cout << m << " to ";
			if (n < 10)cout << n << ": ";
			else cout << n << ": ";
			for (j = 0; j < 20; j++)Q[j] = j;
			int l;
			l = w(m, n);
			cout << l << "\n";
		}
		c++;
	}
	return 0;

}