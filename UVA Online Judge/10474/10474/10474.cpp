#include<cstdio>
#include<iostream>
#define max 10010
using namespace std;
int c = 0;
int main()
{
	int number, query, query_number, i, array[max], k;
	while (cin >> number >> query && (number || query))
	{
		int location = 0;
		for (i = 1; i <= number; i++)
		{
			scanf("%d", &array[i]);
			for (int j = i - 1; j >= 1; j--)
			{
				if (array[j] <= array[i])
				{
					location = j + 1; break;
				}
				else location = j;
			}
			if (location != 0) /*insertion sort*/
			{
				int temp = array[i];
				for (int j = i - 1; j >= location; j--)
				{
					array[j + 1] = array[j];
				}
				array[location] = temp;
			}
		}
		printf("CASE# %d:\n", ++c);
		while (query--)
		{
			cin >> query_number;
			int beg, end, mid;
			beg = 1; end = number; mid = (beg + end) / 2; location = 0;
			if (array[mid] == query_number)location = mid;
			while (beg <= end)
			{
				if (array[mid]<query_number)
				{

					beg = mid + 1; if (beg>end)break;
					mid = int(beg + end) / 2;
					if (array[mid] == query_number)
					{
						location = mid;
					}
				}

				else
				{
					end = mid - 1; if (beg>end)break;
					mid = (beg + end) / 2;
					if (array[mid] == query_number)location = mid;
				}
			}
			if (location) printf("%d found at %d\n", query_number, location);
			else printf("%d not found\n", query_number);
		}
	}
	return 0;
}
