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
#pragma warning(disable:4996)

using namespace std;
int n;
set<int> a1;
set<int> a2;
int main()
{
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	int n;
	cin >> n;
	vector<int>elsie(n+2);
	vector<bool>bessie(n * 2 + 5, false);
	vector<int>start(n + 5, 0), e(n + 5, 0);
	for (int i = 1; i <= n; i++){
		cin >> elsie[i];
		bessie[elsie[i]] = true;
	}
	for (int i = 1; i <= n * 2; i++){
		if (!bessie[i]){
			a1.insert(i);
			a2.insert(-i);
		}
	}
	for (int i = 1; i <= n; i++){
		start[i] = start[i - 1];
		auto it = a1.upper_bound(elsie[i]);
		if (it != a1.end()){
			a1.erase(it);
			start[i]++;
		}
	}
	for (int i = n; i >= 1; i--){
		e[i] = e[i + 1];
		auto it = a2.upper_bound(-elsie[i]);
		if (it != a2.end()){
			a2.erase(it);
			e[i]++;
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		ans = max(ans, start[i] + e[i + 1]);
	cout << ans;
	return 0;
}