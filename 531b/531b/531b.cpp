#include<iostream>
#include<string>
#include<stdio.h>
#define sz 105
using namespace std;

string ss1[sz], ss2[sz];
char dim[sz][sz];
int cal[sz][sz];
bool chk;
void print(int l1, int l2);
int main()
{

	// freopen("in.txt","r",stdin);
	string mmrs;
	char ar[50];
	int i, j, k, l1, l2;
	while (scanf("%s", ar) != EOF)
	{
		mmrs = ar;
		l1 = 0;
		ss1[l1++] = mmrs;
		while (cin >> mmrs && mmrs != "#")
		{
			ss1[l1++] = mmrs;
		}
		l2 = 0;
		while (cin >> mmrs && mmrs != "#")
		{
			ss2[l2++] = mmrs;
		}
		//        for(i=0;i<l1;i++)
		//            cout<<ss1[i]<<"..";
		//        for(i=0;i<l2;i++)
		//            cout<<ss2[i]<<"..";
		for (i = 0; i <= l1; i++)
			cal[0][i] = 0;
		for (j = 0; j <= l2; j++)
			cal[j][0] = 0;
		for (i = 1; i <= l1; i++)
		{
			for (j = 1; j <= l2; j++)
			{
				if (ss1[i - 1] == ss2[j - 1])
				{
					dim[i][j] = 'D';
					cal[i][j] = cal[i - 1][j - 1] + 1;
				}
				else if (cal[i - 1][j]>cal[i][j - 1])
				{
					dim[i][j] = 'U';
					cal[i][j] = cal[i - 1][j];
				}
				else
				{
					dim[i][j] = 'L';
					cal[i][j] = cal[i][j - 1];
				}
			}

		}
		chk = true;
		print(l1, l2);
		printf("\n");

	}
	return 0;
}

void print(int i, int j)
{

	if (i == 0 || j == 0)
		return;
	if (dim[i][j] == 'D')
	{
		print(i - 1, j - 1);
		if (chk == false)
			printf(" ");
		cout << ss1[i - 1];
		chk = false;
	}
	else if (dim[i][j] == 'U')
		print(i - 1, j);
	else  print(i, j - 1);
}