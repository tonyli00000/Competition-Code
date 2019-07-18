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
#define INF 100000000.0
using namespace std;

long long n, x, y,i,j,k;

vector<pair<long long, long long>>xy(155);
double dist[155][155];

long long distcalc(long long x1, long long y1, long long x2, long long y2){
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}
int main()
{
	cin >> n;
	for (i = 0; i < n + 3; i++){
		for (j = 0; j < n + 3; j++){
			dist[i][j] = 100000000.0;
		}
	}
	for (i = 0; i < n; i++){
		cin >> x >> y;
		xy[i] = make_pair(x, y);
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			char c;
			cin >> c;
			if (c == '1'){
				dist[i][j] = sqrt(distcalc(xy[i].first, xy[i].second, xy[j].first, xy[j].second));
			}
		}
	}
	for (k = 0; k < n; k++){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	double ans = 0.0;
	double a=INF, b=INF;
	pair<long long,long long>ai, bi;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (j == i)continue;
			if (dist[i][j] != INF)ans = max(ans, dist[i][j]);
			else {
				if (sqrt(distcalc(xy[i].first, xy[i].second, xy[j].first, xy[j].second)) < a && ai != make_pair(i, j) && bi != make_pair(i, j)){
					if (a > b){
						if (sqrt(distcalc(xy[i].first, xy[i].second, xy[j].first, xy[j].second)) < a){
							a = sqrt(distcalc(xy[i].first, xy[i].second, xy[j].first, xy[j].second));
							ai = make_pair(i, j);
						}
					}
					else {
						if (sqrt(distcalc(xy[i].first, xy[i].second, xy[j].first, xy[j].second)) < b){
							b = sqrt(distcalc(xy[i].first, xy[i].second, xy[j].first, xy[j].second));
							bi = make_pair(i, j);
						}
					}

				}
			}
		}
	}
	dist[ai.first][ai.second] = a;
	dist[ai.second][ai.first] = a;
	dist[bi.first][bi.second] = b;
	dist[bi.second][bi.first] = b;
	for (k = 0; k < n; k++){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (j == i)continue;
			if (dist[i][j] != INF)ans = max(ans, dist[i][j]);
		}
	}
	cout << fixed<<setprecision(6)<<ans << "\n";
	return 0;
}
