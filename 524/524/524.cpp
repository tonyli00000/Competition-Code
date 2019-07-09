#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define N 23
using namespace std;
bool p[N];
int prime[50],top,solution[N];
int isprime(long long key)
{
	long i;
	for (i = 0; i < top; i++)
		if ((key % prime[i] == 0)&&(key!=prime[i])) return 0;
	return 1;
}

void solve(int step, int n,int ans[N]){
	int i, j, k,b;
	if (step == n){

		if (isprime(1 + ans[n - 1])==1){
			for (i = 0; i < n-1; i++)cout << ans[i]<<" ";
			cout << ans[n - 1];
			cout << "\n";
		}
		return;
	}
	for (i = 2; i <= n; i++){
		if (p[i]){
			ans[step] = i;
			k = ans[step] + ans[step - 1];
			if (isprime(k)==1){
				p[i] = false;
				solve(step + 1, n, ans);
				p[i] = true;
			}
		}
	}
}
int main()
{
	int n,i,j,k,b=0;
	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	prime[3] = 7;
	top = 4;
	while (cin >> n){
		if (b != 0)cout << "\n";
		b++;
		for (i = 0; i <= n; i++)p[i] = true;
		solution[0] = 1;
		cout << "Case " << b << ":" << "\n";
		solve(1, n,solution);
	}
	return 0;
}
