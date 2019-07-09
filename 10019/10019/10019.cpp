#include<cstdio>
using namespace std;

int ones(int n)
{
	int cnt = 0;
	while (n)
	{
		if (n % 2 == 1) cnt++;
		n /= 2;
	}
	return cnt;
}

int hex_to_dec(int n)
{
	int temp = 0, t = 1;
	while (n)
	{
		temp += (n % 10)*t;
		t *= 16;
		n /= 10;
	}
	return temp;
}

int main()
{
	int t, n, b1, b2;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		b1 = ones(n);
		n = hex_to_dec(n);
		b2 = ones(n);
		printf("%d %d\n", b1, b2);
	}
	return 0;
}