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

using namespace std;

int main()
{
	long long n;
	//int i, j, k;
	
	while (cin >> n && n != 0) {
		if (n <= 100)cout << "f91(" << n << ") = 91\n";
		else {
			cout << "f91(" << n << ") = "<<n-10<<"\n";
		}
	}
	return 0;
}
