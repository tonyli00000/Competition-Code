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

using namespace std;

class Solution2 {
public:
	int minSwap(vector<int> A, vector<int> B) {
		int n = A.size();
		vector<vector<int>>dp(n + 2, vector<int>(2, 0));

		dp[n - 1][1] = 1;
		for (int i = 1; i<n - 1; i++){
			dp[i][0] = INT_MAX;
			dp[i][1] = INT_MAX;
			if (A[i - 1] < A[i] && B[i - 1] < B[i]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
			if (B[i - 1] < A[i] && A[i - 1] < B[i]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
			if(A[i - 1] < B[i] && B[i - 1] < A[i]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
			if (B[i - 1] < B[i] && A[i - 1] < A[i]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
		}
		return *min_element(dp[n-1].begin(), dp[n-1].end());
	}
};
class Solution {
public:
	vector<int> p;
	int s, t;
	vector<int>a;
	bool dfs(int v, vector<vector<int>>& graph) {
		a[v] = 1;
		for (int i = 0; i<graph[v].size(); ++i) {
			int u = graph[v][i];
			if (a[u] == 0) {
				p[u] = v;
				if (dfs(u,graph))  return true;
			}
			else if (a[u] == 1) {
				t = v;
				s = u;
				return true;
			}
		}
		a[v] = 2;
		return false;
	}
	vector<int> eventualSafeNodes(vector<vector<int>> graph) {
		int n = graph.size();

		vector<int>ans;
		set<int>x;
		for (int i = 0; i<graph.size(); i++){
			p.assign(n, -1);
			a.assign(n, 0);
			if (!dfs(i, graph))continue;
				vector<int> cycle;
				x.insert(s);
				cycle.push_back(s);
				for (int v = t; v != s; v = p[v])
					x.insert(v);

				
		}
		for (int i = 0; i < n; i++){
			if (x.find(i) == x.end())ans.push_back(i);
		}
		return ans;
	}
};
int main()
{
	Solution2 cls;
	cout<<cls.minSwap({ 1, 3, 5, 4 }, { 1, 2, 3, 7 });
	return 0;
}


