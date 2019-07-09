using namespace std;
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define LLU long long unsigned int

int main()
{
	int height, M = 0, t1, t2, t3, i = 0, N = 0;
	vector<int> L;
	vector<int> H;
	vector<int> R;
	vector<int> ans;
	int coord[10001] = { 0 };
	bool first = true;
	while (cin >> t1 >> t2 >> t3)
	{
		L.push_back(t1);
		H.push_back(t2);
		R.push_back(t3);
		N++;
	}
	for (i = 0; i<N; i++)
	{
		t1 = H[i];
		for (int j = L[i]; j<R[i]; j++)
		{
			coord[j] = max(coord[j], t1);
		}
	}
	i = 0;
	first = true;
	for (int i = 0; i<10001; i++)
	{
		if (i || coord[i])
		{
			if (first)
			{
				cout << i << " " << coord[i];
				first = false;
			}
			else
				cout << " " << i << " " << coord[i];
		}
		t3 = coord[i];
		while (coord[i + 1] == t3)
		{
			i++;
			if (i == 10001) break;
		}
	}
	cout << endl;
	return 0;
}