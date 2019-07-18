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
	int n;
	cin >> n;
	while (n--){
		string x, y,result="",q="",w="";
		cin >> x >> y;
		int carry = 0,i;
		for (i = 0; i < min(x.length(), y.length()); i++){
			q += x[i];
			w += y[i];
		}
		for (i = q.length()-1; i >=0; i--){
			int a = q[i] - '0', b = w[i] - '0';
			if (a + b+carry > 9){
				carry = 1;
				result += ((a + b + carry) % 10 + '0');
			}
			else {
				result += (a + b + carry+'0');
				carry = 0;
			}
		}
		if (x.length() > q.length()){
			for (i=x.length()-q.length(); i >0; i--){
				int a = x[i] - '0';
				if (a + carry > 9){
					carry = 1;
					result += (((a + carry) % 10)+'0');
				}
				else {
					result += (a+ carry + '0');
					carry = 0;
				}
			}
		}
		if (y.length() > q.length()){
			for (i=y.length() - q.length(); i >= 0; i--){
				int a = y[i] - '0';
				if (a + carry > 9){
					carry = 1;
					result += (((a + carry) % 10) + '0');
				}
				else {
					result += (a + carry + '0');
					carry = 0;
				}
			}
		}
		cout << result << "\n";
	}
	return 0;
}
