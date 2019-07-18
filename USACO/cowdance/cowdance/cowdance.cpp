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
vector<long long>cow;
long long i, j, k;
long long n, timelimit;

class Compare {
public: bool operator()(long long a, long long b)
{
	return (a >= b);
}
};


int main()
{
	cin >> n >> timelimit;
	for (i = 0; i < n; i++) {
		long long x;
		cin >> x;
		cow.push_back(x);
	}
	for (i = 1;; i++) {
		priority_queue<long long, vector<long long>, Compare>z;
		long long time = 0,index=0;
		
		while (index < n) {
			while (z.size() < i) {
				z.push(time+cow[index]);
				index++;
			}
			time = z.top();
			while(!z.empty() && z.top()<=time)z.pop();
		}
		while (!z.empty()) {
			time = z.top();
			z.pop();
		}
		if (time <= timelimit)break;
	}
	cout << i << "\n";
    return 0;
}

