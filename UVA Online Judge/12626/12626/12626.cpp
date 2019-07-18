#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int min(int x, int y){
	if (x<y)
		return x;
	return y;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	while (n--){
		int M = 0, A = 0, R = 0, G = 0, I = 0, T = 0, i = 0, z = 0;
		char str[600];
		scanf("%s", str);
		z = strlen(str);
		for (i = 0; i<z; i++){
			if (str[i] == 'M')
				M++;
			else if (str[i] == 'A')
				A++;
			else if (str[i] == 'R')
				R++;
			else if (str[i] == 'G')
				G++;
			else if (str[i] == 'I')
				I++;
			else if (str[i] == 'T')
				T++;
		}
		int answer = min(min(min(min(min(M, A / 3), R / 2), G), I), T);
		printf("%d\n", answer);
	}
	return 0;
}