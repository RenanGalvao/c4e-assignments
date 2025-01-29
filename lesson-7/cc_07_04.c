#include <stdio.h>
#include <string.h>
#include <ctype.h>

main() {
	char s1[] = "    Hello    World    ";
	void py_lstrip();

	py_lstrip(s1);
	printf("-%s-\n", s1);
}

void py_lstrip(inp)
char inp[];
{
	char tmp[100];
	int firstc = 0;
	while(isblank(inp[firstc]) || isspace(inp[firstc]) || inp[firstc] == '\n')
		firstc++;

	int i, j;
	for(i = firstc, j = 0; isprint(inp[i]); i++, j++)
		tmp[j] = inp[i];
	tmp[++j] = '\0';

	strcpy(inp, tmp);
	
}
