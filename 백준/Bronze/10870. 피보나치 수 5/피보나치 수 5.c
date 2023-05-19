#include <stdio.h>

int num[20];

int fibo(int n) {
	if (n < 2) return n;
	else {
		if (num[n] > 0) return num[n];
		num[n] = fibo(n - 1) + fibo(n - 2);
		return num[n];
	}
}

int main(void) {
	int n;

	scanf("%d", &n);

	printf("%d", fibo(n));

	return 0;
}