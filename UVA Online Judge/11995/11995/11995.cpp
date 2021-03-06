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
	int n,i,j,k;
	while (cin >> n) {
		if (n == 1) {
			int a, b;
			cin >> a >> b;
			if(a==1)cout << "not sure\n";
			else cout << "impossible\n";
		}
		else {
			int arr[1010];
			bool flagpq=true, flagq=true, flags=true;
			priority_queue<int> pq;
			queue<int>q;
			stack<int>s;
			for (k = 0; k < n; k++) {
				int a, b;
				cin >> a >> b;
				if (a == 1) {
					pq.push(b);
					q.push(b);
					s.push(b);
				}
				else {
					if (pq.empty()) {
						flagpq = false;
						flagq = false;
						flags = false;
					}
					else {
						if (pq.top() != b)flagpq = false;
						if (q.front() != b)flagq = false;
						if (s.top() != b)flags = false;
						pq.pop();
						q.pop();
						s.pop();
					}
				}
			}
			if (!flagpq && !flagq && !flags)cout << "impossible\n";
			else {
				if (flagpq && !flagq && !flags)cout << "priority queue\n";
				else {
					if (!flagpq && flagq && !flags)cout << "queue\n";
					else {
						if (!flagpq && !flagq && flags)cout << "stack\n";
						else cout << "not sure\n";
					}
				}
			}
		}
	}
	return 0;
}
