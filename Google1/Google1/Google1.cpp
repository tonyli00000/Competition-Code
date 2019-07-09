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
	while (t--){
		int x, y;
		cin >> x >> y;
		int n;
		cin >> n;
		string s=""; 
		while (s != "CORRECT"){
			int mid = x + (y - x) / 2;
			cout << mid << "\n";
			cin >> s;
			if (s == "TOO_SMALL")x = mid+1;
			if (s == "TOO_BIG")y=mid-1;
		}
	}
	return 0;
}
