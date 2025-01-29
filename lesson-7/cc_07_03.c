#include <stdio.h>
#include <string.h>

main() {
	char s1[] = "    Hello    World    ";
	void py_rstrip();

	py_rstrip(s1);
	printf("-%s-\n", s1);
}

void py_rstrip(inp)
char inp[];
{
	int lastc = strlen(inp) - 1;
	while(inp[lastc] == ' ')
		inp[lastc--] = '\0';
}
