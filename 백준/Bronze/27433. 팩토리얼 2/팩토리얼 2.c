#include <stdio.h>
#include <stdint.h>

uint64_t fac(int a) {
	if (a == 0) return 1;
	else return a* fac(a - 1);
}

int main(void) {
	int a;

	scanf("%d", &a);

	printf("%lld", fac(a));

	return 0;
}