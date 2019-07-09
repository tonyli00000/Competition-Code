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

#define MAXN 30  

int vis[MAXN], N, T, f[MAXN], rk[MAXN], in[MAXN], out[MAXN];

void init() 
{
	for (int i = 0; i<MAXN; i++)
		f[i] = i, rk[i] = 0;
}

int find(int x)
{
	int r = x;
	while (f[r] != r)
		r = f[r];
	f[x] = r;
	return r;
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	if (rk[x] > rk[y]){
		f[y] = x;
	}
	else{
		if (rk[x] == rk[y]) {
			rk[y]++;
		}
		f[x] = y;
	}
}

int main(){

	cin >> T;
	while (T--){
		for (int i = 0; i < 30; i++){
			in[i] = 0;
			out[i] = 0;
		}

		string s;
		init();
		cin >> N;
		for (int i = 0; i<N; ++i){
			cin >> s;
			++out[s[0] - 'a'];
			++in[s[s.length() - 1] - 'a'];
			Union(s[0] - 'a', s[s.length() - 1] - 'a');
		}

		int cnt = 0;
		for (int i = 0; i<27; ++i){
			if ((in[i] || out[i]) && f[i] == i)
				++cnt;
		}

		bool flag = true;
		if (cnt != 1) flag = false;

		int num1 = 0, num2 = 0;
		for (int i = 0; i<MAXN; ++i){
			if (!flag) break;
			if (in[i] != out[i]){
				if (in[i] == out[i] + 1) { ++num1; }
				else if (out[i] == in[i] + 1) { ++num2; }
				else { flag = false; break; }
			}
		}

		if (num1 && num2 && num1 + num2>2) flag = false;

		if (flag)cout<<"Ordering is possible.\n";
		
		else cout<<"The door cannot be opened.\n";
		
	}
	return 0;
}