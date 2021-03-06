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
#define INF 10000000
#define MOD 1000000007
using namespace std;
class Solution {
public:
	int stoint(string S) {
		int ret = 0, curr = 1;
		for (int i = S.length() - 1; i >= 0; i--) {
			ret += (S[i] - '0')*curr;
			curr *= 10;
		}
		return ret;
	}
	vector<int> splitIntoFibonacci(string S) {
		if (S.size() <= 2)return {};
		for (int i = 0; i<S.length() - 2; i++) {
			for (int j = i + 1; j<S.length() - 1; j++) {
				string x = S.substr(i + 1, j + 1 - i - 1), y = S.substr(0, i + 1);
				if (x.length() > 1 && x[0] == '0')continue;
				if (y.length() > 1 && y[0] == '0')continue;
				int b = stoint(S.substr(i + 1, j+1-i-1)),a= stoint(S.substr(0, i + 1));
				
				bool isTrue = false;
				int index = j + 1;
				int currSum = a+b;
				int curr = j + 1;
				vector<int>ret;
				ret.push_back(a);
				ret.push_back(b);
				bool found;
				while (index<S.length()) {
					found = false;
					while (true) {
						if (index == S.length())break;
						string t = S.substr(curr, index-curr+1);
						if (stoint(t) > currSum)break;
						if (stoint(t) == currSum) {
							found = true;
							ret.push_back(stoint(t));
							currSum = b + stoint(t);
							b = stoint(t);
							break;
						}
						index++;
					}
					if (!found)break;
					curr = ++index;
					//index++;
				}
				if (found) {
					if (curr = S.length()) {
						return ret;
					}
					if (stoint(S.substr(curr)) != currSum);
					else {
						ret.push_back(stoint(S.substr(curr)));
						if (index == S.length()) {
							return ret;
						}
					}
				}
			}
		}
		return {};
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	Solution cls;
	vector<int>x=cls.splitIntoFibonacci("1011");
	return 0;
}


