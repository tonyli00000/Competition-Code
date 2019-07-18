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

using namespace std;

int main()
{
	int t,i,j,k;
	cin >> t;
	while (t--){
		int m, n;
		cin >> m >> n;
		vector<int>fire(m);
		vector<long long>d(n + 1, 1000000);
		vector<vector<long long>>dist(n + 5, vector<long long>(n + 5, 1000000));
		for (i = 0; i < m; i++){
			cin >> fire[i];
			d[fire[i]] = 0;
		}
		sort(fire.begin(), fire.end());
		string line;
		getline(cin, line);
		while(getline(cin,line)&&line!=""){
			stringstream ss(line);
			int x, y, z;
			ss >> x >> y >> z;
			dist[x][y] = z;
			dist[y][x] = z;
			dist[i + 1][i + 1] = 0;
		}
		for (k = 1; k <= n; k++){
			for (i = 1; i <= n; i++){
				for (j = 1; j <= n; j++){
					dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
				}
			}
		}
		int ct = 0;
		
		for (i = 1; i <= n; i++){
			for (auto j : fire){
				d[i] = min(d[i], dist[i][j]);
			}
		}
		long long ans = 100000000;
		int ret = -1;
		for (i = 1; i <= n; i++){
			long long minn = -1;
			for (j = 1; j <= n; j++){
				if (i == j)continue;
				long long q = min(dist[i][j], d[j]);
				minn = max(minn, q);
			}
			if (minn < ans)ret = i;
			ans = min(minn, ans);
		}
		cout << ret << "\n";
		if (t)cout << "\n";
	}
	return 0;
}
