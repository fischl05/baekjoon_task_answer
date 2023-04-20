#include <stdio.h>
#include <stdint.h>

int main(void) {
	/*int a;
	scanf("%d", &a);
	printf("1\n0");*/

	uint64_t n, cnt = 0;

	scanf("%lld", &n);
	
	printf("%lld\n3", (n * (n - 1) * (n - 2)) / 6);

	return 0;
}