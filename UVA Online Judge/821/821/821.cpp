#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 10000
using namespace std;
int i, j, k,dist[105][105],vertex[105];
bool connected[105][105];

void sort(int last){
	for (i = 0; i < last; i++)
		for (j = 0; j < last; j++)
			dist[vertex[i]][vertex[j]] = MAXN;
	for (i = 0; i < last; i++)dist[vertex[i]][vertex[i]] = 0;
	for (i = 0; i < last; i++)
		for (j = 0; j < last; j++){
			if (connected[vertex[i]][vertex[j]] == true){
				dist[vertex[i]][vertex[j]] = 1;
				connected[vertex[i]][vertex[j]] = false;
			}
		}
	for (k = 0; k < last; k++){
		for (i = 0; i < last; i++){
			for (j = 0; j < last; j++){
				if (dist[vertex[i]][vertex[j]] > dist[vertex[i]][vertex[k]] + dist[vertex[k]][vertex[j]])dist[vertex[i]][vertex[j]] = dist[vertex[i]][vertex[k]] + dist[vertex[k]][vertex[j]];
			}
		}
	}	
}
int main()
{
	int m, n,last,t=0;
	while (cin >> m >> n && m != 0 && n != 0){
		t++;
		for (i = 0; i < 105; i++)vertex[i] = 0;
		connected[m-1][n-1] = true;
		vertex[0] = m - 1;
		vertex[1] = n - 1;
		last = 2;
		while (cin >> m >> n && m != 0 && n != 0){
			connected[m - 1][n - 1] = true;
			for (i = 0; i < last; i++)if (vertex[i] == m - 1)break;
			if (i == last){
				vertex[last] = m - 1;
				last++;
			}
			for (i = 0; i < last; i++)if (vertex[i] == n - 1)break;
			if (i == last){
				vertex[last] = n - 1;
				last++;
			}
		}
		sort(last);
		int sum = 0;
		for (i = 0; i < last; i++){
			for (j = 0; j < last; j++){
				if (dist[i][j] != MAXN){
					sum += dist[vertex[i]][vertex[j]];
				}
			}
		}
		float f = 0;
		f = 1.0*sum / (1.0*(last*(last - 1)));
		cout << fixed << setprecision(3) << "Case "<<t<<": average length between pages = "<< f <<" clicks\n";
	}


	return 0;
}
