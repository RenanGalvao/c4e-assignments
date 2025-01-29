#include <stdio.h>
#include <string.h>

int main() {
	char line[1000];
	void process();

	strcpy(line, "Hi there and welcome to LSB290");
	process(line);
	strcpy(line, "I love C");
	process(line);
}

void process(line)
	char line[];
{
	printf("\nString: %s\n", line);
	printf("Count=%lu\n", strlen(line));
	if(strlen(line) > 10)
		printf("The ninth character is: %c\n", line[9]);
	int i;
	for(i = 0; i < strlen(line) - 1; i++) {
		if(line[i] == ' ')
			line[i] = '-';
	}
	printf("String: %s\n", line);
}
