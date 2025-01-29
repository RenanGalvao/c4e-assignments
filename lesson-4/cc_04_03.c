#include <stdio.h>
#include <stdlib.h>

main() {
	char input[100];
	float value, average;
	int n;
	value = average = 0.0;
	n = 0;

	/* while(fgets(input, 100, stdin) != NULL) { */
	while(scanf("%s", input) != EOF) {
		value += atof(input);	
		n++;
	}

	printf("The total is: %.1f\n", value);
	printf("The average is: %.1f\n", value/n);
}
