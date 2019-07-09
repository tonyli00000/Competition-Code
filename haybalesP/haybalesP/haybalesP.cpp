#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;
 
struct Segmenttree
{
	long long l, r, min, sum, id;
}t[1000000];

vector<int>ct(200002);
void update(int k, long long x){
	t[k].id += x;
	t[k].min += x;
	t[k].sum += (t[k].r - t[k].l + 1)*x;
}
void pushup(int k)
{
	t[k].min = min(t[k << 1].min, t[k << 1 | 1].min);
	t[k].sum = t[k << 1].sum + t[k << 1 | 1].sum;
}
void pushdown(int k){
	if (!t[k].id) return;
	update(k << 1, t[k].id); update(k << 1 | 1, t[k].id);
	t[k].id = 0;
}
void build(int k, int l, int r){
	t[k].l = l; t[k].r = r; t[k].id = 0;
	if (l == r){ t[k].min = t[k].sum = ct[l]; return; }
	int mid = (l + r) >> 1;
	build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
void add(int k, int l, int r, long long x){
	if (t[k].l == l&&t[k].r == r){ update(k, x); return; }
	int mid = (t[k].l + t[k].r) >> 1;
	pushdown(k);
	if (r <= mid) add(k << 1, l, r, x);
	else if (l > mid) add(k << 1 | 1, l, r, x);
	else{ add(k << 1, l, mid, x); add(k << 1 | 1, mid + 1, r, x); }
	pushup(k);
}
long long query(int k, int l, int r){
	if (t[k].l == l&&t[k].r == r) return t[k].min;
	int mid = (t[k].l + t[k].r) >> 1;
	pushdown(k);
	if (r <= mid) return query(k << 1, l, r);
	else if (l>mid) return query(k << 1 | 1, l, r);
	else return min(query(k << 1, l, mid), query(k << 1 | 1, mid + 1, r));
}
long long getsum(int k, int l, int r){
	if (t[k].l == l&&t[k].r == r) return t[k].sum;
	int mid = (t[k].l + t[k].r) >> 1;
	pushdown(k);
	if (r <= mid) return getsum(k << 1, l, r);
	else if (l>mid) return getsum(k << 1 | 1, l, r);
	else return getsum(k << 1, l, mid) + getsum(k << 1 | 1, mid + 1, r);
}

int main()
{
	/*freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);*/
	int n, m;
	char op;
	cin >> n >> m;
	for(int i = 1; i <= n;i++)
		cin>>ct[i];
	build(1, 1, n);
	for (int i = 1; i <= m;i++){
		cin>>op;
		while (op<'A' || op>'Z') cin>>op;
		int l,r,x;
		cin >> l >> r;
		if (op == 'M') cout<< query(1, l, r)<<"\n";
		else if (op == 'S') cout<< getsum(1, l, r)<<"\n";
		else{
			cin >> x;
		    add(1, l, r, x);
		}
	}	
	return 0;
}