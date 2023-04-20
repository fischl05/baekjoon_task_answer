#include <stdio.h>
#include <stdint.h>

int main(void) {
	 uint64_t n;

	scanf("%lld", &n);

	if (n == 1) {
		printf("4");
		return 0;
	}
	printf("%lld", (2 * n) + (2 * n));

	return 0;
}