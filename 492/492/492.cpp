#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define LL long long
#define MX 100000
#define MOD 1000000007

bool isVowel(char c)
{
	if (c == 65 || c == 69 || c == 73 || c == 79 || c == 85 || c == 97 || c == 101 || c == 105 || c == 111 || c == 117)
		return true;
	return false;
}


int main()
{
	char c, cons;

	while (c = getchar())

	{
		if (c == EOF)
			return 0;

		if (isVowel(c))
		{
			while (isalpha(c))
			{
				cout << c;
				c = getchar();
			}
			cout << "ay";
		}

		else if (isalpha(c))
		{
			cons = c;
			c = getchar();
			while (isalpha(c))
			{
				cout << c;
				c = getchar();
			}
			cout << cons << "ay";
		}

		cout << c;
	}
	return 0;
}