#include <stdio.h>

main() {
	int bump();
	void start();

  	printf("bump() returns %d\n", bump());
  	printf("bump() returns %d\n", bump());
  	printf("bump() returns %d\n", bump());
  	start(42);
  	printf("bump() returns %d\n", bump());
  	printf("bump() returns %d\n", bump());
}
