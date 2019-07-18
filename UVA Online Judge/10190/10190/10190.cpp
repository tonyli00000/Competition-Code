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
	long long n, m;
	while (cin >> n >> m) {
		long long i=0;
		if(n<2 || m<2 || n<m)cout << "Boring!\n";
		else {
			bool istrue = true;
			vector<long long>v;
			v.push_back(n);
			while (n > 1) {
				if (n%m != 0) {
					istrue = false;
					break;
				}
				else v.push_back(n / m);
				n /= m;
			}
			if (!istrue)cout << "Boring!\n";
			else {
				for (int i = 0; i < v.size() - 1; i++) {
					cout << v[i] << " ";
				}
				cout << v[v.size() - 1] << "\n";
			}
		}
	}
	return 0;
}
