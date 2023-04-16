#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, out = 0;
	
	scanf("%d", &n);
	
	char* input = (char*)calloc(sizeof(char), n + 1);
	int* holder = (int*)calloc(sizeof(int), n + 2);
	scanf("%s", input);

	for (int i = 0; i < n - 1; i++) {
		if (input[i] == 'S') {
			if (holder[i] == 0) {
				holder[i] = 1;
				out++;
			}
			else if (holder[i] != 0 && holder[i + 1] == 0) {
				holder[i + 1] = 1;
				out++;
			}
		}
		else if (input[i] == 'L') {
			if (input[i - 1] == 'L' && holder[i + 1] == 0) {
				holder[i + 1] = 1;
				out++;
				if (input[i + 1] == 'L') i++;
			}
			else if (input[i + 1] == 'L' && holder[i] == 0) {
				holder[i] = 1;
				out++;
			}
		}
	}
	printf("%d", out + 1);

	return 0;
}