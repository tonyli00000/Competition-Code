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
	string s;
	int t, i, j, k, l, n, d, f;
		cin >> t;
		getline(cin, s);
		for (j = 0; j<t; j++){
			if (j != 0)cout << "\n";
			while (getline(cin,s)){
				l = s.length();
				if (l == 0) break;
				for (i = 0; i<l; i++){
					if (s[i] == '4') cout << "A";
					else if (s[i] == '8')cout << "B";
					else if (s[i] == '3')cout << "E";
					else if (s[i] == '6')cout << "G";
					else if (s[i] == '1')cout << "I";
					else if (s[i] == '0')cout << "O";
					else if (s[i] == '9')cout << "P";
					else if (s[i] == '5')cout << "S";
					else if (s[i] == '7')cout << "T";
					else if (s[i] == '2')cout << "Z";
					else cout << s[i];
				}
				cout << "\n";
			}
		}

	return 0;
}