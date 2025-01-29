#include <stdio.h>

main(){
	int bump();
	printf("bump() returns %d\n", bump());
	printf("bump() returns %d\n", bump());
  	printf("bump() returns %d\n", bump());
  	printf("bump() returns %d\n", bump());
  	printf("bump() returns %d\n", bump());
}

int nbump = 0;

