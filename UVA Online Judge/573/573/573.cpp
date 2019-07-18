#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int i, j, k;
int main()
{
	int a, b, c, d;
	while (cin >> a >> b >> c >> d && a != 0) {
		int day = 1;
		float height = 0.0;
		float dist = b*1.0;
		bool flag = true;
		while (height < a) {
			if(dist>0)height += dist;
			if (height > a) break;
			dist = dist-b*1.0*d*1.0/100;
			height = height - c;
			if (height < 0) {
				flag = false;
				break;
			}
			day++;
		}
		if (flag == false)cout << "failure on day ";
		else cout << "success on day ";
		cout << day << "\n";
	}
	return 0;
}
