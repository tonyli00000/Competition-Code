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
int is_prime(int x)
{
	for (int i = 2; i * i <= x; i++){
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int n, test;
	cin >> test;

	while (test--){
		cin >> n;
		int k = n / 2 + 1;
		while (true){
			if (is_prime(k)){
				cout << k << "\n";
				break;
			}
			k++;
		}
	}
	return 0;
}