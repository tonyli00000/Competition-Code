#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <set>
#include <functional>

using namespace std;

int main()
{
	int m, n, t = 0,a1[11000],a2[11000];;
	while (cin >> m >> n) {
		if (m == 0 && n == 0)break;
		int min = 100, p = 100;
		for (int i = 0; i < m; i++) {
			int age;
			cin >> age;
			if (age < min)min = age;
			a1[i] = age;
		}
		for (int i = 0; i < n; i++) {
			int age;
			cin >> age;
			if (age < p)p = age;
			a2[i] = age;
		}
		if (m <=n)cout << "Case " << ++t << ": 0\n";
		else {
			cout << "Case " << ++t << ": " << abs(m - n) << " ";
			cout << min << "\n";
			//unordered_map<int, int> p;
			//auto it = p.cbegin(), l = p.cbegin();
			//while (m != 0 && n != 0) {
			//	int spouse = -100, husband;
			//	bool flag = false;
			//	for (it = p.cbegin(); it != p.cend(); it++) {
			//		if (it->second == 0) {
			//			if (flag && abs(spouse - husband) < abs(it->first - husband)) {
			//				p.erase(it);
			//				p.erase(l);
			//				m--;
			//				n--;
			//				break;
			//			}
			//			spouse = it->first;
			//		}
			//		else {
			//			if (!flag) {
			//				husband = it->first;
			//				l = it;
			//			}
			//			flag = true;
			//		}
			//	}
			//}
			//if (p.empty())cout << "Case " << t << ": " << 0 << "\n";
			//else {
			//	auto it = p.begin();
			//	cout << "Case " << t << ": " << p.size() << " " << it->first << "\n";
			//}
		}
	}
	return 0;
}
