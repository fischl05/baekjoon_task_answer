#include <stdio.h>

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j > i; j--)
			printf(" ");
		for (int j = 0; j < i * 2 + 1 ; j++)
			printf("*");
		printf("\n");
	}
	
	return 0;
}