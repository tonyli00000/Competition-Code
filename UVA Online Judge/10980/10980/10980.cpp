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

double min(double x, double y) {
	if (x < y)return x;
	else return y;
}
int main()
{
	string line;
	int i, j, k;
	double x;
	int y,t=0;
	while (cin >> x >> y) {
		double price[500];
		for (i = 2; i < 205; i++)price[i] = 20000;
		price[1] = x;
		price[0] = 0;
		for (i = 0; i < y; i++) {
			int m;
			cin >> m;
			cin >> x;
			price[m] = min(price[m], x);
		}
		for (i = 2; i <= 200; i++) {
			for (j = 0; j < i; j++) {
				price[i] = min(price[i], price[i - j] + price[j]);
			}
		}
		for (i = 199; i; i--) {
			price[i] = min(price[i], price[i + 1]);
		}
		getline(cin, line);
		getline(cin, line);
		string ss;
		stringstream l(line);
		cout << "Case " << ++t << ":\n";
		while (l >> ss) {
			int m = 1,num=0;
			for (i = ss.length() - 1; i >= 0; i--) {
				num += m*(ss[i] - '0');
				m *= 10;
			}
			cout << "Buy "<<num<<" for $"<<fixed<<setprecision(2)<<price[num] << "\n";
		}
	}
	return 0;
}
