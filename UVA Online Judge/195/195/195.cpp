#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
using namespace std;
string y;
int c, a[100], t;
bool p[100];
void sort(){
	int c, i, j, temp,x,k;
	c = y.length();
	for (i = 0; i < c; i++){
		for (j = i + 1; j < c; j++){
			if ((y[j] >= 'A') && (y[j] <= 'Z'))x = (y[j] - 'A') * 2;
			else x = (y[j] - 'a') * 2 + 1;
			if ((y[i] >= 'A') && (y[i] <= 'Z'))k = (y[i] - 'A') * 2;
			else k = (y[i] - 'a') * 2 + 1;
			if (x < k){
				temp = y[i];
				y[i] = y[j];
				y[j] = temp;
			}
		}
	}
}


void solve(string y, int position, int len){
	int i, j, k = 0;
	for (i = 0; (i < len); i++){
		if ((p[i]) && ((i == 0) || (y[i] != y[i - 1]) || (p[i - 1] == false))){
			a[position] = y[i];
			p[i] = false;
			solve(y, position + 1, len);
			p[i] = true;
		}
	}
	if (position == len){
		for (i = 0; i < len; i++){
			cout << char(a[i]);
		}
		cout << "\n";
	}
}
int main()
{
	int i, j, k, n, t, solution[10];
	cin >> n;
	getline(cin, y);
	for (i = 0; i < n; i++){
		getline(cin, y);
		sort();
		t = y.length();
		for (j = 0; j < t; j++)p[j] = true;
		solve(y, 0, t);
	}
	return 0;
}
