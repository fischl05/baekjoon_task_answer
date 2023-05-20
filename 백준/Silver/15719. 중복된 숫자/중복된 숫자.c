#include <stdio.h>

int main(void) {
	long long int n;
	long long int sum = 0, value;

	scanf("%lld", &n);

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		sum += a;
	}

	value = (n - 1) * n / 2;
	printf("%lld", sum - value);

	return 0;
}