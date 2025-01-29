#include <stdio.h>

main() {
	int lower();

	printf("M is %c\n", lower('M'));
	printf("G is %c\n", lower('G'));
	printf("X is %c\n", lower('X'));
}

int lower(c)
int c;
{
	return c >= 'A' && c <= 'Z' ? (c - 'A') + 'a' : c;
}
