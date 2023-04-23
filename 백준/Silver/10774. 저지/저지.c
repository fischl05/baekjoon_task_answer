#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int j, a;
	int out = 0;

	scanf("%d %d", &j, &a);
	
	char* size_check = (char*)calloc(sizeof(char), j + 1);

	for (int i = 0; i < j; i++) {
		char size[2];
		scanf("%s", size);
		size_check[i] = size[0];
	}

	for (int i = 0; i < a; i++) {
		char size[2];
		int num;

		scanf("%s %d", size, &num);
		if (size_check[num - 1] <= size[0]) {
			size_check[num - 1] = 'Z';
			out++;
		}
	}
	printf("%d", out);

	free(size_check);
	return 0;
}