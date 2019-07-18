//#include <iostream>
//#include <string>
//#include <sstream>
//#include <iomanip> 
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <vector>
//#include <map>
//#include <set>
//#include <functional>
//
//using namespace std;
//
//set<set<int>> init[7];
//set<int> l;
//int arr[15];
//void st(int step,int r,int p[15],int k) {
//	if (step != 0) {
//		//if (r - k > 6)return;
//		p[step-1]=k;
//	}
//	if (step == r) {
//		int i;
//		for (i = 0; i<r; i++) {
//			if (i != 0)cout << " ";
//			cout << arr[p[i]];
//		}
//		cout << "\n";
//		return;
//	}
//	int i;
//	for (i = 0; i < r; i++) {
//		if(r+step-i>6 && i>k)st(step + 1, r, p,i);
//	}
//}
//int main()
//{
//	int i;
//	set<set<int>>::iterator it;
//	while (cin >> i && i != 0) {
//		int j;
//		for (j = 0; j < i; j++) {
//			cin >> arr[j];
//		}
//		int p[15];
//		st(0, i, p, -1);
//	}
//	return 0;
//}

#include <cstdio>
using namespace std;

int main() {
	int k, S[12], count = 0;
	while (scanf("%d", &k), k) {
		if (count++)
			printf("\n");
		for (int i = 0; i < k; i++)
			scanf("%d", &S[i]);

		for (int a = 0; a < k - 5; a++)
			for (int b = a + 1; b < k - 4; b++)
				for (int c = b + 1; c < k - 3; c++)
					for (int d = c + 1; d < k - 2; d++)
						for (int e = d + 1; e < k - 1; e++)
							for (int f = e + 1; f < k; f++)
								printf("%d %d %d %d %d %d\n", S[a], S[b], S[c],
									S[d], S[e], S[f]);
	}

	return 0;
}