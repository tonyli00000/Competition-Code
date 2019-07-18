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
	while (getline(cin, line)){
		vector<char> f;
		string l;
		stringstream ss(line);
		while (ss >> l)f.push_back(l[0]);
		getline(cin, line);
		
		int ct = 0;
		stringstream sss(line);
		bool flag = true;
		while (sss >> l){
			if (ct == f.size()){
				flag = false;
				break;
			}
			if (l[0] != f[ct++]){
				flag = false;
				break;
			}
		}
		if (flag)cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
