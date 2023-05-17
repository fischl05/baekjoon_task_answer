#include <stdio.h>

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int h, w, n;
		scanf("%d %d %d", &h, &w, &n);
		n -= 1;
		printf("%d%02d\n", n % h + 1, n / h + 1);
	}

	return 0;
}