#include <stdio.h>

long long int num[120];

long long int fibo(int n) {
	if (n <= 3) return 1;
	else {
		if (num[n] > 0) return num[n];
		num[n] = fibo(n - 1) + fibo(n - 3);
		return num[n];
	}
}

int main(void) {
	int n;

	scanf("%d", &n);

	printf("%lld", fibo(n));

	return 0;
}