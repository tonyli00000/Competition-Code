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

using namespace std;

#define INF  1 << 30
#define MAXN 20
int m[MAXN][MAXN];

int solve(int n, int s){
	int tmp[MAXN][MAXN] = { 0 };
	for (int i = 0; i < n; i++){
		if (s & (1 << i))tmp[0][i] = 1;
		else if (m[0][i] == 1)return INF;
	}
	//find tmp
	for (int i = 1; i < n; i++){
		for (int j = 0; j < n; j++){
			int sum = 0;
			if (i > 1)//add above 
				sum += tmp[i - 2][j];
			if (j > 0)//left
				sum += tmp[i - 1][j - 1];
			if (j < n - 1)
				sum += tmp[i - 1][j + 1]; 
			if (sum % 2)tmp[i][j] = 1;
			if (tmp[i][j] == 0 && m[i][j] == 1)	return INF;
		}
	}
	int ct = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (m[i][j] != tmp[i][j])
				ct++;
	return ct;
}

int main(){
	int t, n, ct = 0;
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> m[i][j];
		int ans = INF;
		for (int i = 0; i < (1 << n); i++)//Find status of first line;
			ans = min(ans, solve(n, i));
		if (ans == INF)cout << "Case " << ++ct << ": -1\n";
		else cout << "Case " << ++ct << ": " << ans << "\n";
	}
	return 0;
}
