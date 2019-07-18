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

long long i, j, k;
map<long long, pair<long long,long long>>ind;
vector<long long>seq;
int main()
{
	long long n;
	cin >> n;
	for (i = 0; i < n; i++){
		long long x;
		cin >> x;
		ind[x].push_back(i);
		seq.push_back(x);
	}
	long long ans = 0;
	bool visited[60000];
	for (i = 0; i <= n + 5; i++){
		visited[i] = false;
	}
	for (i = 1; i <= n; i++){
		long long s = ind[i][0], e = ind[i][1], temp = 0;;
		map<long long, int>ct;
		for (j = s + 1; j < e; j++){
			if (seq[j]>i)ct[seq[j]]++;
		}
		for (auto it = ct.begin(); it != ct.end(); it++){
			if (it->second == 2)continue;
			else ans++;
		}
		
	}
	cout << ans << "\n";
	return 0;
}
