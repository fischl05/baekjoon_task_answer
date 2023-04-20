#include <stdio.h>

int main(void) {
	int n, i, sum = 0;

	scanf("%d", &n);

	for (i = 1; sum < n; i++) {
		sum += i;
	}
	i--;

	if (i % 2 == 0)
		printf("%d/%d", i - (sum - n), 1 + (sum - n));
	else
		printf("%d/%d", 1 + (sum - n), i - (sum - n));

	return 0;
}