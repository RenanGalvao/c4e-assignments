#include <stdio.h>
#include <string.h>

/* uniq simple implementation from stdin */
main() {
	char line[1000];
	char last[1000];

	while(gets(line) != NULL) {
		if(strcmp(last, line) != 0)
			printf("%s\n", line);
		strcpy(last, line);
	}
}
