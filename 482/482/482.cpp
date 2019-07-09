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
	int t;
	cin >> t;
	string line;
	getchar();
	while (t--) {
		vector<double>num;
		string line,sa;

		getchar();
		getline(cin, line);
		stringstream ss(line);
		vector<string>index,r;
		vector<pair<string, string>>arr;
		vector<int>innum;
		while (ss >> sa) {
			index.push_back(sa);
		}
		getline(cin, line);
		stringstream sb(line);
		while (sb >> sa) {
			r.push_back(sa);
		}
		

		for (int i = 0; i < min(index.size(),r.size()); i++) {
			arr.push_back(make_pair(index[i],r[i]));
		}
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size();i++){
			cout << arr[i].second<< "\n";
		}
		if (t)cout << "\n";
	}
    return 0;
}

