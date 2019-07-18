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
	int c = 0;
	while (t--){
		string st;
		cin >> st;
		vector<int>ct(26, 0);
		int pos = 0;
		stack<char>s;
		for (i = 0; i < st.length(); i++){
			if (s.empty() || s.top() != st[i]-'A'){
				s.push(st[i]-'A');
				ct[st[i]-'A']++;
			}
			else {
				s.pop();
				if (!s.empty())ct[s.top()]++;
			}
		}
		cout << "Case " << ++c << "\n";
		ct[st[0]-'A']--;
		for (i = 0; i < 26; i++){
				if (ct[i])cout << (char)(i+'A')<<" = " << ct[i] << "\n";
		}
	}
	return 0;
}
