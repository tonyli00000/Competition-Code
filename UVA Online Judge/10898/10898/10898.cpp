
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
int A[10];
int B[10][10], cB[10];
int I, C;
map<int, int> dp;
int dfs(int state) {
	if (state == 0)  return 0;
	if (dp.find(state) != dp.end())
		return dp[state];
	int &val = dp[state];
	val = 0xfffffff;
	int v[6] = {}, i, j, xx;
	for (i = I - 1; i >= 0; i--)
		v[i] = state % 10, state /= 10;
	for (i = 0; i < C; i++) {
		for (j = 0; j < I; j++)
			if (v[j] < B[i][j])
				break;
		if (j != I)  continue;
		xx = 0;
		for (j = 0; j < I; j++) {
			v[j] -= B[i][j];
			xx = xx * 10 + v[j];
		}
		val = min(val, dfs(xx) + cB[i]);
		for (j = 0; j < I; j++)
			v[j] += B[i][j];
	}
	for (i = 0; i < I; i++) {
		if (v[i] == 0)   continue;
		v[i]--;
		xx = 0;
		for (j = 0; j < I; j++)
			xx = xx * 10 + v[j];
		val = min(val, dfs(xx) + A[i]);
		v[i]++;
	}
	return val;
}
int main() {
	int i, j;
	while (scanf("%d", &I) == 1) {
		for (i = 0; i < I; i++)
			scanf("%d", &A[i]);
		scanf("%d", &C);
		for (i = 0; i < C; i++) {
			for (j = 0; j < I; j++)
				scanf("%d", &B[i][j]);
			scanf("%d", &cB[i]);
		}
		int q, x;
		scanf("%d", &q);
		dp.clear();
		while (q--) {
			int xx = 0;
			for (i = 0; i < I; i++) {
				scanf("%d", &x);
				xx = xx * 10 + x;
			}
			printf("%d\n", dfs(xx));
		}
	}
	return 0;
}