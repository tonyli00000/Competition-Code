/*
ID: tonyli21
PROG: nuggets
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
bool dp[1000000];
int rec[20];
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int main(){
	freopen("nuggets.in","r",stdin);
	freopen("nuggets.out","w",stdout);
	while (cin>>n){
		bool f = false;
		int minn = 256;
		for (int i = 0; i<n; i++){
			cin >> rec[i];
			minn = min(minn, rec[i]);
			if (rec[i] == 1)f = true;
		}
		if (n == 1 || f){
			cout << 0 << "\n";
			continue;
		}
		int ans = rec[0];
		for (int i = 1; i<n; i++)ans = gcd(ans, rec[i]);
		if (ans != 1){
			cout << 0 << "\n";
			continue;
		}
		for (int i = 0; i < 1000000; i++){
			dp[i] = 0;
		}
		dp[0] = true;
		for (int i = 0; i<n; i++){
			for (int j = 0; j<1000000 - rec[i]; j++){
				if (dp[j])dp[j + rec[i]] = true;
			}
		}
		ans = -1;
		int num = 0;
		for (int i = 1; i<1000000; i++){
			if (dp[i]){
				num++;
			}
			else{
				ans = i;
				num = 0;
			}
			if (num >= minn)break;
		}
		cout << ans << "\n";
	}
}