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

int main()
{
	int n;
	while (cin >> n && n != 0) {
		int age[102];
		for (int i = 1; i < 101; i++)
			age[i] = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			age[x]++;
		}
		for (int i = 1; i <= 100; i++) {
			for (int j = 0; j < age[i]; j++) {
				if (i!=1 || j!=0)cout << " ";
				cout << i;
			}
		}
		cout << "\n";
	}
	return 0;
}
