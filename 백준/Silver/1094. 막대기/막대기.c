#include <stdio.h>

int main(void) {
	int n, out = 0;
	
	scanf("%d", &n);

	while (n) {
		if (n % 2 == 1) out++;
		n /= 2;
	}
	printf("%d\n", out);

	return 0;
}