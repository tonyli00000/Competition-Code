#include <iostream>
#include <sstream>
using namespace std;
int main()
{
	int T, W, N;
	cin >> T;
	while (T--) {
		cin >> W >> N;
		bool Map[100][100] = { 0 };
		int dp[100][100] = { 0 };
		cin.ignore(); 
		string str;
		for (int i = 1, j; i <= W; ++i) {
			getline(cin, str);
			stringstream ss(str);
			ss >> j;
			while (ss >> j)
				Map[i][j] = true;
		}
		dp[1][1] = 1;
		for (int i = 1; i <= W; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (Map[i][j]) continue;
				if (i > 1) dp[i][j] += dp[i - 1][j];
				if (j > 1) dp[i][j] += dp[i][j - 1];
			}
		}
		cout << dp[W][N] << "\n";
		if (T) cout << "\n";
	}
}