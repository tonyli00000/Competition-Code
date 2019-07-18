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
	int tc,t=0,i,j,k;
	cin >> tc;
	while (tc--) {
		string today, birth;
		int m1, d1, y1, m2, d2, y2;
		cin >> today >> birth;
		for (i = 0; i < today.length(); i++) {
			if (today[i] == '/') {
				today[i] = ' ';
				birth[i] = ' ';
			}
		}
		stringstream ss(today);
		string a, b,c,d,e,f;
		ss >> a >> b >> c;
		d1 = (a[0] - '0') * 10 + a[1] - '0';
		m1 = (b[0] - '0') * 10 + b[1] - '0';
		y1= (c[0] - '0') * 1000 + (c[1] - '0') * 100 + (c[2] - '0')*10+ c[3] - '0';
		stringstream sss(birth);
		sss >> a >> b >> c;
		d2 = (a[0] - '0') * 10 + a[1] - '0';
		m2 = (b[0] - '0') * 10 + b[1] - '0';
		y2 = (c[0] - '0') * 1000 + (c[1] - '0') * 100 + (c[2] - '0') * 10 + c[3] - '0';
		cout << "Case #" << ++t << ": ";
		int age = 0;
		if (y1 < y2 || (y1 == y2 && m1 < m2)||(y1==y2 && m1==m2 && d1<d2))cout << "Invalid birth date\n";
		else {
			if (d1>d2)
			{
				d2 = d2 + 30;
				m1 = m1 + 1;
			}
			if (m1>m2)
			{
				m2 = m2 + 12;
				y1 = y1 + 1;
			}
			age = y1 - y2;
			if (age > 130)cout << "Check birth date\n";
			else cout << age << "\n";
		}
	}
	return 0;
}
