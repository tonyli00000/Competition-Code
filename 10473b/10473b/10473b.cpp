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
	string line;
	int i, j, k;
	while (getline(cin, line) && line[0] != '-') {
		bool ishex = false;
		if (line[0] == '0'&&line[1] == 'x') {
			ishex = true;
			line.erase(0, 2);
		}
		long long n = 0,m=1;
		for (i = line.length() - 1; i >= 0; i--) {
			n += m*(line[i] - '0');
			m *= 10;
		}
		int largest = 0;
		long long ans = 0;
		j = 1;
		if (ishex) {
			for (i = line.length() - 1; i >= 0; i--) {
				ans += j*(line[i] - '0');
				j *= 16;
			}
			cout << ans << "\n";
		}
		else {
			long long q = n;
			while (q /= 16) {
				largest++;
			}
			int out[100];
			for (i = 0; i <= largest; i++) {
				long long l = pow(16, largest - i);
				out[i] = n / pow(16, l);
				n -= out[i] * pow(16, l);
			}
			for (i = 0; i <= largest; i++) {
				cout << out[i];
			}
			cout << "\n";
			
		}
	}
	return 0;
}
