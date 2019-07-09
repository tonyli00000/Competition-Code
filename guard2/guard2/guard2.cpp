#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cctype>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <utility>
using namespace std;

struct cow {
	long long height, weight, strength;
};

bool comparebystrength(cow a, cow b) { return (a.weight + a.strength < b.weight + b.strength); }


int main()
{
	int N, H;
	vector<cow> cows;
	cin >> N >> H;
	for (int i = 0; i<N; i++) {
		int x, y, z;
		cow tempcow;
		cin >> x>>y>>z;
		tempcow.height = x;
		tempcow.weight = y;
		tempcow.strength = z;
		cows.push_back(tempcow);
	}
	sort(cows.begin(), cows.end(), comparebystrength);
	//for (int i = 0; i<N; i++) {
	//	cout << cows.at(i).height << " " << cows.at(i).weight << " " << cows.at(i).strength << "\n";
	//}
	long long ans = -1;
	for (int i = 0; i<pow(2,N); i++) {
		long long height = 0, safe = 10000000000000000, total = 0;
		for (int j = 0; j<N; j++) {
			if (i&(1 << j)) {
				height += cows.at(j).height;
				safe = min(safe, cows.at(j).strength - total);
				total += cows.at(j).weight;
			}
		}
		if (height >= H && safe >= 0) {
			//cout << i << " " << safe << "\n";
			ans = max(ans, safe);
		}
	}
	if (ans == -1) cout << "Mark is too tall\n";
	else cout << ans << "\n";
	return 0;
}