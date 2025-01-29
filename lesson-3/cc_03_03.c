#include <stdio.h>

main() {
	int c, last;
	while((c = getchar()) != EOF){
		if(last == ' ' && c == ' ')
			continue;
		putchar(c);
		last = c;
	}
}
