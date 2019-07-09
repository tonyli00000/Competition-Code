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


// CP3: Suffix Array

#define MAX_N 1000050 // second approach: O(n log n)

int RA[MAX_N], tempRA[MAX_N]; // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; // suffix array and temporary suffix array. SA[i] = starting position of i-th suffix in lexicographical order
int RSA[MAX_N]; // RSA[i]: the i-th suffix is in the RSA[i]-ith lexicographically smallest suffix
int c[MAX_N]; // for counting/radix sort
int Phi[MAX_N], LCP[MAX_N], PLCP[MAX_N]; // for LCP counting

class suffix_array {
public:
	string T; // the input string, up to MAX_N characters
	int n; // the length of input string


	void countingSort(int k) { // O(n)
		int i, sum, maxi = max(300, n); // up to 255 ASCII chars or length of n
		memset(c, 0, sizeof c); // clear frequency table
		for (i = 0; i < n; i++) // count the frequency of each integer rank
			c[i + k < n ? RA[i + k] : 0]++;
		for (i = sum = 0; i < maxi; i++) {
			int t = c[i]; c[i] = sum; sum += t;
		}
		for (i = 0; i < n; i++) // shuffle the suffix array if necessary
			tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
		for (i = 0; i < n; i++) // update the suffix array SA
			SA[i] = tempSA[i];
	}

	void constructSA(string s) { // this version can go up to 100000 characters
		int i, k, r;
		T = s;
		n = s.length();
		for (i = 0; i < n; i++) RA[i] = T[i]; // initial rankings
		for (i = 0; i < n; i++) SA[i] = i; // initial SA: {0, 1, 2, ..., n-1}
		for (k = 1; k < n; k <<= 1) { // repeat sorting process log n times
			countingSort(k); // actually radix sort: sort based on the second item
			countingSort(0); // then (stable) sort based on the first item
			tempRA[SA[0]] = r = 0; // re-ranking; start from rank r = 0
			for (i = 1; i < n; i++) // compare adjacent suffixes
				tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
				(RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
			for (i = 0; i < n; i++) // update the rank array RA
				RA[i] = tempRA[i];
			if (RA[SA[n - 1]] == n - 1) break; // nice optimization trick
		}
	}

	void computeLCP() {
		int i, L;
		Phi[SA[0]] = -1; // default value
		for (i = 1; i < n; i++) // compute Phi in O(n)
			Phi[SA[i]] = SA[i - 1]; // remember which suffix is behind this suffix
		for (i = L = 0; i < n; i++) { // compute Permuted LCP in O(n)
			if (Phi[i] == -1) { PLCP[i] = 0; continue; } // special case
			while (T[i + L] == T[Phi[i] + L]) L++; // L increased max n times
			PLCP[i] = L;
			L = max(L - 1, 0); // L decreased max n times
		}
		for (i = 0; i < n; i++) // compute LCP in O(n)
			LCP[i] = PLCP[SA[i]]; // put the permuted LCP to the correct position
	}

	void buildReverseSA() {
		int i;
		for (i = 0; i < n; i++) RSA[SA[i]] = i;
	}
};

suffix_array sa;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	sa.constructSA(s);
	sa.computeLCP();
	int q;
	cin >> q;
	int n = s.length();
	while (q--) {
		int x;
		cin >> x;
		for (int i = 0; i < n; i++) {
			int a = n - SA[i];
			if (x <= a - LCP[i]) {
				int p = 0, q = 0;
				while (x) {
					if (p != LCP[i])p++;
					else x--;
					cout << s[SA[i] + q];
					q++;
				}
			}
			else x -= (a - LCP[i]);
		}
		cout << "\n";
	}

	return 0;
}