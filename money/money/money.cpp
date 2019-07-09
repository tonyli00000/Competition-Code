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

long long ways[30003];
vector<int>coin;
int i, j, k;
void count()
{
	ways[0] = 1;
	for (int i = 0; i < coin.size(); i++)
		for (int j = coin[i]; j < 30001; j++)
			ways[j] += ways[j - coin[i]];
}
int main()
{
	int v, n;
	cin >> v >> n;
	for (i = 0; i < v; i++) {
		int x;
		cin >> x;
		coin.push_back(x);
	}
	count();
	cout << ways[n] << "\n";
	return 0;
}
