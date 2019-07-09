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
#define INF 100000000
using namespace std;


int main()
{
	int k, m;
	while (cin >> k >> m){
		int x[105], y[105], r[105];
		double mat[105][105];
		cin >> x[0] >> y[0] >> r[0]>>x[1]>>y[1]>>r[1];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> x[i+2] >> y[i+2] >> r[i+2];
		}
		for (int i = 0; i < n+2; i++) {
			for (int j = 0; j < n+2; j++){
				double dist = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
				if (dist < r[i] + r[j]) dist = 0;
				else  dist = dist - r[i] - r[j];

				if (dist > k*m) mat[i][j] = INF;
				else mat[i][j] = dist;
			}
		}
		for (int k = 0; k < 2 + n; k++){
			for (int i = 0; i < 2 + n; i++){
				for (int j = 0; j < 2 + n; j++){
					if (mat[i][j] > mat[i][k] + mat[k][j]){
						mat[i][j] = mat[i][k] + mat[k][j];
					}
				}
			}
		}
		if (mat[0][1] == INF)cout << "Larry and Ryan will be eaten to death.\n";
		else cout << "Larry and Ryan will escape!\n";
	}
	return 0;
}
