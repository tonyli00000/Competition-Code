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
	int n,t=0;
	while (cin >> n && n >= 0){
		cout << "Case " << ++t << ": ";
		int i;
		for (i = 0; i <= 14; i++){
			if (pow(2, i) >= n){
				cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}
