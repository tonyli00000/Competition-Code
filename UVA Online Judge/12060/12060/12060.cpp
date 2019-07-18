#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
#define MAXP 30000
int i, j, k,prime[10000];
bool p[MAXP];
float average = 0.0;
int main()
{
	int n;
	long long i2, j,top;
		top = 1;
		prime[0] = 2;
		p[0] = false;
		p[1] = false;
		p[2] = true;
		for (i = 3; i < MAXP; i += 2) p[i] = true;
		for (i = 3; i < MAXP; i += 2)
		{
			if (p[i]) {
				prime[top] = i;
				top++;
				i2 = i + i;
				for (j = i * 3; j < MAXP; j += i2) p[j] = false;
			}
		}
		int t = 0;
	while (cin >> n && n != 0) {
		long long sum = 0;
		t++;
		cout << "Case " << t << ":\n";
		for (i = 0; i < n; i++) {
			int a = 0;
			cin >> a;
			sum += a;
		}
		average = sum*1.0 / n;
		long long num = sum, den = n;
		k = 0;
		while (prime[k] <= sqrt(abs(num)) || prime[k] <= den) {
			if (abs(num)%prime[k] == 0 && den%prime[k] == 0) {
				num = num / prime[k];
				den = den / prime[k];
			}
			else k++;
		}
		int intpart = 0;
		if (abs(num) >= den) {
			intpart = num / den;
			int p = abs(intpart);
			num = num%den;
			int fact = 1, d = 0;
			for (i = 0; i < 100; i++) {
				fact = fact * 10;
				if (abs(p) > fact) {
					cout << " ";
					d++;
				}
				else break;
			}
			if (den == 1) {
				if (intpart < 0)cout << "- ";
				cout << abs(intpart) << "\n";
			}
			else {
				if (num < 0)cout << "  ";
				if (den > 99)cout << "   ";
				else if (den > 9)cout << "  ";
				else cout << " ";
				cout << abs(num) << "\n";
				if (intpart < 0)cout << "- ";
				cout << abs(intpart);
				if (den > 99)cout << "---";
				else if (den > 9)cout << "--";
				else cout << "-";
				cout << "\n";
				if (den > 99)cout << "  ";
				else if (den > 9)cout << " ";
				else cout<<" ";
				if (num < 0)cout << "  ";
				for (j = 0; j < d; j++)cout << " ";
				cout << den << "\n";
			}
		}
		else {
			if (den > 99)cout << "  ";
			else if (den > 9)cout << " ";
			else cout << "";
			if(num<0)cout<<"  ";
			cout << abs(num) << "\n";
			if (num < 0) {
				cout << "- ";
			}
			if (den > 99)cout << "---";
			else if (den > 9)cout << "--";
			else cout << "-";
			cout << "\n";
			if (den > 99)cout << "  ";
			else if (den > 9)cout << " ";
			else cout<<"";
			if (num < 0)cout << "  ";
			cout << den << "\n";
		}
	}
	return 0;
}