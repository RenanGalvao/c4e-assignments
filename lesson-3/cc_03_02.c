#include <stdio.h>

/* Print Celsius-Fahrenheit table from 0 to 100 */

main() {
	int lower, upper, step;
	float fahr, celsius;

	lower = 0;
	upper = 100;
	step = 20;
	celsius = lower;

	printf("CELSIUS\tFAHR\n---------------\n");
	while(celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32;
		printf("%4.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
