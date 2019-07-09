#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

struct item {
	int a, b, c;
	int sum;
};

#define pii pair<item,int>
#define MAX 30001

item q[4];
item best;
int bestI, bestJ, bestR, bestSum = MAX, bestRes;

int ok(item tmp) {
	double a, b, c;
	if (q[0].a == 0) {
		if (tmp.a != 0) return -1;
		a = -2;
	}
	else {
		a = tmp.a / q[0].a;
	}
	if (q[0].b == 0) {
		if (tmp.b != 0) return -1;
		b = -2;
	}
	else {
		b = tmp.b / q[0].b;
	}
	if (q[0].c == 0) {
		if (tmp.c != 0) return -1;
		c = -2;
	}
	else {
		c = tmp.c / q[0].c;
	}
	if ((a == -2 || tmp.a / a == q[0].a) && (b == -2 || tmp.b / b == q[0].b) && (c == -2 || tmp.c / c == q[0].c) && (a == b || a == -2 || b == -2) && (b == c || b == -2 || c == -2)) return max(a, max(b, c));
	return -1;
}


int main() {
	for (int i = 0; i < 4; ++i) {
		cin >> q[i].a >> q[i].b >> q[i].c;
		q[i].sum = q[i].a + q[i].b + q[i].c;
	}
	item sum;
	for (int i = 0; i <= 100; ++i) {
		sum.a = q[1].a*i;
		sum.b = q[1].b*i;
		sum.c = q[1].c*i;
		for (int j = 0; j <= 100; ++j) {
			sum.a += q[2].a*j;
			sum.b += q[2].b*j;
			sum.c += q[2].c*j;
			for (int r = 0; r <= 100; ++r) {
				sum.a += q[3].a*r;
				sum.b += q[3].b*r;
				sum.c += q[3].c*r;
				int res = ok(sum);
				if (res != -1 && i + j + r<bestSum) {
					if (res == -2) res = 0;
					bestI = i;
					bestJ = j;
					bestR = r;
					bestSum = i + j + r;
					bestRes = res;
				}
				sum.a -= q[3].a*r;
				sum.b -= q[3].b*r;
				sum.c -= q[3].c*r;
			}
			sum.a -= q[2].a*j;
			sum.b -= q[2].b*j;
			sum.c -= q[2].c*j;
		}
	}
	if (bestSum == MAX) {
		cout << "NONE\n";
	}
	else {
		cout << bestI << " " << bestJ << " " << bestR << " " << bestRes <<"\n";
	}
	return 0;
}