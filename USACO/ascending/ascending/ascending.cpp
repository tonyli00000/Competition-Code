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

long long i, j, k;

int main()
{
	for (k = 0; k < 5; k++) {
		stack<int>num;
		vector<long long>sequence;
		string s;
		char temp;
		cin >> temp;
		long long a = 0;
		long long n = temp - '0';
		for (i = n-1; i>=0; i--) {
			char c;
			cin >> c;
			a += (c - '0')*pow(10, i);
		}
		sequence.push_back(a);
		getline(cin, s);
		if (s == "") {
			cout << a << "\n";
			continue;
		}
		for (i = 0; i < s.length(); i++) 
			num.push(s[i] - '0');
		bool added = true;
		while (added) {
			long long b = 0;
			while (b <= sequence[sequence.size() - 1]) {
				b *= 10;
				if (num.empty()) {
					added = false;
					break;
				}
				b += num.top();
				num.pop();
			}
			if(added)sequence.push_back(b);
		}
		for (i = 0; i < sequence.size(); i++) {
			cout << sequence[i];
			if (i == sequence.size() - 1)cout << "\n";
			else cout << " ";
		}
	}
    return 0;
}
vector<vector<int>>x;
int target;
class Solution {
public:
	void generate(int step, int n, vector<int>sol, int sum){
		if (step == n){
			if (sum == target)x.push_back(sol);
			return;
		}
		for (int i = 1; i <= 9; i++){
			if ((sol.empty() && sum + i <= target)){
				sol.push_back(i);
				generate(step + 1, n, sol, sum + i);
				sol.pop_back();
				continue;
			}
			if (sol.empty())continue;
			if ((i>sol[step - 1] && sum + i <= target)){
				sol.push_back(i);
				generate(step + 1, n, sol, sum + i);
				sol.pop_back();
			}
		}
		return;
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		x.clear();
		vector<int>q;
		target = n;
		generate(0, k, q, 0);
		return x;
	}
};

