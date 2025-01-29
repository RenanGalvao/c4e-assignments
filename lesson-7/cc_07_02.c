#include <stdio.h>
#include <string.h>

main() {
	void removeNewLine();

	char line[100];
	char first[100];
	char second[100];
	char result[200];

	printf("Enter two strings\n");

	fgets(line, 100, stdin);
	removeNewLine(line);
	strcpy(first, line);

	fgets(line, 100, stdin);
	removeNewLine(line);
	strcpy(second, line);
	
	strcat(result, first);
	strcat(result, " & ");
	strcat(result, second);
	printf("%s\n", result);
}

void removeNewLine(line)
char *line;
{
	int newLinePos = strlen(line) - 1;
	while(line[newLinePos] == '\n')
		line[newLinePos--] = '\0';
}
