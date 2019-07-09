#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int min(int x, int y) {
	if (x < y)return x;
	else return y;
}
int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int find(int x) {
	while (x / 10 > 0) {
		if (x / 100 == 0)x = x % 10 + x / 10;
		else x = x % 10 + (x % 100) / 10 + x / 100;
	}
	return x;
}
int main()
{
	string line,l;
	int i, j, k;
	while (getline(cin,line)) {
		int sum = 0,a=0,b=0;
		for (i = 0; i < line.length(); i++) {
			if (('a' <= line[i] && line[i] <= 'z') || ('A' <= line[i] && line[i] <= 'Z')) {
				if (line[i] >= 'a')sum += line[i] - 'a'+1;
				else sum += line[i] - 'A'+1;
			}
		}
		if (sum / 10 == 0)a = sum;
		a = find(sum);
		getline(cin, line);
		int sum_2 = 0;
		for (i = 0; i < line.length(); i++) {
			if (('a' <= line[i] && line[i] <= 'z') || ('A' <= line[i] && line[i] <= 'Z')) {
				if (line[i] >= 'a')sum_2 += line[i] - 'a' + 1;
				else sum_2 += line[i] - 'A' + 1;
			}
		}
		b = find(sum_2);
		double p = min(a, b)*1.0 / max(a, b)*1.0*100.0;
		cout << fixed << setprecision(2) << p << " %\n";
	}
	return 0;
}
