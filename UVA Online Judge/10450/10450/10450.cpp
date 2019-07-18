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
	int t,tc=0;
	vector<long long> solution;
	solution.push_back(1);
	solution.push_back(2);
	for (int i = 2; i <= 51; i++){
		solution.push_back(solution[i - 1] + solution[i - 2]);
	}
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		cout << "Scenario #" << ++tc << ":\n" << solution[n] << "\n\n";
	}
	return 0;
}
