#include <stdio.h>

main() {
	int htoi();

	printf("0xf %d\n", htoi("f"));
	printf("0xf0 %d\n", htoi("f0"));
	printf("0x12fab %d\n", htoi("12fab"));
}

/* convert hex string to integer */
int htoi(s)
char s[];
{
	int i, n, base, comp;
	i = n = 0;
	base = 16;
	comp = 10; /* a - a = 0 in ASCII, compesate since a = 10 in HEX */

	while(s[i] != '\0') {
		if(s[i] >= '0' && s[i] <= '9')
			n = base * n + s[i] - '0';
		else if(s[i] >= 'A' && s[i] <= 'F')
			n = base * n + s[i] - 'A' + comp;
		else if(s[i] >= 'a' && s[i] <= 'f')
			n = base * n + s[i] - 'a' + comp;
		i++;
	}

	return n;
}

