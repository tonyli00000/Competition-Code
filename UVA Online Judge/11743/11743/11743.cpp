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
		int n[16];
		for (int i = 0; i < 16; i++){
			char c;
			cin >> c;
			n[i] = c - '0';
			
			if (i % 2 == 0)n[i] *= 2;
		}
		int sum = 0;
		for (int i = 0; i < 16; i++){
			if (n[i]>9)sum += (n[i] % 10 + 1);
			else sum += n[i];
		}
		if (sum % 10 == 0)cout << "Valid\n";
		else cout << "Invalid\n";
	}
	return 0;
}
