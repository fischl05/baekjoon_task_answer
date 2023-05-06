#include <stdio.h>
#include <stdint.h>

uint64_t res[100];

uint64_t fibo(int a) {
	if (a < 2) return a;
	else {
		if (res[a] > 0) return res[a];
		res[a] = fibo(a - 1) + fibo(a - 2);
		return res[a];
	}
}

int main(void) {
	int n;

	scanf("%d", &n);

	//if (n == 1)
	//	printf("0");
	//else
		printf("%lld", fibo(n));

	return 0;
}