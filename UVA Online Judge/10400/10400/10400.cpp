#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int in[102],result;
bool flag = true;
int operation(int a, int b, int c){
	if (c == 0)return a+b;
	if (c == 1)return a - b;
	if (c == 2)return a*b;
	if (c == 3)return a / b;
}
void solve(int step, int p,int ans[100],int sum){
	int i, j, k;
	if (flag == true){
		if ((step == p - 1)){
			if (flag == true){
				for (i = 0; i < p; i++){
					cout << in[i];
					if (i < p - 1){
						if (ans[i] == 0)cout << '+';
						if (ans[i] == 1)cout << '-';
						if (ans[i] == 2)cout << '*';
						if (ans[i] == 3)cout << '/';
					}
				}
				cout << "=" << sum << "\n";
				flag = false;
			}
			return;
		}
		result = in[0];
		for (i = 0; i < step; i++){
			result = operation(result, in[i + 1], ans[i]);
		}
		for (i = 0; i < 4; i++){
			ans[step] = i;
			if ((i == 3) && (result%in[step + 1] != 0));
			else{
				if (-32000 <= (operation(result, in[step + 1], i) <= 32000)){
					if ((step == p - 2) && (operation(result, in[step + 1], i) != sum));
					else{
						result = operation(result, in[step + 1], i);
						solve(step + 1, p, ans, sum);
					}
				}
			}
		}
	}
}
int main()
{
	int n, p,i,j,k,solution[100];
	cin >> n;
	for (i = 0; i < n; i++){
		cin >> p;
		for (j = 0; j < p; j++)cin >> in[j];
		cin >> k;
		result = in[0];
		flag = true;
		solve(0, p,solution,k);
		if (flag == true)cout << "NO EXPRESSION\n";
	}
	return 0;
}
