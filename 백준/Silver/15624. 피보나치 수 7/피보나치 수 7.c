#include <stdio.h>

int num[1000000] = { 0, 1 };

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
		num[i] = (num[i - 1] + num[i - 2]) % 1000000007;
	printf("%lld", num[n]);

	return 0;
}