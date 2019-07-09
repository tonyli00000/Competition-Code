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

long long ways[10002];
void count()
{
	int coin[21] = { 9261,8000,6859,5832,4913,4096,3375,2744,2197,1728,1331,1000,729, 512,343,216,125,64, 27, 8, 1 };
	ways[0] = 1;
	for (int i = 0; i < 21; i++)
		for (int j = coin[i]; j < 10000; j++)
			ways[j] += ways[j - coin[i]];
}
int main()
{
	int t;
	count();
	while (cin >> t) {
		cout << ways[t] << "\n";
	}
	return 0;
}
