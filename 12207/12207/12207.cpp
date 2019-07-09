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
	long long p, c,i,j,k,t=0;
	string line;
	while (cin >> p >> c){
		if (!p && !c)break;
		getline(cin, line);
		cout << "Case " << ++t << ":\n";
		int curr = 1;
		stack<long long>expedite,m;
		map<long long, bool>exp;
		for (i = 0; i < c; i++){
			char a;
			long long b;
			cin >> a;
			
			if (a == 'N'){
				if (expedite.empty()){
					while (exp.find(curr) != exp.end()){
						exp.erase(exp.find(curr));
						curr++;
						if (curr>p)curr = 1;
					}
					cout << curr << "\n";
					curr++;
					if (curr>p)curr = 1;
				}
				else {

					cout << expedite.top() << "\n";
					exp[expedite.top()] = true;

					expedite.pop();
				}
			}
			else {
				cin >> b;
				if (exp.find(b) == exp.end())expedite.push(b);
				exp[b] = true;
			}
		}
	}
	return 0;
}
