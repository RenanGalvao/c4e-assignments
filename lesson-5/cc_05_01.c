#include <stdio.h>

main() {
	char t[1000];
	void expand();

	expand("Hello world\n", t);
	printf("%s\n", t);
}

/* expands \n and \t chars */
void expand(s, t)
char s[], t[];
{
	int i, j;
	for(i = j = 0; s[i]; i++){
		switch(s[i]) {
			case '\t':
				t[j++] = '\\';
				t[j++] = 't';
				break;
			case '\n':
				t[j++] = '\\';
				t[j++] = 'n';
				break;
			default:
				t[j++] = s[i];
				break;
		}
	}

	t[j] = '\0';
}
