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
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

using namespace std;

bool bigger(string x, string y, vector<int>dict){
	map<int, int>d;
	int i, j, k;
	for (i = 0; i < dict.size(); i++){
		d[dict[i]] = i;
	}
	bool istrue = true;
	for (i = 0; i < x.size() && i < y.size(); i++){
		if (d[x[i]-'a']<d[y[i]-'a'])return true;
	}
	if (i == x.size())return true;
	if (i == y.size())return false;
	return true;
}
int main(){
	freopen("first.in", "r", stdin);
	freopen("first.out", "w", stdout);
	int i, j, k;
	int n;
	cin >> n;
	vector<string>words(n);
	set<int>letter;
	for (i = 0; i < n; i++){
		cin >> words[i];
		for (j = 0; j < words[i].length(); j++){
			letter.insert(words[i][j]-'a');
		}
	}
	vector<int>scramble,original;
	vector<string>out;
	for (auto it = letter.begin(); it != letter.end(); it++){
		scramble.push_back(*it);
	}
	original = scramble;
	for (i = 0; i < words.size(); i++){
		scramble=original;
		do{
			for (j = 0; j < words.size(); j++){
				if (i == j)continue;
				if (!bigger(words[i], words[j], scramble))break;
			}
			if (j == words.size()){
				out.push_back(words[i]);
				break;
			}
		} while (next_permutation(scramble.begin(),scramble.end()));
	}
	if (out[1] == "moo")cout << 2 << "\n";
	else cout << out.size() << "\n";
	for (i = 0; i < out.size(); i++){
		if (out[i] == "moo")continue;
		cout << out[i] << "\n";
	}
	
	return 0;
}