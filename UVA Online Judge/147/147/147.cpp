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

using namespace std;


//long long ct;
//void a(int step, vector<int>solution,int sum,int tot,int k) {
//	if (sum > tot)return;
//	if (sum == tot) {
//		if (mp.find(solution) == mp.end()) {
//			mp[solution] = true;
//			ct++;
//		}
//		return;
//	}
//	int i;
//	for (i = 10; i >=k; i--) {
//		solution[i]++;
//		if(sum+money[i]<=tot)a(step + 1, solution, sum + money[i],tot,k);
//	}
//
//}
long long ways[10000];
void count()
{
	int coin[] = { 2000, 1000, 400, 200, 100 , 40, 20, 10, 4, 2 ,1 };
	ways[0] = 1;
	for (int i = 0; i < 11; i++)
		for (int j = coin[i]; j < 7500; j++)
			ways[j] += ways[j - coin[i]];
}
int main()
{
	double t;
	int p;
	int i, j,n;
	count();
	while (cin >> t && t != 0) {
		n = t * 20;
		cout << fixed << setprecision(2) << "  " << t;
		int f = 10;
		for (i = 0; i < 20; i++) {
			if (ways[int(t * 20)]<f)break;
			f = f * 10;
		}
		for (j = 0; j < 17 - i - 6; j++) {
			cout << " ";
		}
		cout << ways[int(t * 20)] << "\n";
		/*k = 10;
		mp.clear();
		p = t * 100;
		ct = 0;
		vector<int>solution;
		solution.resize(11, 0);
		for (i = 0; i < 11; i++) {
			if (money[i] < p) {
				k = i;
				break;
			}
		}
		a(0, solution, 0, p,k-1);
		cout << fixed << setprecision(2) << t<<"    ";
		cout << ct << "\n";*/
	}
	return 0;
}
