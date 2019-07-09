#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
using namespace std;
string y;
int c,a[10],t;
bool p[10];
void sort(){
	int c,i,j,temp;
	c = y.length();
	for (i = 0; i < c; i++){
		for (j = i + 1; j < c; j++){
			if (y[j] < y[i]){
				temp = y[i];
				y[i] = y[j];
				y[j] = temp;
			}
		}
	}
}


void solve(string y,int position,int len){
	int i, j, k=0;
	for (i = 0; (i < len); i++){
		if ((p[i]) && ((i == 0) || (y[i] != y[i - 1]) || (p[i-1] == false))){
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
	int i, j, k, n, t,solution[10];
	cin >> n;
	getline(cin, y);
	for (i = 0; i < n; i++){
		getline(cin, y);
		sort();
		t = y.length();
		for (j = 0; j < 10; j++)p[j] = true;
		solve(y, 0, t);
		cout << "\n";
	}
	return 0;
}
