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
#include <cstdio>
#include <string.h>

using namespace std;
int main()
{
	int max, min, guess;
	bool valid;
	string input;
	max = 11;
	min = 0;
	valid = true;
	while (cin>>guess && guess)
	{
		cin >> input;
		if (strcmp(input,  == 0)
		{
			if (guess <= min)
				valid = false;
			if (guess < max)
				max = guess;
		}
		else if (strcmp(input, "low") == 0)
		{
			if (guess >= max)
				valid = false;
			if (guess > min)
				min = guess;
		}
		else
		{
			if (guess > min && guess < max && valid)
			{
				printf("Stan may be honest\n");
			}
			else
			{
				printf("Stan is dishonest\n");
			}
			valid = true;
			min = 0;
			max = 11;
		}
	}
}

