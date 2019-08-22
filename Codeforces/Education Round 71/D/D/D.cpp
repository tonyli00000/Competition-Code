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

int query(vector<int>& x) {
	cout << "? ";
	for (auto it : x)cout << it << " ";
	cout << "\n";
	fflush(stdout);
	int a;
	cin >> a;
	return a;
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
//#define int long long
	vector<int>out;
	for (int i = 1; i <= 100; i++) {
		out.push_back(i * (1 << 7));
	}
	int x = query(out); //last 7
	vector<int>out2;
	for (int i = 0; i < 100; i++) {
		out2.push_back(i);
	}
	int y = query(out2); //first 7

	vector<int>b;
	int ret =( x & 127) + (y & (127 * 128));
		
	//for(int i=0;i<7;i++){
	//	b.push_back(x % 2);
	//	x /= 2;
	//}
	//for (int i = 0; i < 7; i++) {
	//	b.push_back(y % 2);
	//	y /= 2;
	//}
	////reverse(b.begin(), b.end());
	//int curr = 1,ret=0;
	//for (int i = 0; i < b.size(); i++) {
	//	ret += b[i] * curr;
	//	curr *= 2;
	//}
	//
	cout << "! "<<ret << "\n";
	fflush(stdout);
	return 0;
}