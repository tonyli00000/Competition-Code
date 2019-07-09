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
	long n, m,i,j,k;
	while (cin >> n >> m){
		if (!n&&!m)break;
		vector < pair<pair<long, long>, long>> tasks;
		bool conflict = false;
		for (i = 0; i < n; i++){
			long x, y;
			cin >> x >> y;
			for (j = 0; j < tasks.size(); j++){
				if (tasks[j].first.first<y && tasks[j].first.first>x){
					conflict = true;
					break;
				}
				if (tasks[j].first.second > x && tasks[j].first.second < y){
					conflict = true;
					break;
				}

			}
			tasks.push_back(make_pair(make_pair(x, y), -1));
		}
		for (i = 0; i < m; i++){
			long x, y,z;
			cin >> x >> y>>z;
			for (j = 0; j < tasks.size(); j++){
				if (tasks[j].second == -1){
					if (tasks[j].first.first<y && tasks[j].first.first>x){
						conflict = true;
						break;
					}
					if (tasks[j].first.second > x && tasks[j].first.second < y){
						conflict = true;
						break;
					}
					long a = (tasks[j].first.first) / z + x,b=(tasks[j].first.second)/z+y;
					if (tasks[j].first.first<y && tasks[j].first.first>x){
						conflict = true;
						break;
					}
					if (tasks[j].first.second > x && tasks[j].first.second < y){
						conflict = true;
						break;
					}
				}
			}
		}
		if (conflict)cout << "CONFLICT\n";
		else cout << "NO CONFLICT\n";
	}
	return 0;
}
