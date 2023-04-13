#include <stdio.h>
#include <string.h>

int res(char a) {
	switch (a) {
	case '0':
		return 4;
		break;
	case '1':
		return 2;
		break;
	case '\0':
		return 0;
		break;
	default:
		return 3;
		break;
	}
}

int main(void) {
	char input[5];
	int out = 2;

	memset(input, 0, 5);
	scanf("%s", input);

	while (strcmp(input, "0")) {
		for (int i = 0; i < 4; i++)
			out += res(input[i]);
		out += strlen(input) - 1;
		
		printf("%d\n", out);
		out = 2;
		memset(input, 0, 5);
		scanf("%s", input);
	}

	return 0;
}