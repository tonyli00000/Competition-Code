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
void count()
{
	int coin[] = { 50, 25, 10, 5, 1};
	ways[0] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = coin[i]; j < 30001; j++)
			ways[j] += ways[j - coin[i]];
}
int main()
{
	int t;
	count();
	while (cin >> t) {
		if (ways[t] > 1)cout << "There are " << ways[t] << " ways to produce " << t << " cents change.\n";
		else cout << "There is only 1 way to produce " << t << " cents change.\n";
	}
	return 0;
}
