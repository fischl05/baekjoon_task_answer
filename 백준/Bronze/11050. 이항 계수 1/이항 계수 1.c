#include <stdio.h>

int fac[11];

int factorial(int n) {
	if (n == 0) return 1;
	else {
		if (fac[n] > 0) return fac[n];
		fac[n] = n * factorial(n - 1);
		return fac[n];
	}
}

int main(void) {
	int n, k;

	scanf("%d %d", &n, &k);
	
	printf("%d", factorial(n) / (factorial(k) * factorial(n - k)));

	return 0;
}