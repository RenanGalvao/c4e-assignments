#include <ctype.h>
#include <stdio.h>

int main() {
  char memory[256], token[256];
  int position = 0, value = 0;

  while (scanf("%s", token) == 1) {
#ifdef DEBUG
    printf("%s\n", token);
#endif

    int i;
    char lastc;

    for (i = 0; token[i] != '\0'; i++) {
      if (isdigit(token[i])) {
        if (isdigit(lastc))
          value *= 10;
        value += token[i] - '0';
      } else if (isgraph(token[i])) {
        if (token[i] == '>')
          position++;
        else if (token[i] == '<')
          position--;
      }      
	  lastc = token[i];
    }
	
	if(value)
		memory[position] = value;
	value = 0;
  }
  printf("Memory:\n%s\n", memory);
}
