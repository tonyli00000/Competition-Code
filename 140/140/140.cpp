#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int a[26],neighbors[29][3];
bool p[29];
void sort(string y){
	int c, i, j, temp, x, k;
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
	int i, j, k,b,x[26];
	char letters;
	string input,y;
	bool flag;
	while (getline(cin, input)){
		y = "";
		int len = input.length();
		b =0;
		flag = false;
		j = 0;
		for (i = 0; i < 26; i++)x[i] = 0;
		while (b < len){
			if (input[b] == ':'){
				flag = true;
				i = input[b - 1];
			}
			else{
				if ((input[b] != ';')&&(flag==true)){
					neighbors[i-'A'][j] = input[b];
					j++;
					x[i - 'A'] = 1;
					y.insert(0, 1,char(input[b]));
				}
			}
			if (input[b] == ';'){
				j = 0;
				flag = false;
			}
			b++;
		}
		sort(y);
		solve(y, 0, len);
	}

	
	return 0;
}
