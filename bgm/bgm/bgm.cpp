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
long long num[128][7];
int main()
{
	long long n,i,j,k;
	for (i = 0; i < 128; i++) {
		for (j = 0; j < 7; j++) {
			num[i][j] = 0;
		}
	}
	cin >> n;
	for (i = 0; i < n; i++) {
		char x;
		long long y;
		cin >> x >> y;
		num[x][(y+7)%7]++;
	}
	long long ans = 0;
	for (int B = 0; B < 7; B++)
		for (int E = 0; E < 7; E++)
			for (int S = 0; S < 7; S++)
				for (int I = 0; I < 7; I++)
					for (int G = 0; G < 7; G++)
						for (int O = 0; O < 7; O++)
							for (int M = 0; M < 7; M++) {
								if (((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O)) % 7 == 0) {
									ans += num['B'][B] * num['E'][E] * num['S'][S] * num['I'][I] *
										num['G'][G] * num['O'][O] * num['M'][M];
								}
							}
	cout << ans << "\n";
	/*long long ways = 1;
	for (i = 0; i < 26; i++) {
		if (c[i] != 0)ways *= (c[i]+1);
	}
	ways--;
	for (i = 0; i < 26; i++) {
		if (c[i] == 0 && v[i].size() != 0)ways *= v[i].size();
	}
	cout << ways << "\n";*/
	return 0;
}
