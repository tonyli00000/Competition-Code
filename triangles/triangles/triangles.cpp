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
//#pragma warning(disable:4996)
using namespace std;

long long i, j, k;
int main()
{
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<long, long>>points(n);
	for (i = 0; i < n; i++){
		cin >> points[i].first >> points[i].second;
	}
	sort(points.begin(), points.end());
	
	vector<vector<int>>lower(n, vector<int>(n, 0));
	for (i = 0; i < n; i++){
		for (j = i+1; j < n; j++){
			for (k = i + 1; k < j; k++){
				long long a, b, c, d;
				a = points[j].first - points[k].first;
				b = points[j].second - points[k].second;
				c = points[i].first - points[k].first;
				d = points[i].second - points[k].second;
				if (a*d - b*c > 0)lower[i][j]++;
			}
		}
	}

	vector<long long>out(n - 2, 0);
	for (i = 0; i < n; i++){
		for (j = i+1; j < n; j++){
			for (k = j+1; k < n; k++){
				long long ct = lower[i][k] - lower[i][j] - lower[j][k];
				if (ct > 0)ct--;
				else if (ct < 0)ct *= -1;
				out[ct]++;
			}
		}
	}
	for (int i = 0; i < n - 2; i++){
		cout << out[i] << "\n";
	}
	return 0;
}

