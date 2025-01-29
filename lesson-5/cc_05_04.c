#include <stdio.h>

main() {
	char line[256];
	char opcode;
	float value, display = 0.0;

	while (fgets(line, 256, stdin) != NULL){
		sscanf(line, "%c %f", &opcode, &value);
		
		if (opcode == 'S') 
			break;
		else if (opcode == '+')
			display += value;
		else if (opcode == '-')
			display -= value;
		else if (opcode == '*')
			display *= value;
		else if (opcode == '/')
			display /= value;
		else if (opcode == '=')
			display = value;

		printf("Display: %.2f\n", display);
	}
}
