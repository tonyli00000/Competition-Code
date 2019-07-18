#include <cstdio>
#include <cctype>

int main()
{
	bool mark_ups = true;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\\') {
			if ((c = getchar()) == EOF) {
				putchar('\\');
				return 0;
			}
			else if (c == '*')
				mark_ups = !mark_ups;
			else if (mark_ups) {
				switch (c) {
				case 'b': case 'i':
					break;
				case 's':
					do
						c = getchar();
					while (isdigit(c) || c == '.');
					if (c == EOF)
						return 0;
					else
						ungetc(c, stdin);
					break;
				default:
					putchar(c);
					break;
				}
			}
			else {
				ungetc(c, stdin);
				putchar('\\');
			}
		}
		else
			putchar(c);
	}
	return 0;
}