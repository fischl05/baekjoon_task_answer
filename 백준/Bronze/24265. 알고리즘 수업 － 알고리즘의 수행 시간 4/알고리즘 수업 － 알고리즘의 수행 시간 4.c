#include <stdio.h>
#include <stdint.h>

int main(void) {
	uint64_t n, cnt = 0;
	
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			cnt++;
	}

	printf("%lld\n2", cnt);

	return 0;
}