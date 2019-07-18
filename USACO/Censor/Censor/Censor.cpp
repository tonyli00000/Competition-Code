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
void preKmp(string x, int m, vector<long long>kmpNext) {
	int i, j;

	i = 0;
	j = kmpNext[0] = -1;
	while (i < m) {
		while (j > -1 && x[i] != x[j])
			j = kmpNext[j];
		i++;
		j++;
		if (x[i] == x[j])
			kmpNext[i] = kmpNext[j];
		else
			kmpNext[i] = j;
	}
}


void KMP(string x, long long m, string y, long long n) {
	int i, j;
	vector<long long>kmpNext(x.length()+1);

	/* Preprocessing */
	preKmp(x, m, kmpNext);

	/* Searching */
	i = j = 0;
	while (j < n) {
		while (i > -1 && x[i] != y[j])
			i = kmpNext[i];
		i++;
		j++;
		if (i >= m) {
			cout<<j - i;
			i = kmpNext[i];
		}
	}
}
int main()
{
	string txt, pat;
	cin >> pat>>txt;
	KMP(pat, pat.length(),txt,txt.length());
	return 0;
}