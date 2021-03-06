#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>

using namespace std;

int main()
{
	int t,i,j,k,num;
	cin >> t;
	for (k = 0; k < t; k++) {
		int m, n;
		cin >> m >> n;
		queue <int> jobs;
		int importance[110];
		for (i = 0; i < 110; i++)importance[i] = 0;
		for (i = 0; i < m; i++) {
			int p;
			cin >> p;
			if (i == n) {
				num = p;
				jobs.push(-1);
			}
			else jobs.push(p);
			importance[i]=p;
		}
		int ct = 0;
		while (!jobs.empty()) {
			int max = 0;
			bool flag = false;
			if (jobs.front() == -1)flag = true;
			int ind = 0;
			if (flag) {
				for (i = 0; i < m; i++) {
					if (importance[i] > max) {
						max = importance[i];
						ind = i;
					}
				}
			}
			else {
				for (i = 0; i <m; i++) {
					if (importance[i] > max) {
						max = importance[i];
						ind = i;
					}
					
				}
			}
			if (!flag) {
				if (max > jobs.front()) {
					jobs.push(jobs.front());
					jobs.pop();
				}
				else {
					ct++;
					importance[ind]=0;
					jobs.pop();
				}
			}
			else {
				if (max > num) {
					jobs.push(jobs.front());
					jobs.pop();
					flag = false;
				}
				else {
					ct++;
					cout << ct << "\n";
					break;
				}
			}
		}
	}
	return 0;
}
