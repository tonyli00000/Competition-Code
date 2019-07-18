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
	int n,i,j,k;
	while (cin >> n && n){
		vector<pair<string, int>>order;
		vector<string>ret(n);
		for (i = 0; i < n; i++){
			string x, y;
			cin >> x >> y;
			order.push_back(make_pair(x, y.length()));
		}
		int index = -1;
		for (i = 0; i < n; i++){
			int ct = 0;
			while (ct < order[i].second){
				index++;
				if (ret[index%n] == "")ct++;
			}
			ret[index%n] = order[i].first;
		}
		for (i = 0; i < ret.size(); i++){
			cout << ret[i];
			if (i != ret.size() - 1)cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
