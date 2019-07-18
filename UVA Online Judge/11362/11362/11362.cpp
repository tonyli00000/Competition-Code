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
	int t, i, j, k, n;
	cin >> t;
	for (k = 0; k < t; k++) {
		cin >> n;
		string phone[10005];
		for (i = 0; i < n; i++)
			cin >> phone[i];
		bool flag = false;
		for (i = 0; i < n; i++) {
			for (j = 0; j < i; j++) {
				int m;
				for (m = 0; m < min(phone[i].length(), phone[j].length()); m++) {
					if (phone[i][m] != phone[j][m])break;
				}
				if (m == min(phone[i].length(), phone[j].length())) {
					flag = true;
					break;
				}
			}
			if (flag)break;
		}
		if (flag)cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
