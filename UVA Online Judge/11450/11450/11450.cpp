//#include <algorithm>
#include <cstdio>
#include <cstring>
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
using namespace std;
int M, C, price[25][25]; 
int memo[210][25];

int shop(int money, int g) {
	if (money < 0) return -1000000000; 
	if (g == C) return M - money; 
	if (memo[money][g] != -1) 
		return memo[money][g];
	int ans = -1000000000;
	for (int model = 1; model <= price[g][0]; model++) 
		ans = max(ans, shop(money - price[g][model], g + 1));
	return memo[money][g] = ans; 
}
int main() { 
	int i, j, TC, score;
	cin >> TC;
	while (TC--) {
		cin >> M >> C;
		for (i = 0; i < C; i++) {
			cin >> price[i][0];
			for (j = 1; j <= price[i][0]; j++) cin >> price[i][j];
		}
		for (i = 0; i < 205; i++) {
			for (j = 0; j < 25; j++) {
				memo[i][j] = -1;
			}
		}
		score = shop(M, 0); 
		if (score < 0) printf("no solution\n");
		else printf("%d\n", score);
	}
	return 0;
}