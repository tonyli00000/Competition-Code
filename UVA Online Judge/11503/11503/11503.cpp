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

//vector<long> p;
map<string, string> p;
map<string,long> rk;
map<string,long> s;

string findset(string i) {
	return(p[i] == i) ? i : (p[i] = findset(p[i]));
}

void changeset(string m, string n) {
	if (p[m] == m) {
		p[m] = n;
		rk[p[m]] = rk[n] - 1;
		return;
	}
	else {
		p[m] = n;
		rk[p[m]] = rk[n] - 1;
		changeset(p[m], n);
	}
}
long unionset(string q, string w) {
	string x = findset(q), y = findset(w);
	if (rk[x] > rk[y]) {
		s[x] += s[y];
		p[y] = p[x];
		//changeset(w, x);
		return s[x];
	}
	else {
		if (rk[x] == rk[y])rk[y]++;
		s[y] += s[x];
		p[x] = p[y];
		//changeset(q, y);
		return s[y];
	}
}
int main()
{
	long t,i,j,k;
	cin >> t;
	for (k = 0; k < t;k++){
		long n;
		cin >> n;
		p.clear();
		rk.clear();
		s.clear();
		string a, b;
		for (j = 0; j < n; j++) {
			cin >> a >> b;
			if (p.find(a) != p.end());
			else {
				p[a] = a;
				rk[a] = 0;
				s[a] = 1;
			}
			if (p.find(b) != p.end());
			else {
				p[b] = b;
				rk[b] = 0;
				s[b] = 1;
			}
			string r = findset(a);
			string q = findset(b);
			if (r!=q)cout<<unionset(r, q)<<"\n";
			else cout << s[r] << "\n";
		}
	}
	return 0;
}
