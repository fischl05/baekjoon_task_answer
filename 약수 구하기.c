#include <stdio.h>

int main(void) {
	int n, k;
	int cnt = 0;

	scanf("%d %d", &n, &k);

	int i = 0;
	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			cnt++;
			if (cnt >= k) {
				printf("%d", i);
				return 0;
			}
		}
	}
	printf("0");

	return 0;
}