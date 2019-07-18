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
int i, j, k;
map<char, int>letter;
vector<pair<int,string>>combo;

string findstr(int x){
	string res = "";
	for (int i = 0; i < combo.size(); i++){
		while (combo[i].first <= x){
			res += combo[i].second;
			x -= combo[i].first;
		}
	}
	return res;
}
int main()
{
	string ans = "IVXLCDM";
	combo.push_back(make_pair(1000, "M"));
	combo.push_back(make_pair(900, "CM"));
	combo.push_back(make_pair(500, "D"));
	combo.push_back(make_pair(400, "CD"));
	combo.push_back(make_pair(100, "C"));
	combo.push_back(make_pair(90, "XC"));
	combo.push_back(make_pair(50, "L"));
	combo.push_back(make_pair(40, "XL"));
	combo.push_back(make_pair(10, "X"));
	combo.push_back(make_pair(9, "IX"));
	combo.push_back(make_pair(5, "V"));
	combo.push_back(make_pair(4, "IV"));
	combo.push_back(make_pair(1, "I"));

	letter['I'] = 0;
	letter['V'] = 0;
	letter['X'] = 0;
	letter['L'] = 0;
	letter['C'] = 0;
	letter['D'] = 0;
	letter['M'] = 0;
	int n;
	cin >> n;
	for (i = 1; i <= n; i++){
		string temp = findstr(i);
		for (j = 0; j < temp.length(); j++){
			letter[temp[j]]++;
		}
	}
	for (i=0; i<ans.length(); i++){
		if (letter[ans[i]]>0)cout << ans[i] << " " << letter[char(ans[i])] << "\n";
	}
	return 0;
}
