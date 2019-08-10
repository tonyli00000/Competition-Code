#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#pragma warning(disable:4996)

#define INF 10000000000
#define MOD 1000000007

#define ALL(a) a.begin(),a.end()
using namespace std;
class Solution {
public:
	bool canConvert(string str1, string str2) {

		if (str1.size() != str2.size())return false;
		if (str1 == str2)return true;
		map<char, char>convert;
		set<char>same;
		map<char, int>ct;
		for (int i = 0; i < str1.size(); i++) {
			if (convert.find(str1[i]) == convert.end()) {
				if (str1[i] == str2[i])same.insert(str1[i]);
				else {
					if (same.find(str1[i]) != same.end())return false;
					convert[str1[i]] = str2[i];
				}
			}
			else {
				if (convert[str1[i]] != str2[i])return false;
			}
			ct[str1[i]]++;
		}
		if (ct.size() >= 26)return false;
		return true;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long

	return 0;
}