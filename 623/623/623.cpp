int i, j, k,arr[3000];
int main() {
	i = 2999;				//start from end of array.
	numArr[2999] = 1;

	for (j = 2; j <= 1000; j++)
	{
		while (i > 0)
		{
			total = numArr[i] * l + rem;
			rem = 0;
			if (total > 9)
			{
				numArr[i] = total % 10;
				rem = total / 10;
			}
			else
				numArr[i] = total;
			i--;
		}
		rem = 0;
		total = 0;
		i = 2999;
	}
}