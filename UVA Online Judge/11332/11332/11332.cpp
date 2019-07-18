#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
string input;
int len, i, j, k,sum,l;
string reverse(string s){
	string result = "";
	for (int i = 0; i < s.length(); i++){
		result = s[i] + result;
	}
	return result;
}
int main()
{
	int s=10;
	while ((getline(cin, input))){
		len = input.length();
		if ((len == 1) && (input[0] == '0'))break;
		s = 10;
		sum = 10;
		while (s>9){
			sum = 0;
			s = 0;
			len = input.length();
			for (i = 0; i < len; i++){
				sum += (input[i] - '0');
			}
			l = log10(sum);
			input = "";
			int a = 10;
			s = sum;
			for (i = l; i >= 0; i--){
				input += ((sum%a)+'0');
				sum = sum / 10;
			}
			reverse(input);
		}
		cout << s << "\n";
	}
	return 0;
}
