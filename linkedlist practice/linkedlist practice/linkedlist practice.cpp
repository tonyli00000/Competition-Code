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

vector<string> node = { "breakfast","brush","homework","school","shower","phone","clothes" };
vector<string> nex = { "school","shower","","homework","clothes","brush","breakfast" };
string getnext(int ind) {
	return nex[ind];
}
bool hasnext(int ind) {
	if (nex[ind] == "")return false;
	else return true;
}
int main()
{
	int i = 0;
	while(true){
		if (!hasnext(i)) {
			nex.erase(nex.begin() + i, nex.begin() + i + 1);
			string l = node[i];
			node.erase(node.begin() + i, node.begin() + i + 1);
			for (int j = 0; j < nex.size(); i++) {
				if (nex[j] == l)nex[j] = "";
				break;
			}
			break;
		}
		i++;
	}
	return 0;
}
