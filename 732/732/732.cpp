#include <stdio.h>
#include <string.h>
char a[105], b[105], buf[105];
char stk[105], w[105];
int len, stkIdx;
void solve(int idx, int i, int o) {
	if (i == len && o == len) {
		for (int j = 0; j < idx; j++) {
			if (j)   putchar(' ');
			putchar(w[j]);
		}
		puts("");
		return;
	}
	if (i < len) {
		stk[stkIdx++] = a[i];
		w[idx] = 'i';
		solve(idx + 1, i + 1, o);
		stkIdx--;
	}
	if (i > o) {
		if (stk[stkIdx - 1] == b[o]) {
			w[idx] = 'o';
			stkIdx--;
			solve(idx + 1, i, o + 1);
			stkIdx++;
			stk[stkIdx - 1] = b[o];
		}
	}
}
int main() {
	while (gets(a)) {
		gets(b);
		puts("[");
		len = strlen(a), stkIdx = 0;
		if (strlen(a) == strlen(b))
			solve(0, 0, 0);
		puts("]");
	}
	return 0;
}