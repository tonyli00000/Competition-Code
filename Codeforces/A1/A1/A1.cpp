#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#define INF 10000000
#define MOD 1000000007
using namespace std;

std::string goal_number="311389257981435198347439158713456781436512834713874123874683219841733141326463164716143851983462461362461326134889135891389574671324631264631252813724613249";
int num_guess_calls = 0;
bool found_number = false;

int guess(const std::string& number) {
	if (number.length() == 0) {
		std::cerr << "Cannot guess a zero-length number." << std::endl;
		exit(1);
	}
	for (char digit : number) {
		if (isprint(digit) && (digit < '0' || digit > '9')) {
			std::cout << number << std::endl;
			std::cerr << "Input must be a non-negative integer." << std::endl;
			exit(1);
		}
	}
	++num_guess_calls;

	size_t NA = number.size();
	size_t NB = goal_number.size();

	std::vector<std::vector<int>> M(NA + 1, std::vector<int>(NB + 1));

	for (size_t a = 0; a <= NA; ++a)
		M[a][0] = a;

	for (size_t b = 0; b <= NB; ++b)
		M[0][b] = b;

	for (size_t a = 1; a <= NA; ++a) {
		for (size_t b = 1; b <= NB; ++b) {
			size_t x = M[a - 1][b] + 1;
			size_t y = M[a][b - 1] + 1;
			size_t z = M[a - 1][b - 1] + (number[a - 1] == goal_number[b - 1] ? 0 : 1);
			int yz = (y < z ? y : z);
			M[a][b] = (x < yz ? x : yz);
		}
	}
	int result = M[number.size()][goal_number.size()];
		std::cout << "guess: " << number << " / distance: " << result << std::endl;
	
	if (result == 0) {
		found_number = true;
		std::cout << (float)num_guess_calls / goal_number.length() << std::endl;
 		exit(1);
	}
	return result;
}

void find_number() {
	int curr = 75, index = 0;
	string s = "0";

	int dist = guess(s);
	int add = dist - 1;
	for (int i = 0; i < add; i++) {
		s += "0";
	}
	string original = s;
	vector<bool>found(s.length(), false);
	set<char>a;
	for (char i = '1'; i <= '9'; i++) {
		a.insert(i);
	}
	int ct = 0;
	int l = 0, r = s.length();
	while (!a.empty()) {
		int best = 0;
		char ind = *a.begin();
		original = s;
		for (auto it : a) {
			for (int i = 0; i < s.length(); i++) {
				if (!found[i])s[i] = it;
			}
			int x = guess(s);
			if (dist - x > best) {
				best = dist - x;
				ind = it;
				if (x*1.0 / dist > 1.0/a.size()*dist*2)break;
			}
		}
		s = original;
		for (int i = 0; i < s.length(); i++) {
			if (found[i])continue;
			s[i] = ind;
			int d = guess(s);
			if (d < dist) {
				dist = d;
				found[i] = 1;
			}
		}
		a.erase(ind);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	find_number();
	return 0;
}