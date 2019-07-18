#include <cstdio>
#define MAXN 100000+10

int a[2 * MAXN], x;
int n, t, flag = 0;

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		flag++;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			a[n + i] = a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			a[i] -= x;
			a[n + i] -= x;
		}

		a[0] = 0;
		for (int i = 1; i <= 2 * n; i++)
		{
			a[i] += a[i - 1];
		}
		int s = 0, mi = 1, cn = 0;
		for (int i = 0; i <= 2 * n; i++)
		{
			if (a[i] >= mi)
			{
				if (++cn>n)  break;
			}
			else
			{
				mi = a[i];
				s = i;
				cn = 1;
				if (i >= n)    break;
			}
		}
		printf("Case %d: ", flag);
		if (cn>n)    printf("Possible from station %d\n", s + 1);
		else printf("Not possible\n");
	}
	return 0;
}