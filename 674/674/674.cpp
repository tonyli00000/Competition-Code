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

long long ways[7500];
void count()
{
	int coin[] = { 50, 25, 10, 5, 1 };
	ways[0] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = coin[i]; j < 7500; j++)
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
