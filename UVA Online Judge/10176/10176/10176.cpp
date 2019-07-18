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
	vector<char>s;
	char c;
	while (true){
		//int i = 0;
		s.clear();
		while (cin >> c && c != '#'){
			s.push_back(c);
		}
		if (s.size() == 0)break;
			int i, j, k;
			long long ans = 0;
			bool first = true;
			for (i = s.size() - 1; i >= 0; i--){
				if (s[i] == '1'){
					j = i;
					j %= 16;
					if (first){
						ans = 1;
						first = false;
					}
					ans *= pow(2, j);
					ans %= 131071;
				}
			}
			if (ans == 0)cout << "YES\n";
			else cout << "NO\n";
	}
	return 0;
}
