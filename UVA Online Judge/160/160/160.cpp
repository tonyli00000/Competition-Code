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

using namespace std;

int main()
{
	int n;
	int prime[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
	int i, j, k,t=0;
	while (cin >> n&& n){
		vector<int>solution;
		int l=-1;
		for (i = 0; i < 25; i++){
			if (prime[i]>n){
				l = i - 1;
				break;
			}
		}
		if (l == -1 && n!=1)l = 25;
		solution.resize(l+1);
		for (i = 0; i <= l; i++){
			j = 1;
			while (pow(prime[i], j) <= n){
				solution[i] += (n / pow(prime[i], j));
				j++;
			}
		}
		cout << setw(3) << n << "! =";
		for (i = 0; i < solution.size(); i++){
			if (i == 15)cout << "\n" << "      ";
			cout << setw(3) << solution[i];
		}
		cout << "\n";
	}

	return 0;
}
