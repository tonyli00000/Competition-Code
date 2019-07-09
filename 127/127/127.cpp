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
struct card{
	char value;
	char suit;
};

int main()
{
	vector<stack<card>>piles(52);
	while (true){
		card f;
		cin >> f.value;
		if (f.value == '#')break;
		cin >> f.suit;
		piles[0].push(f);
		for (i = 1; i < 52; i++){
			card x;
			cin >> x.value>>x.suit;
			piles[i].push(x);
		}
		bool adjust = true;
		while (adjust){
			adjust = false;
			for (i = 0; i < piles.size(); i++){
				if (piles[i].empty())continue;
				if (!piles[i].empty() && i > 0 && !piles[i - 1].empty()){
					card a = piles[i].top(), b = piles[i - 1].top();
					if (a.value == b.value || a.suit == b.suit){
						piles[i].pop();
						piles[i - 1].push(a);
						adjust = true;
						if (piles[i].empty()){
							piles.erase(piles.begin() + i);
							i -=1;
							continue;
						}
						i -= 2;
						continue;
					}
				}
				if (!piles[i].empty()&&i > 2 && !piles[i - 3].empty()){
					card a = piles[i].top(), b = piles[i - 3].top();
					if (a.value == b.value || a.suit == b.suit){
						piles[i].pop();
						piles[i - 3].push(a);
						adjust = true;
						if (piles[i].empty()){
							piles.erase(piles.begin() + i);
							i = i-3;
							continue;
						}
						i -= 3;
						continue;
					}
				}
			}
		}
		for (i = 0; i < piles.size(); i++){
			cout << piles[i].top().suit<<piles[i].top().value << "\n";
		}
		vector<int>out;
		for (i = 0; i < piles.size(); i++){
			if (!piles[i].empty())out.push_back(piles[i].size());
		}
		cout << out.size() << " piles remaining:";
		for (i = 0; i < out.size(); i++){
			cout << " " << out[i];
		}
		cout << "\n";
	}
	return 0;
}
