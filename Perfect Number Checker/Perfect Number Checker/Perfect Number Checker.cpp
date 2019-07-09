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


#define MAXN 1000000000
using namespace std;
long i, j, k, a[10000],top, i2;
int prime[25000];
bool p[25000];

void generatePrime(){
	prime[0] = 2;
	p[0] = false;
	p[1] = false;
	p[2] = true;
	top = 1;
	for (i = 3; i < MAXN; i += 2) p[i] = true;
	for (i = 3; i < MAXN; i += 2){
		if (p[i]) {
			prime[top] = i;
			top++;
			i2 = i + i;
			for (j = i * 3; j < MAXN; j += i2) p[j] = false;
		}
	}
}
bool checkPerfect(long long x){
	long long copy = x;
	vector<pair<int,int>>factor;
	map<int, int>ind;
	int curr = 0;
	while (x){
		while (x%prime[curr] == 0){
			if (ind.find(curr) == ind.end()){
				ind[curr] = ind.size();
				factor[ind[curr]].second = prime[curr];
			}
			factor[ind[curr]].first++;
			x /= prime[curr];
		}
		curr++;
	}
	long long product = 1;
	for (int i = 0; i < factor.size(); i++){
		long long sum = 0,c=1;
		for (int j = 0; j < factor[i].first; j++){
			sum += c;
			c *= factor[i].second;
		}
		product *= sum;
	}
	return product == copy*2;
}
int main()
{
	generatePrime();
	cout << checkPerfect(6) << "\n";
	return 0;
}