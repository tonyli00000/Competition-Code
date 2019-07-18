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
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
using namespace std;

int len;
char s[maxN];

bool Check(int base) {
	uint64 n = 0;
	REP(i, len)
		n = n*base + (s[i] - 48);
	uint64 nn = (uint64)sqrt(n);
	return (nn*nn == n);
}

main() {
	//    FileIn("test"); FileOut("test");
	while (gets(s)) {
		len = strlen(s);
		if (len == 1 && s[0] == '0') break;
		int Max = 0;
		REP(i, len) Max = max(Max, s[i] - 48); Max++;
		FOR(i, Max, 100)
			if (Check(i)) {
				printf("%d\n", i);
				break;
			}
	}
}

