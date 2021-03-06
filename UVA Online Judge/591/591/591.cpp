#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int t = 0;
	int n;
	while (cin >> n && n != 0) {
		t++;
		vector <int> blocks;
		blocks.resize(n);
		int i, j, k,sum=0;
		for (i = 0; i < n; i++) {
			cin >> k;
			sum += k;
			blocks[i] = k;
		}
		int ct = 0;
		for (i = 0; i < n; i++) {
			if (blocks[i] > sum / n)ct+=blocks[i]-sum/n;
		}
		cout << "Set #" << t << "\n";
		cout << "The minimum number of moves is ";
		cout << ct << ".\n";
		cout << "\n";
	}
	return 0;
}
