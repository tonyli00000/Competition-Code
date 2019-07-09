/*
PROG:job
ID:tonyli21
LANG:C++11
*/
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
#pragma warning(disable:4996)
using namespace std;

int A[30],tA[30],fA[1000],B[30],tB[30],fB[1000];

int main()
{
	freopen("job.in", "r", stdin);
	freopen("job.out", "w", stdout);
	int i,j,k;
	int n, a, b;
	cin >> n >> a >> b;
	for (i = 0; i < a; i++) {
		cin >> tA[i];
		A[i] = tA[i];
	}
	for (i = 0; i < b; i++){
		cin >> tB[i];
		B[i] = tB[i];
	}
	int minn;
	for (i = 0; i < n; i++){
		minn = 0;
		for (k = 1; k < a; k++){
			if (A[minn] > A[k]) minn = k;
		}
		fA[i] = A[minn];
		A[minn] += tA[minn];
	}
	cout << fA[n - 1] << " ";

	for (i = 0; i < n; i++){
		minn = 0;
		for (k = 1; k < b; k++){
			if (B[minn] > B[k]) minn = k;
		}
		fB[i] = B[minn];
		B[minn] += tB[minn];
	}
	int maxx = 0;
	for (i = 0; i < n; i++){
		if (fA[i] + fB[n - i - 1] > maxx){
			maxx = fA[i] + fB[n - i - 1];
		}
	}
	cout << maxx << "\n";
	return 0;
}