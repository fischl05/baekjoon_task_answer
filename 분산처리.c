#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
	int n = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int a_buf = a % 10;
		for (int j = 1; j < b; j++) {
			a_buf *= a;
			a_buf %= 10;
		}
		if (a_buf == 0) printf("10\n");
		else printf("%d\n", a_buf);
	}

	return 0;
}