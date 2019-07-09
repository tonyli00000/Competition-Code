#include<stdio.h>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define DBG 0
using namespace std;

//bool trav[10000];
int LM, N;
int top[50];
bool isSqr(int c) {
	int a = int(sqrt(c));
	return a*a == c;
}
void DFS(int cur, int len) {
	if (cur - 1>LM)LM = cur - 1;
	int b;
	rep(i, min(len + 1, N)) {
		if (cur>LM - N && (isSqr(top[i] + cur) || top[i] == 0)) {
			if (DBG)printf("LM-N top cur loc %d %d %d %d\n", LM - N, top[i], cur, i);
			b = top[i], top[i] = cur;
			DFS(cur + 1, min(max(i + 2, len), N));
			top[i] = b;
		}
	}
}
void ans() {
	LM = 0;
	DFS(1, 1);
	printf("%d\n", LM);
}
int main() {
	int n;
	scanf("%d", &n);
	rep(i, n)scanf("%d", &N), ans();
}