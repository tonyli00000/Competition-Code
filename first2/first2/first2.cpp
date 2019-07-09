#include <iostream>
#include <string>
#include <cstring>
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
#pragma warning(disable:4996)
#define MAXN 300005
using namespace std;

struct Trie{
	int ch[26];
	bool flag;
	int len;
};
Trie trie[MAXN];
int n, tot;
string word[MAXN];
vector<string>out;
int ct[26][26];

void buildTree(){
	int i, j, k;
	for (i = 1; i <= n; i++){
		cin >> word[i];
		k = 0;
		for (j = 0; j<word[i].length(); j++){
			if (!trie[k].ch[word[i][j] - 'a'])trie[k].ch[word[i][j] - 'a'] = ++tot;
			k = trie[k].ch[word[i][j] - 'a'];
		}
		trie[k].flag = true;
	}
}
bool dfs(int pos, int k){
	int ret = 0;
	for (int i = 1; i <= ct[pos][0]; i++){
		if (!trie[k].ch[ct[pos][i]] && !ret)ret = dfs(ct[pos][i], k);
		else return true;
	}
	return ret;
}
void check(int x){
	int i, j, k = 0, l,c;
	for (i = 0; i<word[x].size(); i++){
		if (trie[k].flag)return;
		c = trie[k].ch[word[x][i] - 'a'];
		if (dfs(word[x][i] - 'a', k))return;
		for (j = 0; j < 26; j++){
			if (trie[k].ch[j] && j != word[x][i] - 'a'){
				ct[j][0]++;
				ct[j][ct[j][0]] = word[x][i] - 'a';
			}
		}
		k = c;
	}
	out.push_back(word[x]);
}

int main()
{
	freopen("first.in", "r", stdin);
	freopen("first.out", "w", stdout);
	int i, j, k;
	out.clear();
	for (i = 0; i < MAXN; i++){
		trie[i].flag=false;
		trie[i].len = 0;
		for (j = 0; j < 26; j++){
			trie[i].ch[j] = 0;
		}
	}
	tot = 0;
	cin >> n;
	buildTree();
	for (i = 1; i <= n; i++){
		for (j = 0; j < 26; j++){
			for (k = 0; k < 26; k++){
				ct[j][k] = 0;
			}
		}
		check(i);
	}
	cout << out.size() << "\n";
	for (i = 0; i <out.size(); i++)
		cout << out[i] << "\n";
	return 0;
}
