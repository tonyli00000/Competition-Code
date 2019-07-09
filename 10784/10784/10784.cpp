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
	long long n,tc=0;
	while (cin >> n && n){
		long long a = 2 * n;
		long long i = 3;
		while (true){
			if (i*(i - 3) >= a)break;
			i++;
		}
		cout <<"Case "<<++tc<<": "<< i << "\n";
	}
	return 0;
}
