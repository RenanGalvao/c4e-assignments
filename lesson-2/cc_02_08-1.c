#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char line[1000];
	int val, maxval, minval;
	maxval = 0;
	minval = 0;

	while(gets(line) != NULL) {
		if(strcmp(line, "done") == 0) break;

		val = atoi(line);
		if (maxval == 0 || val > maxval) maxval = val;
		if (minval == 0 || val < minval) minval = val;
	}

	printf("Maximum: %d\n", maxval);
	printf("Minimum: %d\n", minval);
}
