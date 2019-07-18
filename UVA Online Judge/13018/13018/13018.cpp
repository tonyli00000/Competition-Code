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
	int x, y;
	bool first = true;
	while (cin >> x >> y){
		if (!first)cout << "\n";
		else first = false;
		vector<int>outcomes;
		outcomes.resize(x + y + 2, 0);
		for (int i = 1; i <= x; i++){
			for (int j = 1; j <= y; j++){
				outcomes[i + j]++;
			}
		}
		vector<int>result;
		int max = 0;
		for (int i = 2; i <= x + y; i++){
			if (outcomes[i] > max){
				result.clear();
				result.push_back(i);
				max = outcomes[i];
			}
			else if (outcomes[i] == max)result.push_back(i);
		}
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << "\n";
	}
	return 0;
}
