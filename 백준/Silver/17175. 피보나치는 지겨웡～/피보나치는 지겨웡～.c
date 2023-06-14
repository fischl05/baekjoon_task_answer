#include <stdio.h>

int num[51] = { 1, 1 };

int main(void) {
	int n, i = 2;

	scanf("%d", &n);

	while (i < 51) {
		num[i] = (num[i - 1] + num[i - 2] + 1) % 1000000007;
		i++;
	}
	
	printf("%d", num[n]);

	return 0;
}