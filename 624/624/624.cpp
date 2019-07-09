#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

bool flag = true;
void print_all_subset(int *A, int len, int *B, int len2, int index,int p)
{
	if (index >= len)
	{
		int sum = 0;
		for (int i = 0; i < len2; ++i)
		{
			sum += B[i];
		}
		if (sum == p && flag) {
			flag = false;
			for (int i = 0; i < len2; ++i)
			{
				cout << B[i] << " ";
			}
			cout << "sum:" << p << "\n";
			return;
		}
		else return;
	}
	print_all_subset(A, len, B, len2, index + 1,p);

	B[len2] = A[index];
	print_all_subset(A, len, B, len2 + 1, index + 1,p);
}
int main()
{
	int i, j, k,x,y,A[22],B[22];
	while (cin >> x >> y) {
		for (i = 0; i < y; i++)cin >> A[i];
		B[y] = 0;
		flag = true;
		while (flag) {
			print_all_subset(A, y, B, 0, 0, x);
			x--;
		}
	}
	return 0;
}
