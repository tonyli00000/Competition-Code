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
int i, j, k;
int main()
{
	int n;
	cin >> n;
	map<char, vector<int>>c;
	for (i = 0; i < n; i++){
		char x;
		int y;
		cin >> x >> y;
		if (c.find(x) == c.end())c[x].resize(2, 0);
		c[x][abs(y)%2]++;
	}
	int B, E, S, I, G, O, M;
	long ret = 0;
	for (B = 0; B < 2; B++){
		for (E = 0; E < 2; E++){
			for (S = 0; S < 2; S++){
				for (I = 0; I < 2; I++){
					for (G = 0; G < 2; G++){
						for (O = 0; O < 2; O++){
							for (M = 0; M < 2; M++){
								if (((B + E + S + S + E + I)*(G + O + E + S)*(M + O + O)) % 2 == 0){
									ret += c['B'][B] * c['E'][E] * c['S'][S] * c['I'][I] * c['G'][G] * c['O'][O] * c['M'][M];
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ret << "\n";
	return 0;
}
