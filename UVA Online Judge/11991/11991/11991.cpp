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

vector<int> p[1000005];
int main()
{
	long m, n,i,j,k;
	while (cin >> m >> n) {
		long fre[1000005];
		for (i = 0; i < 1000005; i++)fre[i] = 0;
		for (i = 0; i < m; i++)p[i].clear();
		for (i = 0; i < m; i++) {
			int x;
			cin >> x;
			fre[x]++;
			p[x].resize(p[x].size()+1, i + 1);
		}
		for (i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			if (fre[b] < a)cout << "0\n";
			else {
				cout << p[b][a-1]<<"\n";
			}
		}
	}
	return 0;
}
