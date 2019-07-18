#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> v;

string add(string a, string b)
{
	string s;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int i = 0;
	int m, k = 0;
	while (a[i] && b[i])
	{
		m = a[i] - '0' + b[i] - '0' + k;
		k = m / 10;
		s += (m % 10 + '0');
		i++;
	}
	if (i == a.size())
	{
		while (i != b.size())
		{
			m = k + b[i] - '0';
			k = m / 10;
			s += m % 10 + '0';
			i++;
		}
		if (k) s += k + '0';
	}
	else if (i == b.size())
	{
		while (i != a.size())
		{
			m = k + a[i] - '0';
			k = m / 10;
			s += m % 10 + '0';
			i++;
		}
		if (k) s += k + '0';
	}
	reverse(s.begin(), s.end());
	return s;
}

void solve()
{
	v.push_back("0");
	v.push_back("2");
	v.push_back("5");
	v.push_back("13");
	string s;
	for (int i = 4; ; i++)
	{
		s = add(v[i - 1], v[i - 1]);
		s = add(v[i - 2], s);
		s = add(v[i - 3], s);
		v.push_back(s);
		if (v[i].size() > 1001) break;
	}
}

int main()
{
	solve();
	int n;
	int Size = v.size();
	while (cin >> n)
	{
		cout << v[n] << endl;
	}
	return 0;
}