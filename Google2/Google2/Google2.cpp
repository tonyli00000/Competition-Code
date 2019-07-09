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
	vector<pair<int, char>>party;
	int t;
	cin >> t;
	for (int k = 0; k < t; k++){
		int n;
		cin >> n;
		vector<pair<int, int>>party(n);
		int tot = 0;
		for (int i = 0; i < n; i++){
			int x;
			cin >> x;
			party[i] = { x, (i+'A') };
			tot += x;
		}
		cout << "Case #" << k + 1 << ": ";
		while (tot){
			sort(party.begin(), party.end());
			reverse(party.begin(), party.end());
			if ((party[0].first - 1) * 2 <= tot - 1 && party[1].first * 2 <= tot - 1) {
				cout << (char)party[0].second << " ";
				party[0].first--;
				tot--;
			}
			else if (party[0].first>1 && (party[0].first - 2) * 2 <= tot - 2 && party[1].first * 2 <= tot - 2) {
				cout << (char)party[0].second << (char)party[0].second << " ";
				party[0].first -= 2;
				tot -= 2;
			}
			else if ((party[0].first - 1) * 2 <= tot - 2 && party[1].first>0 && (party.size() == 2 || party[2].first * 2 <= tot - 2)) {
				cout << (char)party[0].second << (char)party[1].second << " ";
				party[0].first--;
				party[1].first--;
				tot -= 2;
			}
			else {
				cout << "failed\n";
				break;
			}
		}
		cout << "\n";
	}
	return 0;
}
