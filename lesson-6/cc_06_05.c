#include <stdio.h>
#define MEMORY_SIZE 256

main() {
	char line[MEMORY_SIZE];
	char memory[MEMORY_SIZE];
	char opcode;
	int count, address, value;

	while(fgets(line, MEMORY_SIZE, stdin) != NULL) {
		#ifdef DEBUG
			printf("\nLine: %s\n", line);
		#endif
		if(line[0] == 'X') break;
		if(line[0] == '*') {
			printf("%s", line);
			continue;
		}

		count = sscanf(line, "%d %c %d", &address, &opcode, &value);
		if(count != 3) continue;
		#ifdef DEBUG
		printf("address: %d opcode: %c value %d\n", address, opcode, value);
		#endif

		if(opcode == '=')
			memory[address] = value;
		if(opcode == '+')
			memory[address] += value;
		if(opcode == '-')
			memory[address] -= value;
	}

	printf("Memory:\n%s\n", memory);
}
