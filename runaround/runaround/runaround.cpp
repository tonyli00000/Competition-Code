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

string rev(string x){
	for (int i = 0; i < x.length() / 2; i++){
		char temp = x[i];
		x[i] = x[x.length() - i-1];
		x[x.length() - i - 1] = temp;
	}
	return x;
}
bool isRunRound(string str) {
	

	int freq[10];
	for (int i = 0; i < 10; i++)
		freq[i] = 0;

	int len = str.length();
	int curr = str[0] - '0';
	int index = 0;

	for (int i = 0; i < len; i++) {
		index = (index + curr) % len;
		curr = str[index] - '0';
		freq[curr]++;
		if (!curr || freq[curr] > 1) return false;
	}

	return true;
}
int main()
{
	string m;
	cin >> m;
	m=rev(m);
	while (true){
		if (m[0] == '9'){
			int i=0;
			while (m[i] == '9'){
				if (i == m.length() - 1)m.insert(m.length()-1,"1");
				m[i] = '0';
				m[i + 1]++;
			}
		}
		else m[0]++;
		if (isRunRound(rev(m)))break;
	}
	cout << rev(m) << "\n";
	return 0;
}

