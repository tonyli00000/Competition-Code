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
#include <bitset>
using namespace std;

vector<string> prim;
vector<int>len;
int main()
{
	string x,key;
	while (cin >> x && x != "."){
		prim.push_back(x);
		len.push_back(x.length());
	}
	bitset < 200005 > dp;
	for (long long i = 0; i < key.length() + 2; i++)
		dp[i] = 0;
	cin >> key;
	dp[0] = 1;
	long long maxx = 0;
	for (long long i = 0; i < key.length(); i++){
		if (dp[i]){
			maxx = max(maxx, i);
			for (int j = 0; j < prim.size(); j++){
				int k;
				for (k = 0; k < prim[j].length(); k++){
					if (prim[j][k] != key[i + k])break;
				}
				if (k == prim[j].length())dp[i + k] = 1;
			}
		}
	}
	cout << maxx << "\n";
	return 0;
}
