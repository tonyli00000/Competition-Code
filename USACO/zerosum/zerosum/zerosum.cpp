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

map<int, char>operation;
string convert(long long x, int n){
	long long z = x;
	vector<int>power, num;
	int ans = 1;
	int temp = n;
	if (x > pow(3, n + 1))return "COMPLETE";
	while (temp >= 0){
		int y = x / pow(3, temp);
		x -= y*pow(3, temp);
		power.push_back(y);
		if (power.size() > 1 && !power[power.size() - 1] && !power[power.size() - 2])return "COMPLETE";
		temp--;
	}
	bool space = false;
	for (int i = 0; i < power.size(); i++){
		if (i > 0 && !power[i - 1])num.push_back(i * 10 + i + 1);
		else if (power[i] == 0)space = true;
		else num.push_back(i + 1);
	}
	if (space)num.push_back((power.size()) * 10 + power.size() + 1);
	else num.push_back(power.size() + 1);
	int ct = 1;
	if (num[0] != 1)ans = num[0];
	for (int i = 0; i < power.size(); i++){
		if (power[i] == 1)ans += (num[ct]);
		if (power[i] == 2)ans -= (num[ct]);
		if (power[i])ct++;
	}
	if (ans == 0){
		int index = 0;
		for (int i = 0; i < num.size()-1; i++){
			if (num[i]>10)cout << num[i] / 10 << " " << num[i] % 10;
			else cout << num[i];
			cout << operation[power[i]];
		}
		cout << num[num.size()-1]<<"\n";
	}
	return "TRUE";
}
int main()
{
	int n;
	cin >> n;
	operation[1] = '+';
	operation[2] = '-';
	operation[0] = ' ';
	for (int i = pow(3, n - 2); i < pow(3, n - 1); i++){
		convert(i, n - 2);
	}
	return 0;
}
