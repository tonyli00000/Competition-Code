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

int p[30], rk[30];
bool insleep[30];


int main()
{
	int t, i, j, k,c=0;
	while (cin >> t) {
		if (c != 0)cout << "\n";
		else c = 1;
		bool e[30];
		int s[30];
		for (i = 0; i < 30; i++) {
			insleep[i] = true;
			e[i] = true;
			s[i] = 0;
		}
		int n;
		cin >> n;
		set<int> neighbors[30];
		char x, y, z;
		cin >> x >> y >> z;
		insleep[x - 'A'] = false;
		insleep[y - 'A'] = false;
		insleep[z - 'A'] = false;
		for (i = 0; i < n; i++) {
			char a, b;
			cin >> a >> b;
			if (a != b) {
				neighbors[a - 'A'].insert(b - 'A');
				e[a-'A'] = false;
				s[a - 'A'] ++;
				neighbors[b - 'A'].insert(a - 'A');
				e[b - 'A']=false;
				s[b - 'A']++;
			}
		}
		int m=0,year;
		bool flag = true,pre[30];
		while (true) {
			for (i = 0; i < 26; i++) {
				pre[i] = insleep[i];
			}
			flag = true;
			m++;
			//year = m * 3;
			set<int>::iterator it;
			for (i = 0; i < 26; i++) {
				if (!e[i] && s[i] >= 3) {
					int ct = 0;
					for (it = neighbors[i].begin(); it != neighbors[i].end(); it++) {
						if (!insleep[*it] && !pre[*it])ct++;
						if (ct == 3)break;
					}
					if (ct >= 3) {
						insleep[i] = false;
						flag = false;
					}
				}
			}
			if (flag)break;
			for (i = 0; i < 26; i++) {
				if (insleep[i] && s[i]>0) {
					break;
				}
			}
			if (i == 26)break;
		}
		if(t==0)cout << "WAKE UP IN, " << 0 << ", YEARS\n";
		else {
			if (flag == true)cout << "THIS BRAIN NEVER WAKES UP\n";
			else cout << "WAKE UP IN, " << m << ", YEARS\n";
		}
	}
	return 0;
}
