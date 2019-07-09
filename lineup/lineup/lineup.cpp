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
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

using namespace std;
const int N = 100100;

vector<int>num(100005);

map<int, int>mp;

int q[N];

int main()
{

	int n, k;
	cin >> n >> k;
	int i, ans = 0, head = 1, tail = 1;
	int pos = 0;
	for (i = 1; i <= n; ++i)cin >> num[i];
	for (i = 1; i <= n; ++i){
		if (!mp[num[i]])pos++; mp[num[i]]++;
		while (pos>k&&head<tail){
			if (!(--mp[num[q[head++]]]))pos--; 
		}
		ans = max(mp[num[i]], ans);
		q[tail++] = i;
	}
	cout << ans << "\n";
	return 0;
}