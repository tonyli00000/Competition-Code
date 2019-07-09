/*
PROG:stall4
ID:tonyli21
LANG:C++11
*/
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
#pragma warning(disable:4996)
int n, m, tot, flow, cnt, aug, v, p, q, i, j, u;
int map[505][505], queue[20005], pre[505];
int main()
{
	freopen("stall4.in", "r", stdin);
	freopen("stall4.out", "w", stdout);
	memset(map, 0, sizeof(map));
	scanf("%ld%ld", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%ld", &p);
		for (j = 1; j <= p; j++)
		{
			scanf("%ld", &q);
			map[i][q + n] = 1;
		}
	}
	flow = 0; cnt = n + m + 1;
	for (i = 1; i <= n; i++) map[0][i] = 1;
	for (i = n + 1; i <= m + n; i++) map[i][cnt] = 1;
	memset(queue, 0, sizeof(queue));
	while (1)
	{
		memset(pre, -1, sizeof(pre));
		queue[1] = 0;
		for (p = 1, q = 1; p <= q; p++)
		{
			u = queue[p];
			for (v = 1; v <= cnt; v++)
				if (pre[v]<0 && map[u][v]>0)
				{
					pre[v] = u;
					queue[++q] = v;
				}
			if (pre[cnt] >= 0)break;
		}
		if (pre[cnt]<0)break;
		aug = 2000000000;
		for (v = cnt; v != 0; v = pre[v])aug = min(aug, map[pre[v]][v]);
		for (v = cnt; v != 0; v = pre[v])
		{
			map[pre[v]][v] -= aug;
			map[v][pre[v]] += aug;
		}
		flow += aug;
	}
	printf("%ld\n", flow);
	return 0;
}