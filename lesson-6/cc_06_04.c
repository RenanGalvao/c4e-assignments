#include <stdio.h>

main() {
	int sumseries();

	printf("sumseries(0) returns %d\n", sumseries(0));
  	printf("sumseries(1) returns %d\n", sumseries(1));
  	printf("sumseries(5) returns %d\n", sumseries(5));
  	printf("sumseries(42) returns %d\n", sumseries(42));
  	printf("sumseries(-42) returns %d\n", sumseries(-42));
  	printf("sumseries(100) returns %d\n", sumseries(100));
  	printf("sumseries(101) returns %d\n", sumseries(101));
  	printf("sumseries(1000) returns %d\n", sumseries(1000));
}

int sumseries(n)
int n;
{
	if(n < 1) return 0;
	if(n > 100) return -1;

	return n <= 1 ? n : n + sumseries(n-1);
}
