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
	int t,i,j,k;
	cin >> t;
	string temp;
	getline(cin, temp);
	for (k = 0; k < t; k++){
		string l1, l2;
		getline(cin, l1);
		getline(cin, l2);
		cout << "Case " << k + 1 << ": ";
		if (l1 == l2)cout << "Yes\n";
		else{
			string s, a, b;
			stringstream ss(l1);
			while (ss >> a){
				s += a;
			}
			if (s == l2)cout << "Output Format Error\n";
			else cout << "Wrong Answer\n";
		}
	}
	return 0;
}
