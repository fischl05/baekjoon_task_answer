#include <stdio.h>

int main(void) {
	int n, sum = 0;

	while (scanf("%d", &n) != EOF) {
		sum += n;
	}
	printf("%d\n", sum);

	return 0;
}