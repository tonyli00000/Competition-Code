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
	int m, n,i,j,k;
	while (cin >> m >> n){
		map<string, string>irr;
		for (i = 0; i < m; i++){
			string a, b;
			cin >> a >> b;
			irr[a] = b;
		}
		for (i = 0; i < n; i++){
			string a;
			cin >> a;
			if (irr.find(a) != irr.end())cout << irr[a] << "\n";
			else{
				if (a.length() == 1){
					if (a == "o" || a == "s" || a == "x")cout << a + "es" << "\n";
					else cout << a + "s" << "\n";
				}
				else{
					char x = a[a.length() - 2], y = a[a.length() - 1];
					string b = string()+x + y;
					if (b == "ch" || b == "sh")cout << a + "es" << "\n";
					else{
						if (b[1] == 'y' && (b[0] != 'a' && b[0] != 'e' && b[0] != 'i' && b[0] != 'o' && b[0] != 'u')){
							a.erase(a.length() - 1, 1);
							cout << a + "ies" << "\n";
						}
						else cout << a + "s" << "\n";
					}
				}
			}
		}
	}
	return 0;
}
