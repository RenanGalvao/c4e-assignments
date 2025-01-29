#include <stdio.h>

/* Print Fahrenheit-Celsius table from 0 to 300 */

main() {
	int lower, upper, step;
	float fahr, celsius;

	lower = 0;
	upper = 300;
	step = 40;
	fahr = lower;

	printf("FAHR\tCELSIUS\n---------------\n");
	while(fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%4.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
